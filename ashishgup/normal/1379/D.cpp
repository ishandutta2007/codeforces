#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int n, h, m, k;
map<int, vector<int> > events;
 
int32_t main()
{
	IOS;
	cin >> n >> h >> m >> k;
	for(int i = 1; i <= n; i++)
	{
		int hh, mm;
		cin >> hh >> mm;
		if(mm >= m / 2)
			mm -= m / 2;
		events[mm].push_back(i);
		events[mm + m / 2].push_back(i);
		events[mm + m].push_back(i);
		for(int j = -1; j <= 1; j++)
		{
			for(int add = 0; add <= 2; add++)
			{
				events[mm + j + add * m / 2];
				events[mm + k + j + add * m / 2];
			}
		}
	}
	int prv = 0, mn = n, active = 0, bestT = k;
	for(auto &it:events)
	{
		if(it.first > m)
			break;
		if(events.count(it.first - k))
			active -= events[it.first - k].size();
		if(active < mn && it.first >= k)
		{
			bestT = it.first;
			mn = active;
		}
		active += it.second.size();
	}
	vector<int> rem;
	for(auto &it:events)
	{
		if(it.first < bestT && it.first > bestT - k)
			for(auto &elem:it.second)
				rem.push_back(elem);
	}
	while(bestT >= m / 2)
		bestT -= m / 2;
	cout << mn << " " << bestT << endl;
	for(auto &it:rem)
		cout << it << " ";
	return 0;
}