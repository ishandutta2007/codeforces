#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<pair<pair<int,int>,int> > e(m);
        vector<vector<int> > dis(n,vector<int>(n,1e9));
        for(int i=0;i<m;i++){
            cin >> e[i].fs.fs >> e[i].fs.sc >> e[i].sc;
            e[i].fs.fs--;
            e[i].fs.sc--;
            dis[e[i].fs.fs][e[i].fs.sc]=dis[e[i].fs.sc][e[i].fs.fs]=1;
        }
        for(int i=0;i<n;i++){
            dis[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        long long ans=1e18;
        for(auto h:e){
            int k=1e9;
            k=min(k,dis[h.fs.fs][0]+dis[h.fs.sc][n-1]+1);
            k=min(k,dis[h.fs.sc][0]+dis[h.fs.fs][n-1]+1);
            for(int i=0;i<n;i++){
                int nw=dis[i][0]+dis[i][n-1];
                k=min(k,dis[h.fs.fs][i]+nw+2);
                k=min(k,dis[h.fs.sc][i]+nw+2);
            }
            ans=min(ans,1ll*k*h.sc);
            
        }
        cout << ans << "\n";
    }
    return 0;
}