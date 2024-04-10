#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=205;

int n;
string a[N];
char ans[N];
vector<string> pos;
map<string, vector<int> > idx;

void check(int x)
{
	idx.clear();
	multiset<string> s;
	for(int i=1;i<=2*n-2;i++)
	{
		s.insert(a[i]);
		idx[a[i]].push_back(i);
	}
	string pref=pos[x];
	string suf=pos[x^1];
	while(pref.size())
	{
		if(s.find(pref)!=s.end())
		{
			ans[idx[pref].back()]='P';
			idx[pref].pop_back();
			s.erase(s.find(pref));
		}
		else
			break;
		pref.pop_back();
	}
	if(pref.size())
		return;
	while(suf.size())
	{
		if(s.find(suf)!=s.end())
		{
			ans[idx[suf].back()]='S';
			idx[suf].pop_back();
			s.erase(s.find(suf));
		}
		else
			break;
		reverse(suf.begin(), suf.end());
		suf.pop_back();
		reverse(suf.begin(), suf.end());
	}
	if(suf.size())
		return;
	for(int i=1;i<=2*n-2;i++)
		cout<<ans[i];
	exit(0);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=2*n-2;i++)
	{
		cin>>a[i];
		if(a[i].size()==n-1)
			pos.push_back(a[i]);
	}
	check(0);
	check(1);
	return 0;
}