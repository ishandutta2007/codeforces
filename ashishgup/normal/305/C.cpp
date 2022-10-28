#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, cur=0, curmax=0, have=0;
int a[N];
map<int, int> m;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
	}
	for(auto &it:m)
	{
		curmax=max(it.first, curmax);
		cur=it.second/2;
		it.second%=2;
		have+=(it.second==1);
		if(cur>=1)
			m[it.first+1]+=cur;
	}
	cout<<curmax-have+1;
	return 0;
}