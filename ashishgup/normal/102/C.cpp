#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

string s;
int k;
map<char, int> m;
vector<pair<int, char> > v;

int32_t main()
{
	IOS;
	cin>>s>>k;
	for(auto &it:s)
		m[it]++;
	for(auto &it:m)
		v.push_back({it.second, it.first});
	sort(v.begin(), v.end());
	set<char> erased;
	for(auto &it:v)
	{
		if(k-it.first>=0)
		{
			erased.insert(it.second);
			k-=it.first;
		}
		else
			break;
	}
	cout<<m.size()-erased.size()<<endl;
	for(auto &it:s)
	{
		if(erased.find(it)==erased.end())
			cout<<it;
	}
	return 0;
}