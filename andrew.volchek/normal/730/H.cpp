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

const ld pi = acos(-1.0l);

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


//-----------------------------------------------------------------------------

const int maxn = 105;
int need[maxn];

int main() {
    srand(time(NULL));

    retry:
#ifdef LOCAL
    // gen();

    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> sz;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        x--;
        need[x] = 1;
        sz.insert(a[x].size());
    }
    if (sz.size() != 1) {
        cout << "No" << endl;
        return 0;
    }

    string ans;
    vector<int> now(n);
    iota(now.begin(), now.end(), 0);


    vector<char> p;
    for (char c = 'a'; c <= 'z'; c++) {
        p.pb(c);
    }
    for (char c = '0'; c <= '9'; c++) {
        p.pb(c);
    }
    p.pb('.');
    //cout << p << endl;
    while (ans.size() < *sz.begin()) {
        bool any = false;
        for (char c : p) {
            vector<int> nw;
            int cnt = 0;
            for (int x : now) {
                if (a[x].size() < ans.size() + 1) {

                } else if (a[x][ans.size()] == c) {
                    nw.pb(x);
                    cnt += need[x];
                }
            }
            if (cnt == m) {
                any = true;
                ans += c;
                now = nw;
                break;
            }
        }


        if (!any) {
            ans += '?';
            vector<int> nw;
            for (int x : now) {
                if (a[x].size() >= ans.size()) {
                    nw.pb(x);
                }
            }
            now = nw;
        }
    }

    //cout << ans << endl;

    bool good = true;
    for (int i = 0; i < n; i++) {
        bool m = a[i].size() == ans.size();
        for (int j = 0; j < ans.size() && m; j++) {
            m &= a[i][j] == ans[j] || ans[j] == '?';
        }
        if (m != need[i]) {
            //cout << m << " " << need[i] << " " << i << endl;
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    cout << ans << endl;


    return 0;
}