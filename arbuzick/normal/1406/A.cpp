#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
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
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        vector<int> cnt(101);
        for(int i = 0; i < n; ++i)
            cnt[a[i]]++;
        int ans = 0;
        for(int i = 0; i <= 101; ++i){
            if(i == 101)
                ans = 101;
            else{
                if(cnt[i] == 0){
                    ans = i;
                    break;
                }
            }
        }
        for(int i = 0; i <= 101; ++i){
            if(i == 101)
                ans += 101;
            else{
                if(cnt[i] < 2){
                    ans += i;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}