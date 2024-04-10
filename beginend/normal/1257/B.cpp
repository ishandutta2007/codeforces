#include<bits/stdc++.h>

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		int x,y;scanf("%d%d",&x,&y);
		if (x>3) puts("YES");
		else if (y<=x||x>1&&y<=3) puts("YES");
		else puts("NO");
	}
	return 0;
}