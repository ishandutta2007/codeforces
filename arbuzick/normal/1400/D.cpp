#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
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
        vector<int> a(n);
        vector<int> cnt(n+1);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        int ans = 0;
        for(int j = 0; j < n; ++j){
            int ans1 = 0;
            for(int l = j+1; l < n; ++l){
                if(a[j] == a[l])
                    ans += ans1;
                ans1 +=cnt[a[l]];
            }
            cnt[a[j]]++;
        }
        cout << ans << '\n';
    }
    return 0;
}