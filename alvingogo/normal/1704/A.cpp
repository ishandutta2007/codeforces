#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define int long long
using namespace std;

signed main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        string a,b;
        cin >> a >> b;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int flag=0;
        for(int i=0;i<m-1;i++){
            if(b[i]!=a[i]){
                cout << "No\n";
                flag=1;
                break;
            }
        }
        if(flag){
            continue;
        }
        for(int i=m-1;i<n;i++){
            if(a[i]==b[m-1]){
                cout << "Yes\n";
                flag=1;
                break;
            }
        }
        if(flag){
            continue;
        }
        cout << "No\n";
    }
    return 0;
}