#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=520;
map <pair <pii,pii>,int> mp;
ll g[N*N][4];
/// 0 i-1
/// 1 i+1
/// 2 j-1
/// 3 j+1
ll id[N][N];
ll dis[N][N];
pii bk[N*N];
ll dijkstra(ll n){
    set <pii> s;
    for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) dis[i][j]=(ll)1e12;
    dis[n/2][n/2]=0;
    s.insert({0,id[n/2][n/2]});
    while(s.size()){
        ll v=s.begin()->S;
        s.erase(s.begin());
        ll x1=bk[v].F;
        ll y1=bk[v].S;
        ll x2=n-x1;
        ll y2=n-y1;
       // cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << dis[x1][y1] << endl;
        for (int i=-1;i<=1;i++){
            for (int j=-1;j<=1;j++){
                if ((i+j)%2==0 || x1+i<0 || x1+i>n || y1+j<0 || y1+j>n) continue;
                ll w=0;
                if (i==-1){
                    w+=g[id[x1][y1]][0]+g[id[x2][y2]][1];
                }
                if (i==1){
                    w+=g[id[x1][y1]][1]+g[id[x2][y2]][0];
                }
                if (j==-1){
                    w+=g[id[x1][y1]][2]+g[id[x2][y2]][3];
                }
                if (j==1){
                    w+=g[id[x1][y1]][3]+g[id[x2][y2]][2];
                }
                if (dis[x1+i][y1+j]>dis[x1][y1]+w){
                    s.erase({dis[x1+i][y1+j],id[x1+i][y1+j]});
                    dis[x1+i][y1+j]=dis[x1][y1]+w;
                    s.insert({dis[x1+i][y1+j],id[x1+i][y1+j]});
                }
            }
        }
    }
    return min(dis[0][0],dis[0][n]);
}
void Main(){

    ll n,k;
    cin >> k >> n;

    mp.clear();
    for (int i=1;i<=(n+3)*(n+3);i++) for (int j=0;j<4;j++) g[i][j]=0;
    for (int i=0;i<k;i++){
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        mp[{{x1,y1},{x2,y2}}]++;
        mp[{{x2,y2},{x1,y1}}]++;
    }
    ll cnt=0;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            id[i][j]=cnt++;
            bk[cnt-1]={i,j};
        }
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            /// i ,i+1
            if (i!=n){
                ll w=0;
                if (j!=0){
                    w=mp[{{i+1,j},{i+1,j+1}}];
                }
                g[id[i][j]][1]+=w;
                g[id[i+1][j]][0]+=w;
            }

            if (j!=n){

                ll w=0;
                if (i!=0){
                    w=mp[{{i,j+1},{i+1,j+1}}];
                }
              //  if (i==2 && j==1) cout << w << " eifn " << endl;
                g[id[i][j]][3]+=w;
                g[id[i][j+1]][2]+=w;
            }
        }
    }
   // cout << g[id[2][2]][2] << endl;
    cout << k-dijkstra(n) << endl;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--){
        Main();
    }

}