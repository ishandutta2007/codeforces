#include<cstdio>
#include<algorithm>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
LL n,A,R,M,B,C,T1,T2;
LL H,H1=0,H2=0,ans=inf,res;
LL h[100002];
inline bool cmp(LL a,LL b)
{
	return a<b? 1:0;
}
inline LL min(LL a,LL b)
{
	return a<b? a:b;
}
int main()
{
	scanf("%lld%lld%lld%lld",&n,&A,&R,&M);
	for(int i=1;i<=n;++i)scanf("%lld",&h[i]),H2+=h[i];
	T1=H2/n,T2=(H2-1)/n+1,H=H2,sort(h+1,h+n+1,cmp);
	for(int i=0;i<n;++i)
	{
		H1+=h[i],H2-=h[i];
		if(h[i]<=T1 && T1<=h[i+1])
		{
			B=i*T1-H1,C=H2-(n-i)*T1;
			if(B<C)res=B*M+(C-B)*R;
			else res=C*M+(B-C)*A;
			ans=min(ans,res);
		}
		if(h[i]<=T2 && T2<=h[i+1])
		{
			B=i*T2-H1,C=H2-(n-i)*T2;
			if(B<C)res=B*M+(C-B)*R;
			else res=C*M+(B-C)*A;
			ans=min(ans,res);
		}
	}
	H1=0,H2=H;
	for(int i=1;i<=n;++i)
	{
		H1+=h[i],H2-=h[i],B=i*h[i]-H1,C=H2-(n-i)*h[i],ans=min(ans,B*A+C*R);
		if(B<C)res=B*M+(C-B)*R;
		else res=C*M+(B-C)*A;
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}