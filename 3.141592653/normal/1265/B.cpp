#include<cstdio>
#include<cstring>
int n;
int a[1111111],l[1111111],r[1111111],pos[1111111];
int main()
{
	int T; 
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		register int i;
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]),pos[a[i]]=i,l[i]=0;
		l[n+1]=0;
		int tot=0;
		for(i=1;i<=n;i++)
		{
			int t=pos[i];
			if(l[t-1])tot--;
			if(l[t+1])tot--;
			tot++,l[t]=1;
			if(tot==1)putchar('1');
			else putchar('0');
		}puts("");
	}
}
/*
All things passing through, leaving me behind.
Where is your fighting heart, std?
*/