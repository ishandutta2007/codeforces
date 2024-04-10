#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e6;;
const int M = pw(16);
const long long mod = 998244353;
const int N = 1e5 + 100;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector <pll> v[N];

ll dp[N], dp1[N];

const ll MAX = (1e18);
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

    void insertLine(ll k, ll b) {
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

    ll findMin(ll x) {
        x = -x;
        auto best = *lower_bound({-x, -MAX});
        return best.k * x - best.b;
    }
};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;    
    t = 1;

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        // cin >> t;
    #endif    
    
    ll n, m, k;
    cin >> n >> m >> k;

    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].p_b({b, c});
        v[b].p_b({a, c});        
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = dp1[i] = 1e18;
    }

    dp[1] = 0;

    set <pll> st;

    for (int i = 1; i <= n; i++) {
        st.insert({dp[i], i});
    }

    while (!st.empty()) {
        pll xe = *st.begin();
        st.erase(st.begin());            
        for (auto to : v[xe.se]) {
            if (dp[to.fi] > xe.fi + to.se) {
                st.erase({dp[to.fi], to.fi});
                dp[to.fi] = to.se + xe.fi;
                st.insert({dp[to.fi], to.fi});                    
            }
        }
    }    

    for (int step = 1; step <= k; step++) {
        CHT a;
        for (ll i = 1; i <= n; i++) {
            a.insertLine(-2 * i, dp[i] + sqr(i));               
        }        

        for (ll i = 1; i <= n; i++) {
            dp1[i] = min(dp[i], sqr(i) + a.findMin(i));         
        }

        set <pll> st;

        for (int i = 1; i <= n; i++) {
            st.insert({dp1[i], i});
        }

        while (!st.empty()) {
            pll xe = *st.begin();
            st.erase(st.begin());            
            for (auto to : v[xe.se]) {
                if (dp1[to.fi] > xe.fi + to.se) {
                    st.erase({dp1[to.fi], to.fi});
                    dp1[to.fi] = to.se + xe.fi;
                    st.insert({dp1[to.fi], to.fi});                    
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            dp[i] = dp1[i];
            dp1[i] = 1e18;            
        }        
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }

    cout << "\n";


    return 0;
}