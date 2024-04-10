#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int w,n,m,Mx,Mx2,ans;
LL res;
int pw[14],to[4096],cnt[531441];
char s[14];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL calc(char c,bool o)
{
	switch(c)
	{
		case 'A':return o? 0:2;
		case 'O':return o? inf:0;
		case 'X':return o? 1:0;
		case 'a':return o? 1:inf;
		case 'o':return o? 2:1;
		case 'x':return o? 0:1;
	}
}
int main()
{
	read(w),read(n),read(m),pw[0]=1;
	for(int i=1;i<=w;++i)pw[i]=pw[i-1]*3;
	Mx=pw[w],Mx2=(1<<w);
	for(int i=0,x;i<Mx2;to[i]=x,++i)for(int j=x=0;j<w;++j)x+=((i>>j)&1)*pw[j];
	for(int i=1,x;i<=n;++i)scanf("%d",&x),++cnt[to[x]];
	for(int i=0;i<Mx;++i)
		for(int j=0,x=i;j<w;x/=3,++j)
			if(x%3==2)
			{
				cnt[i]=cnt[i-pw[j]]+cnt[i-pw[j]*2];
				break;
			}
	for(;m--;printf("%d\n",ans))
	{
		scanf("%s",s),res=0;
		for(int i=0;i<w-1-i;++i)swap(s[i],s[w-1-i]);
		for(int i=0;i<w;++i)res+=calc(s[i],0)*pw[i];
		ans=cnt[to[0]]*(res<Mx? cnt[res]:0);
		for(int i=1;i<Mx2;ans+=cnt[to[i]]*(res<Mx? cnt[res]:0),++i)for(int j=0,x=(i^(i-1));j<w && x;x>>=1,++j)res+=(calc(s[j],x==1)-calc(s[j],x>1))*pw[j];
	}
	return 0;
}