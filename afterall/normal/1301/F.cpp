#include <bits/stdc++.h>
typedef int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e6+100,M=1e3+100,K=41;
ll dis[K][N];
ll a[M][M];
ll nod[M][M];
pii don[N];
int32_t main(){
    sync;
    ll cnt=41;
    ll n,m,k;
    cin >> n >> m >> k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> a[i][j];
            nod[i][j]=cnt++;
            don[cnt-1]={i,j};
        }
    }
    for (int ii=1;ii<=k;ii++){
        memset(dis[ii],31,sizeof dis[ii]);
        dis[ii][ii]=0;
        queue <int> q;
        q.push(ii);
        while(q.size()){
            ll v=q.front();
            q.pop();
            if (v<41){
                for (int i=1;i<=n;i++){
                    for (int j=1;j<=m;j++){
                        if (a[i][j]==v){
                            if (dis[ii][nod[i][j]]>dis[ii][v]+1){
                                q.push(nod[i][j]);
                                dis[ii][nod[i][j]]=dis[ii][v]+1;
                            }
                        }
                    }
                }
            }
            else{
                ll x=don[v].F,y=don[v].S;
                if (a[x+1][y] && dis[ii][nod[x+1][y]]>dis[ii][v]+1){
                    q.push(nod[x+1][y]);
                    dis[ii][nod[x+1][y]]=dis[ii][v]+1;
                }
                if (a[x-1][y] && dis[ii][nod[x-1][y]]>dis[ii][v]+1){
                    q.push(nod[x-1][y]);
                    dis[ii][nod[x-1][y]]=dis[ii][v]+1;
                }
                if (a[x][y+1] && dis[ii][nod[x][y+1]]>dis[ii][v]+1){
                    q.push(nod[x][y+1]);
                    dis[ii][nod[x][y+1]]=dis[ii][v]+1;
              //  if (ii==1 && x==3 && y==2) cout << "JER" << " " << dis[ii][nod[3][3]]<< endl;
                }
                if (a[x][y-1] && dis[ii][nod[x][y-1]]>dis[ii][v]+1){
                    q.push(nod[x][y-1]);
                    dis[ii][nod[x][y-1]]=dis[ii][v]+1;
                }
                if (dis[ii][a[x][y]]>dis[ii][v]){
                    q.push(a[x][y]);
                    dis[ii][a[x][y]]=dis[ii][v];
                }
            }
        }
    }
    ll q;
    cin >> q;
    while(q--){
        ll x,y,z,t;
        cin >> x >> y >> z >> t;
        ll ans=abs(x-z)+abs(y-t);
        for (int i=1;i<=k;i++){
            ans=min(ans,dis[i][nod[x][y]]-1+dis[i][nod[z][t]]);
        }
        cout << ans << endl;
    }
  //  cout << dis[1][nod[3][3]] << endl;

}