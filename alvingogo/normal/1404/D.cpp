#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

vector<int> e;
int n;
vector<int> vis;
void dfs(int x,int nw){
    vis[x]=nw;
    int ot=(x<n)?x+n:x-n;
    vis[ot]=-nw;
    int r=e[ot];
    if(vis[r]){
        return;
    }
    dfs(r,nw);
}
int main(){
    AquA;
    cin >> n;
    if(n%2==0){
        cout << "First" << endl;
        for(int i=1;i<=2*n;i++){
            cout << i%n+1 << " ";
        }
        cout << endl;
    }
    else{
        cout << "Second" << endl;
        vector<vector<int> > v(n);
        for(int i=0;i<2*n;i++){
            int a;
            cin >> a;
            a--;
            v[a].push_back(i);
        }
        e.resize(2*n);
        vis.resize(2*n);
        for(int i=0;i<n;i++){
            e[v[i][0]]=v[i][1];
            e[v[i][1]]=v[i][0];
        }       
        for(int i=0;i<2*n;i++){
            if(!vis[i]){
                dfs(i,1);
            }
        }
        long long u1=0,u2=0;
        for(int i=0;i<2*n;i++){
            if(vis[i]>0){
                u1+=(i+1);
            }
            else{
                u2+=(i+1);
            }
        }
        if(u1%2==0){
            for(int i=0;i<2*n;i++){
                if(vis[i]>0){
                    cout << i+1 << " ";
                }
            }
            cout << endl;
        }
        else{
            assert(u2%2==0);
            for(int i=0;i<2*n;i++){
                if(vis[i]<0){
                    cout << i+1 << " ";
                }
            }
            cout << endl;
        }

    }
    return 0;
}