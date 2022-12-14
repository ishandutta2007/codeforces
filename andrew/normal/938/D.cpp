#include <bits/stdc++.h>

#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;

ll binpow(ll a,ll n)
{
    ll res = 1;
    while(n)
    {
        if(n % 2)res *= a;
        a *= a;
        n /= 2;
    }
    return res;
}

template <typename T>
T sqr(T x)
{
    return x * x;
}

template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}

ll log(ll a,ll b){
    ll res = 0;
    while(a){
        a /= b;
        res++;
    }
    return res;
}

const ll MAXN = 1123456;
vector <pll> v[MAXN];
set <pll> st;
stringstream ss;
set <ll> s;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
ll dp[MAXN];
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> m;
    while(m--){
        cin >> a1 >> b1 >> c1;
        v[a1].p_b(m_p(b1,c1));
        v[b1].p_b(m_p(a1,c1));
    }
    for(i = 1;i <= n; i++)cin >> a[i];
    for(i = 1; i <= n; i++){
        st.insert(m_p(a[i],i));
        dp[i] = a[i];
    }
    set <pll> :: iterator it;
    while(!st.empty()){
        it = st.begin();
        ll x = it -> se, val = it -> fi;
        st.erase(it);
        ll nn = v[x].size();
        for(i = 0; i < nn; i++){
            ll to = v[x][i].fi, val1 = val + v[x][i].se * 2;
            if(dp[to] > val1){
                st.erase(m_p(dp[to],to));
                dp[to] = val1;
                st.insert(m_p(dp[to],to));
            }
        }
    }
    for(i = 1; i <= n; i++)cout << dp[i] << " ";
    cout << endl;
    return 0;
}