#include <bits/stdc++.h>
/// 500 485 462 A4
using namespace std;
typedef long long int ll;
typedef complex<double> point;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
const int N=500+110;
ll dis[N][N];
ll val[N];
ll yal[N][N];
ll mn[N][N];
ll mark[N][N];
int32_t main(){
    sync;
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) dis[i][j]=(ll)1e15,mn[i][j]=0;
        dis[i][i]=0;
    }
    for (int i=0;i<m;i++){
        ll u,v,l;
        cin >> u >> v >> l;
        dis[u][v]=min(dis[u][v],l);
        dis[v][u]=dis[u][v];
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++) yal[i][j]=dis[i][j];
    }
    for (int i=1;i<=n;i++){
        yal[i][i]=(ll)1e15;
    }
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    ll q;
    cin >> q;
    while(q--){
        ll u,v,l;
        cin >> u >> v >> l;
        for (int i=1;i<=n;i++){
            if (dis[u][i]+dis[i][v]<=l){
                mn[u][i]=max(mn[u][i],l-dis[i][v]);
            }
        }
    }
    ll ans=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int k=1;k<=n;k++){
                if (dis[i][k]+yal[k][j]<=mn[i][j]) mark[k][j]=1;
             //   if (mn[i][j]>0){
               //     cout << i << " " << k  << " " << j << " " << mark[k][j] << endl;
               // }
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++) ans+=max(mark[j][i],mark[i][j]);
    }
    cout << ans << endl;

}