#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=4e5+5;

int n, ans=0, cnt=0;
int a[N], b[N];
vector<int> m[20];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		m[a[i]].push_back(b[i]);
	}
	for(auto &it:m)
		sort(it.begin(), it.end());
	for(auto &it:m[11])
	{
		ans+=it;
		cnt++;
	}
	while(m[01].size() && m[10].size())
	{
		ans+=m[01].back();
		m[01].pop_back();
		ans+=m[10].back();
		m[10].pop_back();
	}
	vector<int> v;
	for(auto &it:m[00])
		v.push_back(it);
	for(auto &it:m[01])
		v.push_back(it);
	for(auto &it:m[10])
		v.push_back(it);
	sort(v.begin(), v.end());
	while(v.size() && cnt>0)
	{
		ans+=v.back();
		v.pop_back();
		cnt--;
	}
	cout<<ans;
	return 0;
}