#include<cstdio>
#define Mx 16777215
int n,ans=0;
int f[16777216];
char s[3];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%s",s),++f[(((1<<(s[0]-'a'))|(1<<(s[1]-'a'))|(1<<(s[2]-'a')))&Mx)^Mx];
	for(int i=1;i<Mx;i<<=1)
		for(int j=0;j<=Mx;j+=(i<<1))
			for(int k=0;k<i;++k)
				f[j+k]+=f[i+j+k];
	for(int i=0;i<=Mx;++i)ans^=(n-f[i])*(n-f[i]);
	return 0&printf("%d",ans);
}