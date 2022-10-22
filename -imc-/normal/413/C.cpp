#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> a(n), isAuc(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	vector<int> auc(m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &auc[i]);
		auc[i]--;
		isAuc[auc[i]] = true;
	}

	vector<ll> aucs;
	ll answer = 0;
	for (int i = 0; i < n; i++)
		if (isAuc[i])
			aucs.push_back(a[i]);
		else
			answer += a[i];

	sort(aucs.rbegin(), aucs.rend());
	for (auto it: aucs)
		answer += max(it, answer);

	cout << answer << endl;

	return 0;
}