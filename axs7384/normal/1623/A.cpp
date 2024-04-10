#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,xx,yy;
int t;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&xx,&yy);
		int tx=xx-x;
		if (tx<0)
			tx=2*n-x-xx;
		int ty=yy-y;
		if (ty<0)
			ty=2*m-y-yy;
		printf("%d\n",min(tx,ty));
	}
	return 0;
}