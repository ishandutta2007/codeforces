 #include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e5;
const int M = pw(16);
const long long mod = 998244353;
const int N = 2e5;
const int inf = 1e9;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll dp[1001][1001];

void u(ll &a, ll b){
    a = min(a, b);
}

const ll MAX = (1e15);
const ll Q = -(1LL << 62);

struct Line {
    ll k, b;
    mutable function<const Line *()> succ;

    bool operator<(const Line &to) const {
        if (to.b != -MAX)
            return k < to.k;
        const Line *cur = succ();
        if (!cur)
            return false;
        return b - cur->b < (ld)(cur->k - k) * to.k;
    }
};

struct CHT : public multiset<Line> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end())
                return false;
            return y->k == z->k && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end())
            return y->k == x->k && y->b <= x->b;
        return (ld)(x->b - y->b) * (z->k - y->k) >= (ld)(y->b - z->b) * (y->k - x->k);
    }

    void insert_line(ll k, ll b) {
        auto cur = insert({-k, -b});
        cur->succ = [=] { return next(cur) == end() ? 0 : &*next(cur); };
        if (bad(cur)) {
            erase(cur);
            return;
        }
        while (next(cur) != end() && bad(next(cur)))
            erase(next(cur));
        while (cur != begin() && bad(prev(cur)))
            erase(prev(cur));
    }

    ll eval(ll x) {
        x = -x;
        auto best = *lower_bound({-x, -MAX});
        return best.k * x - best.b;
    }
};

CHT st[1001];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l, k;
    cin >> n >> l >> k;

    vector <int> d(n);
    vector <int> a(n);

    for(auto &i : d) cin >> i;
    d.p_b(l);
    for(auto &i : a) cin >> i;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++) dp[i][j] = inf;
    }

    dp[0][1] = a[0] * l;

    st[1].insert_line(a[0], dp[0][1]);

    ll ans = 1e18;

    for(int i = 1; i < n; i++){
        for(int j = i; j > 0; j--){
            int val = st[j].eval(-(l - d[i])) + (l - d[i]) * a[i];            
            u(dp[i][j + 1], val);
            st[j + 1].insert_line(a[i], dp[i][j + 1]);
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 1; j <= i + 1; j++) if(j + k >= n) u(ans, dp[i][j]);

    cout << ans << "\n";
    
    return 0;
}
/*
dp[i][j] - ((l - d[np]) * (a[i] - a[np]))
dp[i][j] - (l - d[np]) * a[i] + a[np] * (l - d[np])
*/