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
        int n;
        cin >> n;
        vector<vector<vector<int> > > v(n,vector<vector<int> >(n));
        vector<vector<int> > a(2*n,vector<int>(n));
        for(int i=0;i<2*n;i++){
            for(int j=0;j<n;j++){
                cin >> a[i][j];
                a[i][j]--;
                v[j][a[i][j]].push_back(i);
            }
        }
        queue<pair<int,int> > q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j].size()==1){
                    q.push({i,j});
                }
            }
        }
        vector<int> f(2*n);
        const int mod=998244353;
        int ans=1;
        for(int z=0;z<n;z++){
            int nw=-1;
            while(q.size()){
                auto h=q.front();
                q.pop();
                if(v[h.fs][h.sc].size()!=1){
                    continue;
                }
                if(f[v[h.fs][h.sc][0]]==0){
                    nw=v[h.fs][h.sc][0];
                    break;
                }
            }
            if(nw==-1){
                ans=2ll*ans%mod;
                for(int i=0;i<2*n;i++){
                    if(f[i]==0){
                        nw=i;
                        break;
                    }
                }
            }
            f[nw]=1;
            for(int i=0;i<n;i++){
                for(auto h:v[i][a[nw][i]]){
                    if(f[h]==0){
                        f[h]=-1;
                        for(int k=0;k<n;k++){
                            for(int l=0;l<v[k][a[h][k]].size();l++){
                                if(v[k][a[h][k]][l]==h){
                                    swap(v[k][a[h][k]][l],v[k][a[h][k]][v[k][a[h][k]].size()-1]);
                                    v[k][a[h][k]].pop_back();
                                    if(v[k][a[h][k]].size()==1){
                                        q.push({k,a[h][k]});
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
                v[i][a[nw][i]].clear();
            }
        }
        cout << ans << "\n";
        for(int i=0;i<2*n;i++){
            if(f[i]==1){
                cout << i+1 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}