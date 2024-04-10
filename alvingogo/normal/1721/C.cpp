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
        vector<int> a(n),b(n);
        for(auto &h:a){
            cin >> h;
        }
        for(auto &h:b){
            cin >> h;
        }
        for(int i=0;i<n;i++){
            cout << *lower_bound(b.begin(),b.end(),a[i])-a[i] << " ";
        }
        cout << "\n";
        vector<int> c;
        for(int j=1;j<n;j++){
            if(a[j]>b[j-1]){
                c.push_back(j-1);
            }
        }
        c.push_back(n-1);
        for(int i=0;i<n;i++){
            cout << b[*lower_bound(c.begin(),c.end(),i)]-a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}