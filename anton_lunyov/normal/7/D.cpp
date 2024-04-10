#include <stdio.h>
#include <string.h>

#define N 10101010

char s[N];
int z[N],f[N];
int n,k,l,r;

void update(int beg)
{
	int i;
	for(i=beg;i+k<2*n && s[i]==s[i+k];i++);
	if(i>0)	z[k]=i,l=k,r=k+i-1;
}

int main()
{
	while(gets(s))
	{
		n=strlen(s);
		int i;
		for(i=0;i<n;i++) s[i+n]=s[n-i-1];
		for(l=r=0,k=1;k<2*n;k++)
		{
			z[k]=0;
			if(r-k<0) update(0); else
			if(z[k-l]<r-k) z[k]=z[k-l]; else update(r-k);
		}
		int ans=1;
		f[0]=1;
		for(i=1;i<n;i++)
		{
			f[i]=0;
			if(z[2*n-1-i]==i+1)
			{
				f[i]=f[(i-1)/2]+1;
				ans+=f[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}