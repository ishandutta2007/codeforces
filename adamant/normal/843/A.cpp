#include <bits/extc++.h>

using namespace std;

signed main()
{
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
		cin >> a[i];
	int p[n];
	iota(p, p + n, 0);
	sort(p, p + n, [&](int x, int y){return a[x] < a[y];});
	int used[n] = {0};
	vector<vector<int>> ans;
	for(int i = 0; i < n; i++)
	{
		if(used[i])
			continue;
		int j = i;
		vector<int> cyc;
		while(!used[j])
		{
			cyc.push_back(j);
			used[j] = 1;
			j = p[j];
		}
		ans.push_back(cyc);
	}
	cout << ans.size() << endl;
	for(auto it: ans)
	{
		cout << it.size() << ' ';
		for(auto jt: it)
			cout << jt + 1 << ' ';
		cout << "\n";
	}
    return 0;
}