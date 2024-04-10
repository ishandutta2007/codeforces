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
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        int flag=0;
        int cnt=0;
        while(v.size()>=2){
            vector<int> p;
            if(cnt){
                cnt--;
                p.push_back(v[0]);
            }
            for(int i=0;i<v.size()-1;i++){
                if(v[i+1]-v[i]){
                    p.push_back(v[i+1]-v[i]);
                }
                else{
                    cnt++;
                }
            }
            if(p.empty()){
                flag=1;
                cout << 0 << "\n";
                break;
            }
            else if(p.size()==1){
                flag=1;
                cout << p[0] << "\n";
                break;
            }
            else{
                sort(p.begin(),p.end());
                v=p;
            }
        }
        if(flag==0){
            cout << v[0] << "\n";
        }
    }
    
    return 0;
}