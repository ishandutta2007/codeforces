#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100,M=20;
ll dp[(1<<M)];
ll l[N];
ll p[N];
ll mod=998244353;
ll cnt[M][M];
ll val[M][M];
int32_t main(){
    sync;
    ll d;
    cin >> d;
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> l[i];
    }
    sort(l+1,l+n+1);
    for (int i=1;i<=m;i++){
        cin >> p[i];
    }
    sort(p+1,p+m+1);
    m++;
    p[m]=1e9;
    p[0]=-1e9;
    
    m++;
    for (int i=0;i<m;i++){
        for (int j=i+1;j<m;j++){
            cnt[i][j]=1;
            for (int k=1;k<=n;k++){
                if (l[k]>p[i] && l[k]<p[j]){
                  //  cout << i << " " << j << " " << k << endl;
                    cnt[i][j]*=min(d+1,min(l[k]-p[i],p[j]-l[k]));
                    cnt[i][j]%=mod;
                }
            }
        }
    }
   // cout << " erfjn " << cnt[m-2][m-1] << endl;
    ll ans=0;
    for (int i=0;i<(1<<(m-2));i++){
        vector <int> bit;
        bit.pb(0);
        for (int j=0;j<m-2;j++){
            if ((i & (1<<j))) bit.pb(j+1);
        }
        bit.pb(m-1);
        dp[i]=1;
        if (bit.size()%2==1) dp[i]=-1;
        for (int j=1;j<bit.size();j++){
            dp[i]*=cnt[bit[j-1]][bit[j]];
            dp[i]%=mod;
        }
        ans+=dp[i];
        ans%=mod;
        for (int j=1;j<bit.size();j++){
            val[bit[j-1]][bit[j]]+=dp[i];
            val[bit[j-1]][bit[j]]%=mod;
        }
       // cout << i << " " << dp[i] << endl;
    }
    //cout << ans << endl;
    ll q;
    cin >> q;
    while(q--){
        ll x;
        cin >> x;
        ll z=ans;
        for (int i=0;i<m;i++){
            for (int j=i+1;j<m;j++){
                if (x>p[i] && x<p[j]){
                    z-=val[i][j];
                    z%=mod;
                 //   cout << i << " jn " << j << " " << val[i][j] << " " << min(d+1,min(x-p[i],p[j]-x)) << " " << val[i][j]*min(d+1,min(x-p[i],p[j]-x)) << endl;
                    z+=val[i][j]*min(d+1,min(x-p[i],p[j]-x))%mod;
                    z%=mod;
                }
            }
        }
        z+=mod;
        cout << z%mod << endl;
    }

}