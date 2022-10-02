#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],b[200005];
vector <int> s[200005];
vector <int> v;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++) s[i].clear();
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			b[i]=a[i];
			s[a[i]].push_back(i);
		}
		set <int> S;
		for(int i=1;i<=n;i++) if(s[i].size()) S.insert(i);
		while(S.size())
		{
			v.clear();
			vector <int> V;
			for(auto t:S)
			{
				v.push_back(s[t].back());
				s[t].pop_back();
				if(s[t].empty()) V.push_back(t);
			}
			for(auto t:V) S.erase(t);
			for(int i=1;i<v.size();i++)
				swap(b[v[i-1]],b[v[i]]); 
		}
		for(int i=1;i<=n;i++)
			cout << b[i] << " ";
		cout << "\n";
	}
	return 0;
}