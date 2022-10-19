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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a.rbegin(), a.rend());
        int ans = 0;
        int k = 0;
        for(int i = 0; i < n; ++i){
            k++;
            if(k*a[i] >= x){
                ans++;
                k = 0;
            }
        }
        cout << ans << '\n';
    }
	return 0;
}