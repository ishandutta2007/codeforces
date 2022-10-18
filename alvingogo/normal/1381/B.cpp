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
        vector<int> p(2*n);
        for(int i=0;i<2*n;i++){
            cin >> p[i];
        }
        vector<int> vis(2*n+1);
        vector<int> v;
        vector<int> ab(n+1);
        ab[0]=1;
        for(int i=2*n;i>0;i--){
            if(vis[i]==1){
                continue;
            }
            for(int j=0;j<2*n;j++){
                if(p[j]==i){
                    int nw=0;
                    for(int k=j;k<2*n;k++){
                        if(vis[p[k]]){
                            break;
                        }
                        vis[p[k]]=1;
                        nw++;
                    }
                    v.push_back(nw);
                    break;
                }
            }
        }
        vector<int> k;
        for(auto h:v){
            for(int i=n;i>=0;i--){
                if(ab[i]){
                    if(i+h<=n){
                        ab[i+h]=1;
                    }
                }
            }
        }
        if(ab[n]){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << "\n";
    }
    
    return 0;
}