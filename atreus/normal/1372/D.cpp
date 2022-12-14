#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
const int maxn = 3e5 + 5;

ll a[maxn], par[maxn], suf[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (i >= 2)
			par[i] = par[i-2];
		par[i] += a[i];
		sum += a[i];
	}
	for (int i = n; i >= 1; i--){
		suf[i] = suf[i+2] + a[i];
	}
	if (n == 1)
		return cout << a[1] << endl, 0;
	ll answer = 0;
	for (int i = 1; i <= n; i++)
		answer = max(answer, sum - par[i-1] - suf[i+2]);
	cout << answer << endl;
}