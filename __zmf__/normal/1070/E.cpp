#include<bits/stdc++.h>
using namespace std;
long long a,b,c,T,d[1000001],v[1000001],o,h[500001],u[1000001],cn,ans,fl;
struct p
{
	long long q,w;
}l[1000001];
void add(long long qq,long long ww)
{
	l[++o].q=ww;
	l[o].w=h[qq];
	h[qq]=o;
}
bool ch(long long qq)
{
	cn=0;
	for(int i=1;i<=a;i++)
	{
		if(d[i]<=qq)
		{
			u[++cn]=d[i];
		}
	}
	long long an=0;
	for(int i=1;i<=cn;i++)
	{
		long long tt=0;
		for(int j=i;j<i+b&&j<=cn;j++)
		{
			an+=u[j];tt+=u[j];
			if(an>c) return false;
		}
		an+=tt;
		i=i+b-1;
	}
	return true;
}
int main()
{
	scanf("%lld",&T);
	for(int ii=1;ii<=T;ii++)
	{
		fl=1;
		long long yy=0;
		scanf("%lld%lld%lld",&a,&b,&c);
		for(int i=1;i<=a;i++)
		{
			scanf("%lld",&d[i]);
		}
//		ch(5);return 0;
		long long ll=1,rr=c,an=0;
		while(ll<=rr)
		{
			long long mid=((ll+rr)>>1);
			if(ch(mid))
			{
				an=mid;
				ll=mid+1;
			}
			else rr=mid-1;
		}
//		cout<<an;return 0;
		cn=0;
		for(int i=1;i<=a;i++)
		{
			if(d[i]<=an)
			{
				u[++cn]=d[i];
			}
		}
		long long ann=0;fl=1;
		for(int i=1;i<=cn;i++)
		{
			long long tt=0;
			for(int j=i;j<i+b&&j<=cn;j++)
			{
				ann+=u[j];tt+=u[j];
				if(ann>c)
				{fl=0;
					yy=j-1;break;
				}
			}
			if(!fl) break;
			ann+=tt;i=min(i+b-1,cn);
			if(ann>c)
			{
				yy=i;break;
			}
		}
		if(ann<=c) yy=cn;
		ans=an;
//		cout<<ans<<" "<<yy<<"\n";return 0;
		cn=0;an++;fl=1;
		for(int i=1;i<=a;i++)
		{
			if(d[i]<=an)
			{
				u[++cn]=d[i];
			}
		}ann=0;fl=1;
//		cout<<ans<<" "<<yy<<"\n";
		for(int i=1;i<=cn;i++)
		{
			long long tt=0;
			for(int j=i;j<i+b&&j<=cn;j++)
			{
				ann+=u[j];tt+=u[j];
//				cout<<ann<<" "<<c<<" "<<tt<<"\n";
				if(ann>c)
				{fl=0;
					if(j-1>yy) yy=j-1,ans=an;
					break;
				}
			}
			if(!fl) break;
			ann+=tt;i=min(i+b-1,cn);
//			cout<<ann<<" "<<c<<" "<<yy<<"\n";
			if(ann>c)
			{
				if(i>yy) yy=i,ans=an;
				break;
			}
		}
		if(fl&&ann<=c&&cn>yy) yy=cn,ans=an;
		cn=0;an-=2;fl=1;
		for(int i=1;i<=a;i++)
		{
			if(d[i]<=an)
			{
				u[++cn]=d[i];
			}
		}ann=0;
		for(int i=1;i<=cn;i++)
		{
			long long tt=0;
			for(int j=i;j<i+b&&j<=cn;j++)
			{
				ann+=u[j];tt+=u[j];
				if(ann>c)
				{fl=0;
					if(j-1>yy) yy=j-1,ans=an;
					break;
				}
			}
			if(!fl) break;
			ann+=tt;i=min(i+b-1,cn);
			if(ann>c)
			{
				if(i>yy) yy=i,ans=an;
				break;
			}
		}
		if(fl&&ann<=c&&cn>yy) yy=cn,ans=an;
		printf("%lld %lld\n",yy,ans);
	}
	return 0;
}