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
const int maxn = 30;
vector<int> g[maxn];
int used[maxn];

int mt[maxn];

bool dfs(int v) {
    for (int to : g[v]) {
        if (mt[to] == -1) {
            mt[to] = v;
            return true;
        }
    }
    used[v] = 1;
    for (int to : g[v]) {
        if (!used[mt[to]] && dfs(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}



vector<char> solve(vector<pair<char, char>> a) {
    for (int i = 0; i < maxn; i++) {
        g[i].clear();
    }

    map<char, int> cnt;
    for (auto x : a) {
        cnt[x.fst]++;
    }

    fill(mt, mt + maxn, -1);


    for (int i = 0; i < a.size(); i++) {
        if (cnt[a[i].fst] > 1) {
            if (mt[a[i].snd - 'A'] != -1) {
                cout << "NO" << endl;
                exit(0);
            } else {
                mt[a[i].snd - 'A'] = i;
            }
        } else {
            g[i].pb(a[i].fst - 'A');
            g[i].pb(a[i].snd - 'A');
        }
    }

    for (int i = 0; i < a.size(); i++) {
        if (cnt[a[i].fst] > 1) {
            continue;
        }
        fill(used, used + maxn, 0);
        if (!dfs(i)) {
            cout << "NO" << endl;
            exit(0);
        }
    }
    vector<char> res(a.size());
    for (int i = 0; i < maxn; i++) {
        if (mt[i] != -1) {
            res[mt[i]] = 'A' + i;
        }
    }
    return res;
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


    int n;
    cin >> n;
    vector<pair<string, pair<char, char>>> a(n);
    map<string, vector<int>> b;
    for (int i = 0; i < n; i++) {
        string s, t;
        cin >> s >> t;
        a[i].fst = s.substr(0, 2);
        a[i].snd = mp(s[2], t[0]);
        b[a[i].fst].pb(i);
    }

    vector<string> ans(n);
    for (auto kv : b) {
        vector<pair<char, char>> c;
        for (int x : kv.snd) {
            c.pb(a[x].snd);
        }
        auto r = solve(c);
        for (int i = 0; i < kv.snd.size(); i++) {
            int x = kv.snd[i];
            ans[x] = a[x].fst + r[i];
        }
    }

    cout << "YES" << endl;
    for (auto s : ans) {
        cout << s << endl;
    }



    return 0;
}