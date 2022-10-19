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
        vector<int> w(n);
        for(int i = 0; i < n; ++i)
            cin >> w[i];
        int k = 0;
        for(int s = 2; s <= n*2; ++s){
            int k1 = 0;
            vector<int> used(n);
            for(int i = 0; i < n; ++i)
                for(int j = i+1; j < n; ++j)
                    if(!used[i] && !used[j] && w[i]+w[j] == s)
                        k1++, used[i] = used[j] = 1;
            k = max(k1, k);
        }
        cout << k << '\n';
    }
    return 0;
}