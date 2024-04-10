#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const int INF = 1.01e9;
typedef vector<int> vi;



int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, m;
    scanf("%d%d", &n, &m); 
    vector<vector<int>> e(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
    vector<int> use(n);
    vector<int> st;
    vector<pair<int,int>> seg;

    function<void(int, int)> dfs = [&](int v, int p) {
        st.pb(v);
        use[v] = 1;
        for (auto u: e[v]) {
            if (u == p) continue;
            if (!use[u]) {
                dfs(u, v);
            }
            else if (use[u] == 1) {
                vector<int> who;
                //db2(v, u);
                //dbv(st);
                for (int j = st.size() - 1; st[j] != u; j--) {
                    who.pb(st[j]);
                }
                who.pb(u);
                assert(who.size() % 2 == 1);
                int mn = INF;
                int mx = -INF;
                for (auto x: who) {
                    mn = min(mn, x);
                    mx = max(mx, x);
                }
                seg.pb({mn, mx});
            }
        }
        use[v] = 2;
        st.pop_back();
    };

    for (int i = 0; i < n; i++) {
        if (!use[i]) {
            dfs(i, -1);
        }
    }
    //for (auto x: seg) {
        //db2(x.F, x.S);
    //}

    vector<int> h(n);
 
    sort(all(seg), [](pair<int,int> A, pair<int,int> B) {
            return A.S < B.S;
            });

    int up = -1;
    int cur = 0;
    vector<int> profi(n);
    for (int i = 0; i < n; i++) {
        for (; cur < sz(seg) && seg[cur].S <= i; cur++) {
            up = max(up, seg[cur].F);
        }
        h[i] = i - up;
        profi[i] = up;
    }
    vector<ll> pref;
    pref.pb(0);
    for (int i = 0; i < n; i++) {
        pref.pb(pref.back() + h[i]);
    }

    auto getC = [](ll f) {
        return f * (f + 1) / 2;
    };
    //dbv(h);
    //dbv(profi);

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d%d", &l, &r); l--; r--;
        int pos = lower_bound(all(profi), l) - profi.begin();
        ll answer = 0;
        if (pos > r) {
            answer = getC(r - l + 1);
        }
        else {
            //db3(l, pos, r);
            //db(getC(pos - l));
            answer = getC(pos - l) + pref[r + 1] - pref[pos]; 
        }
        cout << answer << "\n";
    }





        
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}