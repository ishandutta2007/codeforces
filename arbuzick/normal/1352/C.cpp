#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
        int n, k;
        cin >> n >> k;
        int ans;
        if(k%(n-1) == 0)
            ans = (k-1)/(n-1)*n+n-1;
        else
            ans = k/(n-1)*n+k%(n-1);
        cout << ans << '\n';
	}
	return 0;
}