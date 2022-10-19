#include<bits/stdc++.h>
#define LL long long
using namespace std;
int m,k,t,a,b,c,ans;
LL res=0,res1=0,res2=0;
LL sum[1002]={};
LL p[1002][1002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(m),read(k);
	for(int i=1;i<=k;++i)
		for(int j=1;j<=m;++j)
			read(p[i][j]),sum[i]+=p[i][j];
	for(int i=3;i<=k;++i)
		if(!(sum[2]-sum[1]) || ((sum[i]-sum[1])%(sum[2]-sum[1])) || (sum[i]-sum[1])/(sum[2]-sum[1])!=(i-1))
		{
			if(!t)t=i;
			else
			{
				if(sum[4]-sum[3]==sum[3]-sum[2])t=1;
				else t=2;
				break;
			}
		}
	if(t>3)a=1,b=2,c=3,res2=2*sum[t-1]-sum[t-2];else a=k-2,b=k-1,c=k,res2=2*sum[t+1]-sum[t+2];
	for(int i=1;i<=m;++i)res+=p[a][i]*p[a][i]+p[c][i]*p[c][i]-2*p[b][i]*p[b][i],res1+=p[t][i]*p[t][i];
	if(t>3)for(int i=1;i<=m;++i)res+=2*p[t-1][i]*p[t-1][i]-p[t-2][i]*p[t-2][i];
	else for(int i=1;i<=m;++i)res+=2*p[t+1][i]*p[t+1][i]-p[t+2][i]*p[t+2][i];
	for(int i=1;i<=m;++i)
		if(res1-p[t][i]*p[t][i]+(res2-(sum[t]-p[t][i]))*(res2-(sum[t]-p[t][i]))==res)
		{
			ans=res2-(sum[t]-p[t][i]);
			break;
		}
	printf("%d %d",t-1,ans),fflush(stdout);
	return 0;
}