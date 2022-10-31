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

const int maxn = 2e5 + 5;
const int inf = 1e9;
vector<int> g[maxn];
map<pair<int,int>, int> dp;
vector<int> order;

void dfs(int v, int p = -1) {
    order.pb(v);
    vector<int> ch;
    for (int to : g[v]) {
        if (p != to) {
            dfs(to, v);
            ch.pb(min(dp[mp(to, v)] + 1, inf));
        }
    }
    if (ch.empty()) {
        dp[mp(v, p)] = 0;
    } else {
        if (p != -1) {
            bool good = true;
            for (int i = 1; i < ch.size(); i++) {
                good &= ch[0] == ch[i];
            }
            if (!good || ch[0] == inf) {
                dp[mp(v, p)] = inf;
            } else {
                dp[mp(v, p)] = ch[0];
            }
        } else {
            set<int> was(ch.begin(), ch.end());
            if (was.count(inf) || was.size() > 2) {
                dp[mp(v, p)] = inf;
            } else if (was.size() == 2) {
                int x = *was.begin();
                int y = *(++was.begin());
                int s = x + y;
                while (s % 2 == 0) {
                    s /= 2;
                }
                dp[mp(v, p)] = s;
            } else {
                int s = *was.begin();
                while (s % 2 == 0) {
                    s /= 2;
                }
                dp[mp(v, p)] = *was.begin();
            }
        }
    }
}

int main() {
    srand(time(0));

retry:
#ifdef LOCAL
    //gen();
    //return 0;
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("identification.in", "r", stdin);
    //freopen("identification.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1);
    for (int v : order) {
        map<int, int> cnt;
        for (int to : g[v]) {
            cnt[min(inf, dp[mp(to, v)] + 1)]++;
        }

        {
            if (cnt.count(inf) || cnt.size() > 2) {
                dp[mp(v, -1)] = inf;
            } else if (cnt.size() == 2) {
                int x = cnt.begin()->fst;
                int y = (++cnt.begin())->fst;
                int s = x + y;
                while (s % 2 == 0) {
                    s /= 2;
                }
                dp[mp(v, -1)] = s;
            } else {
                int s = cnt.begin()->fst;
                while (s % 2 == 0) {
                    s /= 2;
                }
                dp[mp(v, -1)] = s;
            }
        }

        for (int to : g[v]) {
            int val = min(inf, dp[mp(to, v)] + 1);
            cnt[val]--;
            if (!cnt[val]) {
                cnt.erase(val);
            }

            if (cnt.count(inf) || cnt.size() > 1) {
                dp[mp(v, to)] = inf;
            } else if (cnt.size() == 1) {
                dp[mp(v, to)] = cnt.begin()->fst;
            } else {
                dp[mp(v, to)] = 0;
            }

            cnt[val]++;
        }
    }


    int ans = inf;
    for (int i = 1; i <= n; i++) {
        chmin(ans, dp[mp(i, -1)]);
    }

    if (ans == inf) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }


    return 0;
}