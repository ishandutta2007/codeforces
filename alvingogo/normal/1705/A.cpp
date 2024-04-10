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
        int n,x;
        cin >> n >> x;
        vector<int> v(2*n);
        for(int i=0;i<2*n;i++){
            cin >> v[i];
        }
        sort(v.begin(),v.end());
        int flag=0;
        for(int i=0;i<n;i++){
            if(v[i+n]-x<v[i]){
                flag=1;
            }
        }
        if(flag){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    return 0;
}