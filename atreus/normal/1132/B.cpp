#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 3e5 + 10;
const ll inf = 1e18;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	int m;
	cin >> m;
	while (m--){
		int x;
		cin >> x;
		cout << sum - a[n - x] << '\n';
	}
}