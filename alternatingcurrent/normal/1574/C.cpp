#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int n, m;
ll a[200200];

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n)
		cin >> a[i];
	sort(a, a + n);
	ll sum = 0;
	rep(i, n)
		sum += a[i];
	cin >> m;
	rep(i, m){
		ll x, y;
		cin >> x >> y;
		int pos = upper_bound(a, a + n, x) - a;
		ll ret = 0x3f3f3f3f3f3f3f3f;
		if(pos > 0){
			ret = min(ret, max(0ll, x - a[pos - 1]) + max(0ll, y - (sum - a[pos - 1])));
		} if(pos < n){
			ret = min(ret, max(0ll, x - a[pos]) + max(0ll, y - (sum - a[pos])));
		}
		cout << ret << endl;
	}
	return 0;
}