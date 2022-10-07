#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const ll INF = 1.01e11;

struct pt {
    ll x, y;
    pt() {}
    pt(ll xx, ll yy): x(xx), y(yy) {}
    pt operator + (pt A) {
        return pt(x + A.x, y + A.y);
    }
    pt operator - (pt A) {
        return pt(x - A.x, y - A.y);
    }
    pt operator * (ll k) {
        return pt(x * k, y * k);
    }
    pt operator / (ll k) {
        assert(x % k == 0 && y % k == 0);
        return pt(x / k, y / k);
    }
    ll operator * (pt A) {
        return x * A.y - y * A.x;
    }
    ll operator % (pt A) {
        return x * A.x + y * A.y;
    }
    bool operator == (pt A) {
        return x == A.x && y == A.y;
    }
    bool operator != (pt A) {
        return x != A.x && y != A.y;
    }
    pt rotate() {
        return pt(-y, x);
    }
    ll len2() {
        return x * x + y * y;
    }
    dbl len() {
        return sqrt(x * x + y * y);
    }
    void read() {
        scanf("%lld%lld", &x, &y);
    }
};



int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }

    vector<vector<pt>> who(n * 4);
    vector<int> done(n * 4);


    function<void(int,int,int,int,pt)> add = [&](int v, int tl, int tr, int pos, pt A) {
        who[v].pb(A);
        assert(done[v] == 0);
        if (tl + 1 == tr) {
            return;
        }
        if (pos < (tl + tr) / 2)
            add(v * 2 + 1, tl, (tl + tr) / 2, pos, A);
        else
            add(v * 2 + 2, (tl + tr) / 2, tr, pos, A);
    };

    auto checkAng = [](pt v, pt u) {
        dbl res = v.x * 1.0 * u.y - v.y * 1.0 * u.x;
        if (abs(res) > 1e18) {
            return res > 0;
        }
        return v * u >= 0;
    };


    function<ll(int,int,int,int,int,pt)> get = [&](int v, int tl, int tr, int l, int r, pt u) {
        if (r <= tl || tr <= l) return -INF;
        if (l <= tl && tr <= r) {
            if (!done[v]) {
                sort(all(who[v]), [](pt A, pt B) {
                    return A.y < B.y || (A.y == B.y && A.x < B.x);
                });
                vector<pt> st;
                for (auto A: who[v]) {
                    //for (;st.size() >= 2 && (st.back() - st[st.size() - 2]) * (A - st.back()) >= 0; st.pop_back());
                    for (;st.size() >= 2 && checkAng((st.back() - st[st.size() - 2]), (A - st.back())); st.pop_back());
                    st.pb(A);
                }
                who[v] = st;
                done[v] = 1;
            }

            int L = 0;
            int R = who[v].size() - 1;
            while (R - L > 1) {
                int mid = (L + R) / 2;
                if ((who[v][mid + 1] - who[v][mid]) % u > 0) {
                    L = mid;
                }
                else {
                    R = mid;
                }
            }

            return max(who[v][L] % u, who[v][R] % u);
        }
        return max(get(v * 2 + 1, tl, (tl + tr) / 2, l, r, u), get(v * 2 + 2, (tl + tr) / 2, tr, l, r, u));
    };



    vector<ll> dp(n);
    vector<int> tin(n);
    vector<int> tout(n);
    int tmr = 0;
    function<void(int, int )> dfs = [&](int v, int p) {
        tin[v] = tmr++;
        for (auto u: e[v]) {
            if (u == p) continue;
            dfs(u, v);
        }
        tout[v] = tmr;
        if (v != 0 && e[v].size() == 1) {
            dp[v] = 0;
        }
        else {
            dp[v] = -get(0, 0, n, tin[v] + 1, tout[v], pt(1, a[v]) * -1);
        }
        add(0, 0, n, tin[v], pt(dp[v], b[v]));

    };


    dfs(0, -1);


    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;





    return 0;
}