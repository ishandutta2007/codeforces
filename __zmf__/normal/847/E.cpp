#include<bits/stdc++.h>
using namespace std;
long long a,b,an,v[100005],d[100005],cn;
char s[100005];
bool ch(long long qq)
{
	memset(v,0,sizeof(v));
	long long ll=1,fl=1;
	for(int i=1;i<=a;i++)
	{
		if(s[i]=='P')
		{
			long long tt=qq;
			if(i<d[ll])
			{
				ll=max(ll,(long long)(upper_bound(d,d+cn+1,i+tt)-d));
				if(ll>cn) return true;
				continue;
			}
			tt-=i-d[ll];
			if(tt<0)
			{
				fl=0;break;
			}
			long long gg=ll;
			ll=max(upper_bound(d,d+cn+1,max((long long)(i),d[ll]+tt))-d,upper_bound(d,d+cn+1,i+tt/2)-d);
			if(ll>cn) return true;
		}
	}
	if(ll<=cn) return false;
	return true;
}
int main()
{
	scanf("%lld",&a);
	scanf("%s",s+1);
	for(int i=1;i<=a;i++) if(s[i]=='*') d[++cn]=i;
//	cout<<ch(2);return 0;
	long long ll=0,rr=a*2;
	while(ll<=rr)
	{
		long long mid=((ll+rr)>>1);
		if(ch(mid))
		{
			an=mid;
			rr=mid-1;
		}
		else ll=mid+1;
	}
	printf("%lld",an);
	return 0;
}
//10
//**P**P**P*