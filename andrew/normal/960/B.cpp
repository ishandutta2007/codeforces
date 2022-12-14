#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()

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

vector <ll> v[MAXN],va;
string s1,s2,s3;
set <ll> s;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
//bool f[1001][1001];
//ll dp[1001][1001];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll k1, k2;
    cin >> n >> k1 >> k2;
    for(i = 1; i <= n; i++)cin >> a[i];
    for(i = 1; i <= n; i++)cin >> b[i];
    for(ll i1 = 1; i1 <= k1; i1++){
        ll mx = -1, mxj = 0;
        for(i = 1; i <= n;i++)if(sqr(a[i] - b[i]) > mx){
            mxj = i;
            mx = sqr(a[i] - b[i]);
        }
        if(sqr(a[mxj] + 1 - b[mxj]) < sqr(a[mxj] - 1 - b[mxj]))a[mxj]++; else a[mxj]--;
        //cout << mxj << " " << a[mxj] << endl;
    }

    for(ll i1 = 1; i1 <= k2; i1++){
        ll mx = -1, mxj = 0;
        for(i = 1; i <= n;i++)if(sqr(a[i] - b[i]) > mx){
            mxj = i;
            mx = sqr(a[i] - b[i]);
        }
        if(sqr(a[mxj] - (b[mxj] + 1 )) < sqr(a[mxj] - (b[mxj] - 1)))b[mxj]++; else b[mxj]--;
    }

    for(i = 1; i <= n; i++)ans += sqr(a[i] - b[i]);
    vout(ans);
    return 0;
}