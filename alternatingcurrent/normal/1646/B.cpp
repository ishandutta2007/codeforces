#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n;
ll a[200200];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		sort(a, a + n);
		reverse(a, a + n);
		ll sum0 = 0, sum1 = 0;
		bool ok = 0;
		for(int i = 1; i <= n; i++){
			sum1 += a[n - i];
			if(sum0 > sum1)
				ok = 1;
			sum0 += a[i - 1];
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
	return 0;
}