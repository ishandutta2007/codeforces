#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n;
int a[N], b[N], x[N];

int check(int k)
{
	for(int i=1;i<=n;i++)
		b[i]=a[i];
	for(int i=0;i<k;i++)
		x[i]=a[i+1]-a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1] + x[(i-1+k)%k])
			return 0;
	}
	return 1;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		if(check(i))
			v.push_back(i);
	}
	cout<<v.size()<<endl;
	for(auto &it:v)
		cout<<it<<" ";
	return 0;
}