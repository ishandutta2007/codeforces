#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> a(100000);
	a[0] = 2;
	for(int i = 1; i < 100000; ++i)
        a[i] = i+(i+1)*2+a[i-1];
	int t;
	cin >> t;
	while(t--){
        int n;
        cin >> n;
        int ans = 0;
        while(n > 1){
            int k = lower_bound(a.begin(), a.end(), n)-a.begin();
            if(a[k] != n)
                k--;
            ans++;
            n -= a[k];
        }
        cout << ans << '\n';
	}
	return 0;
}