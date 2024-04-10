#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        set<int> a;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            a.insert(x);
        }
        vector<int> b(m);
        for(int i = 0; i < m; ++i)
            cin >> b[i];
        for(int i = 0; i < m; ++i){
            if(a.count(b[i])){
                cout << "YES\n";
                cout << 1 << ' ' << b[i] << '\n';
                break;
            }
            if(i == m-1)
                cout << "NO\n";
        }
    }
}