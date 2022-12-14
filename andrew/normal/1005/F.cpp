#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector <pll> v[MAXN];

vector <ll> mb_pr[MAXN];

ll dp[MAXN];

string mb;

vector <string> ans;

ll FUFEL, k;

void dfs(ll x){
    if(x == FUFEL){
        ans.p_b(mb);
        if(sz(ans) == k){
            cout << sz(ans) << "\n";
            for(auto i : ans)cout << i << "\n";
            exit(0);
        }
    }else{
        for(auto j : mb_pr[x]){
            mb[j - 1] = '1';
            dfs(x + 1);
            mb[j - 1] = '0';
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, m;
    cin >> n >> m >> k;

    FUFEL = n + 1;

    fill(dp + 1, dp + n + 1, inf);

    for(int i = 1; i <= m; i++){
        ll a, b;
        cin >> a >> b;
        v[a].p_b({b, i});
        v[b].p_b({a, i});
    }

    dp[1] = 0;

    set <pll> st;

    st.insert({0, 1});

    while(!st.empty()){
        pll xe = *st.begin();
        st.erase(st.begin());
        for(auto to : v[xe.se])if(xe.fi + 1 < dp[to.fi]){
            st.erase({dp[to.fi], to.fi});
            dp[to.fi] = xe.fi + 1;
            st.insert({dp[to.fi], to.fi});
        }
    }

    for(int i = 1; i <= n; i++){
        for(auto j : v[i])if(dp[j.fi] + 1 == dp[i])mb_pr[i].p_b(j.se);
    }

    mb.resize(m);
    fill(all(mb), '0');

    dfs(2);

    cout << sz(ans) << "\n";
    for(auto i : ans)cout << i << "\n";

    return 0;
}