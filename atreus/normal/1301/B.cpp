#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10;
const int inf = 2e9;

int a[maxn];

void solve(){
	int n;
	cin >> n;
	a[0] = a[n+1] = 0;
	int m = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n - 1; i++)
		if (a[i] != -1 and a[i+1] != -1)
			m = max(m, abs(a[i] - a[i+1]));
	vector<int> b;
	for (int i = 1; i <= n; i++)
		if (a[i] != -1 and (a[i+1] == -1 or a[i-1] == -1))
			b.push_back(a[i]);
	if (b.empty())
		b.push_back(0);
	int mxm = *max_element(b.begin(), b.end());
	int mnm = *min_element(b.begin(), b.end());
	cout << max(m, (mxm - mnm + 1) / 2) << " " << (mxm + mnm)/2 << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		solve();
	}
}