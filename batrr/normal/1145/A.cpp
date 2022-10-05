#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, a[N], ans = 1;

void solve(int l, int r){
	if(l == r)
		return;
	bool ok = 1;
	for(int i = l + 1; i <= r; i++)
		if(a[i - 1] > a[i])
			ok = 0;
	if(ok)
		ans = max(ans, r - l + 1);
	int m = (l + r) / 2;
	solve(l, m);
	solve(m + 1, r);
}
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	solve(0, n - 1);
	cout << ans;
	return 0;
}