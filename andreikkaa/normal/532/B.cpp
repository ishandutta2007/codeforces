#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<long long> w;
vector<vector<int> > gr;


bool SORT(pair<long long, long long> a, pair<long long, long long> b)
{
	if (a.second - a.first < b.second - b.first)
		return true;
	return false;
}

pair<long long, long long> dfs(int v)
{
	if (gr[v].empty())
		return make_pair(w[v], 0);
	vector<pair<long long, long long> > get(gr[v].size());
	for (size_t i = 0; i < gr[v].size(); i++)
		get[i] = dfs(gr[v][i]);
	sort(get.begin(), get.end(), SORT);
	long long summ = 0;
	for (size_t i = 0; i < get.size(); i++)
		summ += get[i].second;
	long long summ1 = summ - get[0].second + get[0].first;
	for (int i = 0; i < get.size() - 1; i += 2)
	{
		if (get[i].first + get[i + 1].first > get[i].second + get[i + 1].second)
		{
			summ -= (get[i].second + get[i + 1].second);
			summ += (get[i].first + get[i + 1].first);
		}
		else
			break;
	}
	for (int i = 1; i < get.size() - 1; i += 2)
	{
		if (get[i].first + get[i + 1].first > get[i].second + get[i + 1].second)
		{
			summ1 -= (get[i].second + get[i + 1].second);
			summ1 += (get[i].first + get[i + 1].first);
		}
		else
			break;
	}
	return make_pair(max(summ + w[v], summ1), summ);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> n;
	w.resize(n);
	gr.resize(n);
	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p >> w[i];
		if (p != -1)
			gr[p - 1].push_back(i);
	}
	pair<long long, long long> ans = dfs(0);
	cout << max(ans.first, ans.second) << endl;
	return 0;
}