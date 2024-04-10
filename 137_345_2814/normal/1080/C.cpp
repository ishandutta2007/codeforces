#include<cstdio>
#include<algorithm>
using namespace std;
long long t,n,m,a,b,c,d,e,f,g,h;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld",&n,&m,&a,&b,&c,&d,&e,&f,&g,&h);
		long long s11=min(c,g)-max(a,e)+1;
		long long s21=min(d,h)-max(b,f)+1;
		long long tmp;
		if(s11<0||s21<0)
		tmp=0;
		else
		tmp=s11*s21;
		long long ans1=(c-a+1)*(d-b+1)-tmp;
		long long ans2=(g-e+1)*(h-f+1);
		ans1+=n*m-n*m/2;
		ans2+=n*m/2;
		long long s1=max(a,e),s2=max(b,f),s3=min(c,g),s4=min(d,h);
		ans1-=(c-a+1)*(d-b+1)/2;
		ans2-=(c-a+1)*(d-b+1)/2;
		ans1-=(g-e+1)*(h-f+1)/2;
		ans2-=(g-e+1)*(h-f+1)/2;
		{
		if(!(s11<0||s21<0))
		ans1+=(s3-s1+1)*(s4-s2+1)/2,ans2+=(s3-s1+1)*(s4-s2+1)/2;
		}
		if((c-a)%2==0&&(d-b)%2==0)
		{
		if((a+b)&1)ans2--;
		else ans1--;
		}
		if((g-e)%2==0&&(h-f)%2==0)
		{
		if((f+e)&1)ans2--;
		else ans1--;
		}
		if(!(s11<0||s21<0))
		if((s3-s1)%2==0&&(s4-s2)%2==0)
		if((s1+s2)&1)ans2++;
		else ans1++;
		printf("%lld %lld\n",ans1,ans2);
	}
}