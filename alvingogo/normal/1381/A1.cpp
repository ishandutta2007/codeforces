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
        string a,b;
        cin >> a >> b;
        vector<int> ans;
        for(int i=0;i<n;i++){
            int x;
            if(i%2){
                x=(a[n-1-i/2])^1;
            }
            else{
                x=a[i/2];
            }
            if(x==b[n-1-i]){
                ans.push_back(1);
            }
            ans.push_back(n-i);
        }
        cout << ans.size() << " ";
        for(auto h:ans){
            cout << h << " ";
        }
        cout << "\n";
    }
    return 0;
}