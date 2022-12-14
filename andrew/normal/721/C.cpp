#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ll int
#define ple pair <ll, pll>

using namespace std;
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

vector <pll> v[MAXN];
vector <ll> va;
string s1,s2,s3;
set <ple> st;
set <ll> s;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
ll dp[5001][5001];
ll p[5001][5001];
void way(ll val){
    ll x = n;
    while(val){
        va.p_b(x);
        x = p[x][val];
        val--;
    }
    reverse(all(va));
    ll nn = va.size();
    cout << nn << endl;
    for(i = 0; i < nn; i++)cout << va[i] << " ";
    cout << endl;
    exit(0);
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m >> k;
    while(m--){
        cin >> a1 >> b1 >> c1;
        v[a1].p_b(m_p(b1,c1));
    }
    for(i = 1; i <= n; i++)
        for(j = 0; j <= n; j++)dp[i][j] = 2 * 1e9;
    dp[1][1] = 0;
    st.insert(m_p(0, m_p(1,1)));
    set <ple> :: iterator it;
    while(!st.empty()){
        it = st.begin();
        ll time = it -> fi, val = (*it).se.fi + 1, x = (*it).se.se;
        ll i, nn = v[x].size();
        st.erase(it);
        for(i = 0; i < nn; i++){
            ll to = v[x][i].fi, time1 = v[x][i].se + time;
            if(dp[to][val] > time1 && time1 <= k){
                st.erase(m_p(dp[to][val], m_p(val, to)));
                dp[to][val] = time1;
                p[to][val] = x;
                st.insert(m_p(dp[to][val], m_p(val, to)));
            }
        }
    }
    for(i = n; i >= 0; i--)if(dp[n][i] != 2 * 1e9)way(i);
    return 0;
}