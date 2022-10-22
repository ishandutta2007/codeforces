#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int d, n, m;
	scanf("%d %d %d", &d, &n, &m);
	
	vector<pair<int, int>> stops(m);
	for (int i = 0; i < m; i++)
		scanf("%d %d", &stops[i].first, &stops[i].second);
	m += 2;
	stops.emplace_back(0, 0);
	stops.emplace_back(d, 0);
	sort(stops.begin(), stops.end());
	
	vector<int> nextLeq(m, -1);
	vector<int> stopStack;
	for (int i = 0; i < m; i++)
	{
		while (!stopStack.empty() && stops[stopStack.back()].second >= stops[i].second)
		{
			nextLeq[stopStack.back()] = i;
			stopStack.pop_back();
		}
		stopStack.push_back(i);
	}
	
	ll answer = 0;
	
	int charge = n;
	for (int i = 0; i + 1 < m; i++)
	{
		//printf("at %d, charge %d, next <= at %d\n", stops[i].first, charge, nextLeq[i] != -1 ? stops[nextLeq[i]].first : -1);
		int add = 0;
		if (nextLeq[i] != -1 && stops[nextLeq[i]].first - stops[i].first <= n)
		{
			// fill to drive exactly there
			add = (stops[nextLeq[i]].first - stops[i].first) - charge;
		}
		else
		{
			// fill to drive max
			add = n - charge;
			add = min(add, d - stops[i].first - charge);
		}
		if (add < 0) add = 0;
		charge += add;
		answer += add * (ll)stops[i].second;
		//printf("bought %d (cost %d)\n", add, add * stops[i].second);
		
		charge -= stops[i + 1].first - stops[i].first;
		if (charge < 0)
		{
			printf("-1\n");
			return 0;
		}
	}
	
	cout << answer << endl;
	
	return 0;
}