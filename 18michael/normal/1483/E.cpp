#include<bits/stdc++.h>
#define LL long long
#define Mx 50
#define inf 100000000000000LL
using namespace std;
int Test_num,t;
LL o,l,r,x,res;
LL f[Mx+2][Mx+2];
char s[12];
inline bool query(LL x)
{
	return printf("? %lld\n",x),fflush(stdout),scanf("%s",s),res+=(s[0]=='L'? x:-x),s[0]=='F';
}
inline void solve()
{
	for(o=res=1;o<=inf && !query(o);o<<=1);
	if(o==1)return (void)(puts("! 0"),fflush(stdout));
	l=(o>>1),r=min(o-1,inf);
	for(int i=t=1;;++i)
		if(f[i][1]>=r-l+1)
		{
			for(;i;--i)
			{
				for(t=max(t,1);res<=r-l+l*t;query(l));
				t+=((o=query(x=min(l+(t? f[i-1][t-1]:0)+1,r)))? -1:1);
				if(o)r=x-1;
				else l=x;
			}
			return (void)(printf("! %lld\n",l),fflush(stdout));
		}
}
int main()
{
	for(int i=1;i<=Mx;++i)f[1][i]=1;
	for(int i=2;i<=Mx;++i)for(int j=1;j<=Mx;++j)f[i][j]=f[i-1][j-1]+1+f[i-1][j+1];
	for(scanf("%d",&Test_num);Test_num--;)solve();
	return 0;
}