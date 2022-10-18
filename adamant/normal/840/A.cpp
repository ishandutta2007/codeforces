#include <bits/extc++.h>

using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n], b[n];
    for(auto &it: a)
		cin >> it;
    for(auto &it: b)
		cin >> it;
	int p[n];
	iota(p, p + n, 0);
	sort(p, p + n, [&](int x, int y){return b[x] < b[y];});
	int ans[n];
	sort(a, a + n, greater<int>());
	for(int i = 0; i < n; i++)
		ans[p[i]] = a[i];
	for(auto it: ans)
		cout << it << ' ';
}