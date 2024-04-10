#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], f[N];
vector<int> v;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]++;
	}	
	for(int i=1;i<=5000;i++)
	{
		if(f[i]>0)
		{
			f[i]--;
			v.push_back(i);
		}
	}
	for(int i=5000;i>=1;i--)
	{
		if(f[i]>0 && i!=v.back())
		{
			f[i]--;
			v.push_back(i);
		}
	}
	cout<<v.size()<<endl;
	for(auto &it:v)
		cout<<it<<" ";
	return 0;
}