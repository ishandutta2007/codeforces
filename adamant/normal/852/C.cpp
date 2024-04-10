#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
	int p[n];
	for(int i = 0; i < n; i++)
		cin >> p[i];
	int b[n];
	for(int i = 0; i < n; i++)
		b[i] = p[i] + p[(i + 1) % n];
	int a[n];
	iota(a, a + n, 0);
	sort(a, a + n, [&](int x, int y){return b[x] < b[y];});
	int ans[n];
	for(int i = 0; i < n; i++)
		ans[a[i]] = i;
	for(auto it: ans)
		cout << it << ' ';
	cout << endl;
    return 0;
}