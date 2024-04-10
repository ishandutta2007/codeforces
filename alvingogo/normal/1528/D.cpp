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
    vector<vector<int> > v(n,vector<int>(n,1e18));
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        int c;
        cin >> c;
        v[a][b]=min(v[a][b],c);
    }
    for(int i=0;i<n;i++){
        vector<int> dis(n,1e18);
        vector<int> vis(n);
        for(int j=0;j<n;j++){
            dis[j]=min(dis[j],v[i][j]);
        }
        //vis[i]=1;
        for(int j=1;j<n;j++){
            int x=-1;
            for(int z=0;z<n;z++){
                if(!vis[z]){
                    if(x==-1){
                        x=z;
                    }
                    else{
                        if(dis[x]>dis[z]){
                            x=z;
                        }
                    }
                }
            }
            if(x==-1){
                break;
            }
            vis[x]=1;
            dis[(x+1)%n]=min(dis[(x+1)%n],dis[x]+1);
            for(int k=0;k<n;k++){
                dis[(k+dis[x])%n]=min(dis[(k+dis[x])%n],dis[x]+v[x][k]);
            }
        }
        dis[i]=0;
        for(int i=0;i<n;i++){
            cout << dis[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}