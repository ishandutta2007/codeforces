#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

pll dp[2011][2011];
char c[2011][2011];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, m;
    cin >> n >> m;
    ll sx, sy;
    cin >> sx >> sy;
    ll x, y;
    cin >> x >> y;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        cin >> c[i][j];
        dp[i][j] = m_p(1e18, 1e18);
    }
    set <pair <pll, pll> > st;
    dp[sx][sy] = m_p(0, 0);

    st.insert( m_p(dp[sx][sy], m_p(sx, sy)) );

    while(!st.empty()){
        pair <pll, pll> xe = *st.begin();
        st.erase(st.begin());
        ll i = xe.se.fi, j = xe.se.se;
        pll xx = xe.fi;
        //cout << i << " " << j << " " << xx.fi << " " << xx.se << "\n";
        if(i < n && (dp[i + 1][j].fi > xx.fi || dp[i + 1][j].fi == xx.fi && dp[i + 1][j].se > xx.se) && c[i + 1][j] != '*'){
            st.erase({dp[i + 1][j], {i + 1, j}});
            dp[i + 1][j] = xx;
            st.insert({dp[i + 1][j], {i + 1, j}});
        }
        if(i > 1 && (dp[i - 1][j].fi > xx.fi || dp[i - 1][j].fi == xx.fi && dp[i - 1][j].se > xx.se) && c[i - 1][j] != '*'){
            st.erase({dp[i - 1][j], {i - 1, j}});
            dp[i - 1][j] = xx;
            st.insert({dp[i - 1][j], {i - 1, j}});
        }
        xx.se++;
        if(j < m && (dp[i][j + 1].fi > xx.fi || dp[i][j + 1].fi == xx.fi && dp[i][j + 1].se > xx.se) && c[i][j + 1] != '*'){
            st.erase({dp[i][j + 1], {i, j + 1}});
            dp[i][j + 1] = xx;
            st.insert({dp[i][j + 1], {i, j + 1}});
        }
        xx.se--;
        xx.fi++;
        if(j > 1 && (dp[i][j - 1].fi > xx.fi || dp[i][j - 1].fi == xx.fi && dp[i][j - 1].se > xx.se) && c[i][j - 1] != '*'){
            st.erase({dp[i][j - 1], {i, j - 1}});
            dp[i][j - 1] = xx;
            st.insert({dp[i][j - 1], {i, j - 1}});
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
                if(dp[i][j].fi <= x && dp[i][j].se <= y)ans++;
        }
    }
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}