#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
char str[1111111];
int v[1111111];
typedef unsigned long long ull;
const ull bas=125745721;
ull has[1111111],k[1111111],hat[1111111];
inline ull geth(int l,int r,ull*h)
{return h[r]-h[l-1]*k[r-l+1];}
int fir[1111111][33];
int n;
bool cmp(int l,int r)
{
	if(l==r)return 1;
	int cnt=0;
	register int i;
	for(i=1;i<=26;i++)
		if(fir[r][i]>fir[l-1][i])cnt++;
	if(cnt>=3)return 1;
	return str[l]!=str[r];
	//return geth(l,r,has)!=geth(n-r+1,n-l+1,hat);
}
void exec()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	int q;
	scanf("%d",&q);
	register int i;
	k[0]=1;
	for(i=1;i<=n;i++)
	{
		if(str[i]==str[i-1])v[i]=v[i-1];
		else v[i]=v[i-1]+1;
		has[i]=has[i-1]*bas+str[i];
		hat[i]=hat[i-1]*bas+str[n-i+1];
		k[i]=k[i-1]*bas;
		fir[i][str[i]-96]++;
		for(int ii=1;ii<=26;ii++)
			fir[i][ii]+=fir[i-1][ii];
	}
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(l==r)puts("Yes");
		else puts(cmp(l,r)?"Yes":"No");
	}
} 
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}
/*
Every little step contributes in constructing what is called the great.
*/