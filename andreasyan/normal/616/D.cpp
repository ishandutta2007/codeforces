#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1000006;

int n,m;
int a[N],b[N];
int ans,ansl,ansr;
int main()
{
	int i,j,k=0,l,r;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	l=0;
	r=-1;
	while(r<n)
	{
		if(k<=m)
		{
			if(r-l+1>ans)
			{
				ans=r-l+1;
				ansl=l;
				ansr=r;
			}
			++r;
			if(b[a[r]]==0)
				++k;
			++b[a[r]];
		}
		else
		{
			--b[a[l]];
			if(!b[a[l]])
				--k;
			++l;
		}
	}
	cout<<ansl+1<<' '<<ansr+1<<endl;
	return 0;
}