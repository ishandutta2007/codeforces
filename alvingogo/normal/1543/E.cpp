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
        vector<vector<int> > v(1<<n);
        for(int i=0;i<n*(1<<(n-1));i++){
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vector<int> a(1<<n),vis(1<<n);
        a[0]=0;
        int p=1;
        vis[0]=1;
        for(auto h:v[0]){
            a[p]=h;
            vis[h]=1;
            p<<=1;
        }
        for(int i=1;i<(1<<n);i++){
            if(a[i]){
                continue;
            }
            int b=-1,c=-1;
            for(int j=0;j<n;j++){
                if((i>>j)&1){
                    if(b<0){
                        b=a[i^(1<<j)];
                    }
                    else if(c<0){
                        c=a[i^(1<<j)];
                        break;
                    }
                }
            }
            int flag=0;
            for(auto h:v[b]){
                for(auto y:v[c]){
                    if(h==y && !vis[h]){
                        a[i]=h;
                        vis[h]=1;
                        flag=1;
                        break;
                    }
                }
                if(flag){
                    break;
                }
            }
        }
        for(auto h:a){
            cout << h << " ";
        }
        cout << "\n";
        if(n==1 || n==2 || n==4 || n==8 || n==16){
            vector<int> z(1<<n);
            for(int i=0;i<(1<<n);i++){
                int nw=0;
                for(int j=0;j<n;j++){
                    if((i>>j)&1){
                        nw^=j;
                    }
                }
                z[a[i]]=nw;
            }
            for(auto h:z){
                cout << h << " ";
            }
            cout << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }
    return 0;
}