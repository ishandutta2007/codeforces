#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((int)501*1000)

int n;
pair <int,int> a[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y,z,p;
		cin>>x>>y>>z>>p;
		a[i]={-x-y-z-p,i};
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
		if(a[i].second==0)
			return cout<<i+1<<"\n",0;
	return 0;
}