#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define int long long
using namespace std;

signed main(){
    AquA;
    int n,m;
    cin >> n >> m;
    vector<pair<pair<int,int>,int> > v;
    vector<vector<int> > dis(n,vector<int>(n,1e18)),x(n,vector<int>(n,-1e18)); 
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        v.push_back({{a,b},c});
        dis[a][b]=min(dis[a][b],c);
        dis[b][a]=min(dis[b][a],c);
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
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        for(int j=0;j<n;j++){
            x[a][j]=max(x[a][j],c-dis[j][b]);
            x[b][j]=max(x[b][j],c-dis[j][a]);
        }
    }
    int ans=0;
    for(auto h:v){
        for(int i=0;i<n;i++){
            if(dis[h.fs.fs][i]+h.sc<=x[i][h.fs.sc] || dis[h.fs.sc][i]+h.sc<=x[i][h.fs.fs]){
                ans++;
                break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}