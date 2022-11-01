#include<bits/stdc++.h>

int query(int x)
{
	int ans=x;
	for (int i=1;i*i<=x*2;i++)
	{
		ans=std::min(ans,i-1+(x+i-1)/i);
	} 
	return ans;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		int n,d;
		scanf("%d%d",&n,&d);
		if (query(d)<=n) puts("YES");
		else puts("NO");
	}
	return 0;
}