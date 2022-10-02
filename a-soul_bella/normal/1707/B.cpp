#include <bits/stdc++.h>
#define int long long
using namespace std;
pair<int,vector<int> > solve(int cnt,vector<int> v)
{
	int L=cnt+v.size();
	if(L==1) return {cnt,v};
	vector<int> nx;
	for(int i=1;i<v.size();i++) nx.push_back(v[i]-v[i-1]);
	if(cnt&&v.size()) nx.push_back(v[0]);
	sort(nx.begin(),nx.end());
	vector<int> V;
	for(auto t:nx)
		if(t) V.push_back(t);
	cnt=L-1-V.size();
	return solve(cnt,V);
}
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
		vector<int> v;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
		pair<int,vector<int> > x=solve(0,v);
		if(x.first) cout << "0\n";
		else cout << x.second[0] << "\n";
	}
	return 0;
}