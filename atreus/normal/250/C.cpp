#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 2e5 + 50;
const int mod = 1e9 + 7;

int a[maxn];
int ans[maxn], pre[maxn];

int cost(int x, int y){
	if (x == 0 or y == 0)
		return 0;
	return x != y;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (i == 1 or a[i] != a[i-1])
			pre[i] = i;
		else
			pre[i] = pre[i-1];
	}
	for (int i = 1; i <= n; i++)
		if (i == n or a[i] != a[i+1])
			ans[a[i]] -= cost(a[pre[i]-1], a[pre[i]]) + cost(a[i], a[i+1]) - cost(a[pre[i]-1], a[i+1]);
	int mnm = *min_element(ans + 1, ans + k + 1);
	for (int i = 1; i <= k; i++)
		if (ans[i] == mnm)
			return cout << i << endl, 0;
}