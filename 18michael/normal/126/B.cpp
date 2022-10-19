#include<cstdio>
#include<cstring>
int n,l=0,r=0,t=0,mx=0;
char s[1000002];
int z[1000002];
inline int min(int a,int b)
{
	return a<b? a:b;
}
inline int max(int a,int b)
{
	return a>b? a:b;
}
int main()
{
	scanf("%s",s),n=strlen(s);
	for(int i=1;i<n;++i)
	{
		if(i<=r)z[i]=min(z[i-l],r-i+1);
		while(i+z[i]<n && s[z[i]]==s[i+z[i]])++z[i];
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
	for(int i=1;i<n;++i)
	{
		if(i+z[i]==n && mx>=z[i])
		{
			for(int j=0;j<z[i];++j)printf("%c",s[j]);
			return 0;
		}
		mx=max(mx,z[i]);
	}
	return 0&puts("Just a legend");
}