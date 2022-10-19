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
        int n;
        cin >> n;
        vector<int> used(n+1), p;
        for(int i = 0; i < n*2; ++i){
            int x;
            cin >> x;
            if(used[x])
                p.pb(x);
            else
                used[x] = 1;
        }
        for(int i = 0; i < n; ++i)
            cout << p[i] << ' ';
        cout << '\n';
    }
}