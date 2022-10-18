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
        vector<int> a(n);
        for(auto &h:a){
            cin >> h;
        }
        int maxx=-88888;
        for(int i=0;i<n-1;i++){
            maxx=max(maxx,a[i]-a[i+1]);
        }
        maxx=max(maxx,a[n-1]-a[0]);
        for(int i=1;i<n;i++){
            maxx=max(maxx,a[i]-a[0]);
        }
        for(int i=0;i<n-1;i++){
            maxx=max(maxx,a[n-1]-a[i]);
        }
        cout << maxx << "\n";
    }
    return 0;
}