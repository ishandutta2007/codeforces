#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

double dis(int x,int y)
{
	return sqrt(x*x+y*y);
}

int main()
{
	int r,d,n;
	scanf("%d%d",&r,&d);
	scanf("%d",&n);
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if (dis(x,y)>=(double)(z+r-d)&&dis(x,y)+(double)z<=(double)r) ans++;
	}
	cout<<ans;
	return 0;
}