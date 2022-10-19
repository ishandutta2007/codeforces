#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rll(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        int m1 = a[0], m2 = a[0];
        for(int i = 0; i < n; ++i)
            m1 = min(m1, a[i]), m2 = max(m2, a[i]);
        vector<int> ans(n);
        for(int i = 0; i < n; ++i){
            if(a[i] == m1){
                if(k%2 == 0)
                    ans[i] = 0;
                else
                    ans[i] = m2-m1;
            }else if(a[i] == m2){
                if(k%2 == 0)
                    ans[i] = m2-m1;
                else
                    ans[i] = 0;
            }else{
                if(k%2 == 1)
                    ans[i] = m2-a[i];
                else
                    ans[i] = a[i]-m1;
            }
        }
        for(int i = 0; i < n; ++i)
            cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}