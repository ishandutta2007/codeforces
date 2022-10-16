#include <bits/stdc++.h>
using namespace std;
int main() 
{
    string s;
    int k,n;
	cin >> s >> k;
	n = int(s.size());
	if (k > (n * (n+1LL)) / 2)
	{
		cout << "No such line."<<endl;
		return 0;
	}
	set<pair<string, int>> hola;
	for (int i = 0; i < n; i++) 
	{
		string t(1, s[i]);
		hola.insert(make_pair(t, i));
	}
	for (int i = 0; i < k-1; i++) 
	{
		auto u = *hola.begin();
		hola.erase(hola.begin());
		if (u.second + 1 < n)
			hola.insert(make_pair(u.first+s[u.second + 1], u.second + 1));
	}
	auto u = *hola.begin();
	cout << (*hola.begin()).first<<endl;
	return 0;
}