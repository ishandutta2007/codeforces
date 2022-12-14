#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int a[maxn];

int solve(int l, int r, int x){
	if (x < 0)
		return r-l;
	int ret = 0;
	int diff = 0;
	int ptl = r, ptr = r;
	for (int i = x; i >= 0; i--){
		ptr = ptl;
		while (ptl > l and a[ptl-1]&(1<<i))
			ptl --;
		if (ptl == ptr)
			continue;
		for (int j = ptl; j < ptr; j++)
			a[j] ^= (1<<i);
		ret = max(ret, solve(ptl, ptr, i-1) + (ptl > l) + diff);
		for (int j = ptl; j < ptr; j++)
			a[j] ^= (1<<i);
		diff ++;
	}
	ret = max(ret,ptl-l+diff);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	cout << n-solve(0, n, 29) << '\n';
}