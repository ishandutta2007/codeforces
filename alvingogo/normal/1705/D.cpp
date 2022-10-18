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
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        if(a[0]!=b[0] || a[n-1]!=b[n-1]){
            cout << -1 << "\n";
            continue;
        }
        long long ans=0;
        vector<int> c,d;
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]){
                c.push_back(i);
            }
            if(b[i]==b[i-1]){
                d.push_back(i);
            }
        }
        if(c.size()!=d.size()){
            cout << -1 << '\n';
            continue;
        }
        sort(c.begin(),c.end());
        sort(d.begin(),d.end());
        for(int i=0;i<c.size();i++){
            ans+=abs(c[i]-d[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}