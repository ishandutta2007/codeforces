#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

struct DSU{
    vector<int> bo;
    void init(int n){
        bo.resize(n);
        iota(bo.begin(),bo.end(),0);
    }
    int find(int x){
        if(x<0){
            return -find(-x);
        }
        if(bo[x]==x){
            return x;
        }
        return bo[x]=find(bo[x]);
    }
    void merge(int x,int y){
        x=find(x);
        y=find(y);
        if(abs(x)!=abs(y)){
            if(x>0){
                bo[x]=y;
            }
            else{
                bo[-x]=-y;
            }
        }
    }
};
int main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int> > v(n+1,vector<int>(n+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> v[i][j];
            }
        }
        DSU dsu;
        dsu.init(n+1);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(v[i][j]>v[j][i]){
                    dsu.merge(i,-j);
                }
                else if(v[i][j]<v[j][i]){
                    dsu.merge(i,j);
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dsu.find(i)>0){
                for(int j=1;j<=n;j++){
                    swap(v[i][j],v[j][i]);
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout << v[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}