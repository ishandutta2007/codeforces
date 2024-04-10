#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=8e5+5;

int n, ctr=0;
int a[N], l[N], r[N], prv[N];
map<int, int> m;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		m[l[i]];
		m[r[i]];
		m[r[i]+1];
	}
	for(auto &it:m)
		it.second=++ctr;
	for(int i=1;i<=n;i++)
	{
		a[m[l[i]]]++;
		a[m[r[i]+1]]--;
	}
	for(int i=1;i<N;i++)
	{
		a[i]+=a[i-1];
		if(a[i]<2)
			prv[i]=i;
		else
			prv[i]=prv[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		if(prv[m[r[i]]]<m[l[i]])
		{
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}