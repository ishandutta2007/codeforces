#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    //AquA;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        vector<int> z(n);
        iota(z.begin(),z.end(),0);
        vector<int> ans(n);
        int cnt=0;
        while(z.size()){
            cnt++;
            int maxx=z[0];
            for(auto h:z){
                if(v[h]>v[maxx]){
                    maxx=h;
                }
            }
            vector<int> y;
            int u=cnt;
            vector<int> x;
            for(int i=0;i<v[maxx];i++){
                cout << "? " << maxx+1 << endl;
                int a;
                cin >> a;
                a--;
                if(!ans[a]){
                    x.push_back(a);
                }
                else{
                    u=ans[a];
                    break;
                }
            }
            ans[maxx]=u;
            for(auto h:x){
                ans[h]=u;
            }
            for(auto h:z){
                if(!ans[h]){
                    y.push_back(h);
                }
            }
            z=y;
        }
        cout << "! ";
        for(int i=0;i<n;i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}