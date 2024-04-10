#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int main(){
	AquA;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n),b(n);
        vector<vector<int> > v(n+1);
        for(int i=0;i<n;i++){
            cin >> a[i];
            v[a[i]].push_back(i);
        }
        vector<int> vis(n);
        for(int i=0;i<n;i++){
            cin >> b[i];
        }
        int ax=n-1;
        int flag=0;
        for(int i=n-1;i>=0;i--){
            if(i<n-1 && b[i]==b[i+1]){
                if(v[b[i]].empty()){
                    cout << "No\n";
                    flag=1;
                    break;
                }
                int u=v[b[i]].back();
                v[b[i]].pop_back();
                vis[u]=1;
            }
            else if(b[i]!=a[ax]){
                while(vis[ax]){
                    ax--;
                    if(ax<0){
                        cout << "No\n";
                        flag=1;
                        break;
                    }
                    if(b[i]==a[ax]){
                        ax--;
                        int u=v[b[i]].back();
                        v[b[i]].pop_back();
                        vis[u]=1;
                        flag=-1;
                        break;
                    }
                }
                if(flag==1){
                    break;
                }
                if(flag==-1){
                    flag=0;
                    continue;
                }
                cout << "No\n";
                flag=1;
                break;
            }
            else{
                ax--;
                int u=v[b[i]].back();
                v[b[i]].pop_back();
                vis[u]=1;
            }
        }
        if(!flag){
            cout << "Yes\n";
        }
    }
	return 0;
}