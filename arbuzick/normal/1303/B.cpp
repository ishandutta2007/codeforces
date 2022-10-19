#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
        int n, g, b;
        cin >> n >> g >> b;
        int k;
        if((n+1)/2%g == 0)
            k = ((n+1)/2/g-1)*(g+b)+g;
        else
            k = (n+1)/2/g*(g+b)+(n+1)/2%g;
        int k2 = k/(g+b)*b;
        if(k2 < n/2)
            k += n/2-k2;
        cout << k << '\n';
	}
	return 0;
}