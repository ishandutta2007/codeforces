#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n;
int a[N], b[N];
vector<int> p, q;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	for(int i=0;i<n;i++)
	{
		if(a[i]==1)
		{
			for(int j=i;j<n+i;j++)
				if(a[j%n]>0)
					p.push_back(a[j%n]);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(b[i]==1)
		{
			for(int j=i;j<n+i;j++)
				if(b[j%n]>0)
					q.push_back(b[j%n]);
		}
	}
	if(p==q)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}