#include<bits/stdc++.h>
using namespace std;
int n,q,tt,a[2][100005];
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1,x,y;i<=q;i++)
	{
		scanf("%d%d",&x,&y);x--;
		if(a[x][y])tt-=a[x^1][y-1]+a[x^1][y]+a[x^1][y+1];
		else tt+=a[x^1][y-1]+a[x^1][y]+a[x^1][y+1];
		a[x][y]^=1;puts(tt||a[1][n]||a[0][1]?"No":"Yes");
	}
	return 0;
}