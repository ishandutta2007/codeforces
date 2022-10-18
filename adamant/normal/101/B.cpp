#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() 
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int s[m], t[m];
	map<int, vector<int>> start, end;
	for(int i = 0; i < m; i++)
	{
		cin >> s[i] >> t[i];
		start[s[i]].push_back(i);
		end[t[i]].push_back(i);
	}
	end[0];
	multiset<pair<int, int>> good;
	int sum = 0;
	for(auto it = end.rbegin(); it != end.rend(); it++)
	{
		//if(it ->first <= 1)
		//cout << "! " << (*--good.end()).first  <<' ' << (*--good.end()).second << ' ' << it->first << "\n";
		while(good.size() && (*--good.end()).first > it->first)
		{
			sum -= (*--good.end()).second;
			sum = (sum + mod) % mod;
			good.erase(--good.end());
		}
		int tmp = 0;
		//cout << tmp << ' ' << it->first << "\n";
		for(auto jt: it->second)
		{
			good.insert({s[jt], sum + (it->first == n)});
			tmp += sum + (it->first == n);
			tmp %= mod;
		}
		sum += tmp;
		sum %= mod;
		if(it->first == 0)
			cout << sum << "\n";
	}
}