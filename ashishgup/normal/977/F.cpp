#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, elem, len=0;
int a[N];
map<int, int> ans, index;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans[a[i]]=ans[a[i]-1]+1;
		if(ans[a[i]]>len)
		{
			len=ans[a[i]];
			elem=a[i];
		}
	}
	cout<<len<<endl;
	elem=elem-len+1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==elem)
		{
			cout<<i<<" ";
			elem++;
		}
	}
	return 0;
}