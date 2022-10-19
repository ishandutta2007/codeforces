#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        vector<int> ans;
        while(1){
            bool f = 1;
            for(int i = 1; i < n; ++i)
                if(a[i] < a[i-1])
                    f = 0;
            if(f)
                break;
            vector<int> used(n+1);
            for(int i = 0; i < n; ++i)
                used[a[i]] = 1;
            for(int i = 0; i <= n; ++i){
                if(!used[i]){
                    if(i < n){
                        a[i] = i;
                        ans.pb(i+1);
                    }else{
                        for(int j = 0; j < n; ++j)
                            if(a[j] != j){
                                a[j] = i;
                                ans.pb(j+1);
                                break;
                            }
                    }
                    break;
                }
            }
        }
        cout << ans.size() << "\n";
        for(int i = 0; i < ans.size(); ++i)
            cout << ans[i] << ' ';
        cout << "\n";
    }
    return 0;
}