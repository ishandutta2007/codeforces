#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>
#include <limits>
#include <tuple>
#include <complex>
#include <numeric>
#include <future>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = acos(-1.0);

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
bool chmin(T &x, T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

template<typename T>
bool chmax(T &x, T y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
    s << "[";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "]";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
    s << "{";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "}";
    return s;
}

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//--------------------------------------------------------------------------
const int maxn = 5005;
vector<int> g[maxn];
string val[maxn];
int nval[maxn];

int used[maxn];
vector<int> order;
void dfs(int v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
    order.pb(v);
}

int main(int argc, char* argv[]) {

    srand(134);

#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //gen();
    //return 0;

#else
    //freopen("identification.in", "r", stdin);
    //freopen("identification.out", "w", stdout);
#endif


    int n, m;
    cin >> n >> m;

    map<string, int> cc;
    auto get = [&](string s) {
        if (s == "?") {
            return -1;
        }
        if (!cc.count(s)) {
            int sz = cc.size();
            cc[s] = sz;
        }
        return cc.at(s);
    };

    cin.ignore();
    vector<pair<int, pair<int,int>>> a(n, mp(-1, mp(-1, -1)));
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        bool has = false;
        for (char c : s) {
            has |= isupper(c);
        }
        stringstream ss(s);
        //cout << s << endl;
        if (!has) {
            string name, _, val;
            ss >> name >> _ >> val;
            ::val[get(name)] = val;
        } else {
            string name, _, x, op, y;
            ss >> name >> _ >> x >> op >> y;
            if (op == "AND") {
                a[get(name)] = (mp(0, mp(get(x), get(y))));
            } else if (op == "OR") {
                a[get(name)] = (mp(1, mp(get(x), get(y))));
            } else {
                a[get(name)] = (mp(2, mp(get(x), get(y))));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i].fst == -1) {
            continue;
        }
        if (a[i].snd.fst != -1) {
            g[i].pb(a[i].snd.fst);
        }
        if (a[i].snd.snd != -1) {
            g[i].pb(a[i].snd.snd);
        }
    }

    assert(cc.size() == n);
    for (int i = 0; i < cc.size(); i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    string mi, ma;
    for (int i = 0; i < m; i++) {
        int cnt[2] = { 0, 0 };
        for (int j = 0; j < 2; j++) {
            for (int v : order) {
                if (a[v].fst == -1) {
                    nval[v] = val[v][i] - '0';
                } else {
                    auto foo = [&](int x) {
                        if (x == -1) {
                            return j;
                        } else {
                            return nval[x];
                        }
                    };
                    if (a[v].fst == 0) {
                        nval[v] = foo(a[v].snd.fst) & foo(a[v].snd.snd);
                    } else if (a[v].fst == 1) {
                        nval[v] = foo(a[v].snd.fst) | foo(a[v].snd.snd);
                    } else {
                        nval[v] = foo(a[v].snd.fst) ^ foo(a[v].snd.snd);
                    }
                }
            }
            for (int h = 0; h < n; h++) {
                cnt[j] += nval[h];
                //cerr << i << " " << nval[h] << endl;
            }
        }
        //cout << cnt[0] << " " << cnt[1] << endl;
        if (cnt[0] == cnt[1]) {
            mi += '0';
            ma += '0';
        } else if (cnt[0] > cnt[1]) {
            mi += '1';
            ma += '0';
        } else {
            mi += '0';
            ma += '1';
        }
    }

    cout << mi << endl;
    cout << ma << endl;



    return 0;
}