#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=1000000007;
typedef long double lb;
int n,d,t,i,a[10005],s;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&d);
		s=0;
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			while(d>=i-1&&a[i])
			{
				--a[i];
				d-=i-1;
				++s;
			}
		}
		cout<<s<<endl;
	}
}