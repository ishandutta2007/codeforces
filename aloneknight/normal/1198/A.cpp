#include <bits/stdc++.h>
using namespace std;
int n,I,p=1,a[400005];
int main()
{
	scanf("%d%d",&n,&I);I=I*8/n;
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
	for(;I>0&&p<=1e7;I--)p*=2;
	int x=1,c=1,v=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i-1])c++;
		if(c>p)
		{
			while(a[v]==a[v+1]&&v<n-1)v++;
			v++,c--;
		}
		x=max(x,i-v+1);
	}
	printf("%d\n",n-x);
	return 0;
}