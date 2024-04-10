#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL vec_t=0,n,m,k,t,t1,len,ans,res,v;
LL a[5000002],b[5000002],to[10000002]={},vec[5000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
struct aaa
{
	LL x,y;
};
inline LL gcd(LL a,LL b)
{
	return b? gcd(b,a%b):a;
}
inline aaa exgcd(LL a,LL b,LL c)
{
	if(!b)
	{
		if(a>0)return (aaa){c,0};
		return (aaa){-c,0};
	}
	aaa d=exgcd(b,a%b,c);
	return (aaa){d.y%len,(d.x-a/b*d.y)%len};
}
inline LL CRT(LL x,LL y)
{
	if((x%t)!=(y%t))return 0;
	ans=x,res=n,y=(((y-ans)%len)+len)%len,t1=gcd(gcd(res,m),y);
	ans=(((y+ans+m*exgcd(res/t1,-m/t1,y/t1).y)%len)+len-1)%len+1;
	return ans;
}
int main()
{
	read(n),read(m),read(k),t=gcd(n,m),len=n/t*m;
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=m;++i)read(b[i]),to[b[i]]=i;
	for(int i=1,j;i<=n;++i)if(to[a[i]] && (v=CRT(i,to[a[i]])))vec[++vec_t]=v;
	sort(vec+1,vec+vec_t+1),ans=(k-1)/(len-vec_t)*len,k=(k-1)%(len-vec_t)+1;
	for(int i=1;i<=vec_t;++i){if(k<vec[i])break;++k;}
	ans+=k,printf("%lld",ans);
	return 0;
}