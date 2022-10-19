#include<cstdio>
#include<cstring>
#define eps 1e-9
int len=0,len1;
double l=0,r=100,mid;
char s[2000002],s1[1000002];
double f[2000002][2];
inline double max(double x,double y)
{
	return x>y? x:y;
}
inline bool check(double x)
{
	f[0][0]=0,f[0][1]=-x;
	for(int i=1;i<=len;++i)
	{
		f[i][0]=f[i-1][1]+(s[i]=='R')-x;
		f[i][1]=f[i-1][0]+(s[i]=='L')-x;
		f[i][0]=max(f[i][0],f[i][1]-x);
		f[i][1]=max(f[i][1],f[i][0]-x);
	}
	return f[len][0]>=0;
}
int main()
{
	scanf("%s",s1+1),len1=strlen(s1+1);
	if(s1[1]=='R' && s1[len1]=='R')s[++len]='X';
	s[++len]=s1[1];
	for(int i=2;i<=len1;++i)
	{
		if(s1[i]!='X' && s1[i]==s1[i-1])s[++len]='X';
		s[++len]=s1[i];
	}
	if(s1[1]=='L' && s1[len1]=='L')s[++len]='X';
	while(r-l>eps)
	{
		mid=(l+r)/2;
		if(check(mid/100))l=mid;
		else r=mid;
	}
	return 0&printf("%.6lf",(int)(r*1000000)/1000000.0);
}