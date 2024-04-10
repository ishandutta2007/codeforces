#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n, k;
ll a[200200];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> k;
		rep(i, n)
			cin >> a[i];
		ll sum = 0;
		rep(i, n)
			sum += a[i];
		rep(i, k)
			sum -= k - i - 1;
		rep(i, n)
			a[i] = a[i] - (n - i - 1);
		sort(a, a + n);
		for(int i = n - 1; i >= n - k; i--)
			sum -= a[i];
		cout << sum << endl;
	}
	return 0;
}