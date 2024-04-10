#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, k;
int a[N], vis[N];
vector<int> v;

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!vis[a[i]])
		{
			vis[a[i]]=1;
			v.push_back(i);
		}
	}
	if(v.size()<k)
		cout<<"NO";
	else
	{
		cout<<"YES"<<endl;
		for(int i=0;i<k;i++)
			cout<<v[i]<<" ";
	}
	return 0;
}