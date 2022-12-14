#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
const int maxn = 3e5 + 5;

ll a[maxn], mask[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> mask[i], sum += a[i];
	ll answer = 0;
	for (int lg = 62; lg >= 0; lg--){
		ll now = 0;
		for (int i = 0; i < n; i++)
			if ((mask[i] & -mask[i]) == (1ll << lg))
				now += a[i];
		if (now == 0)
			continue;
		if ((now > 0) ^ (sum < 0)){
			answer |= (1ll << lg);
			for (int i = 0; i < n; i++)
				if (mask[i] & (1ll << lg))
					a[i] *= -1;
		}
	}
	cout << answer << '\n';
}