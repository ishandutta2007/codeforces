#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
string s;
map<char, int> m;
string ans;

int32_t main()
{
	IOS;
	cin>>s;
	n=s.size();
	for(auto &it:s)
		m[it]++;
	deque<char> d;
	for(auto &it:m)
	{
		int cur=it.second/2;
		it.second%=2;
		for(int i=1;i<=cur;i++)
			ans+=it.first;
		if(it.second==1)
			d.push_back(it.first);
	}
	while(d.size()>=2)
	{
		ans+=d.front();
		d.pop_front();
		d.pop_back();
	}
	sort(ans.begin(), ans.end());
	string rev=ans;
	reverse(rev.begin(), rev.end());
	if(d.size())
		ans+=d.front();
	ans+=rev;
	cout<<ans;
	return 0;
}