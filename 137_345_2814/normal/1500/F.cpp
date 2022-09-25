#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
#define N 1006000
#define ll long long
int n;
ll v[N],fg,l,r,as[N],ls,v1,v2,vl[N],s1[N];
set<ll> st;
int main()
{
	scanf("%d%*lld",&n);
	fg=1,l=0,r=1e18;v1=1;
	for(int i=1;i<n-1;i++)
	{
		scanf("%lld",&v[i]);
		if(fg&&l<=v[i]&&r>=v[i])
		{
			ll nw=v[i];
			for(int j=i;j>ls;j--)as[j]=nw,nw=v[j-1]-nw;
			ls=i;l=0;r=v[i];fg=1;st.clear();v1=1;v2=0;
			continue;
		}
		else if(fg)fg&=l<=v[i],l=v[i]-l,r=v[i]-r,swap(l,r),l=max(l,0ll);
		if(fg)vl[i]=v[i]-l;
		while(!st.empty()&&v1*(*st.begin())+v2>v[i])st.erase(*st.begin());
		while(!st.empty()&&v1*(*st.rbegin())+v2>v[i])st.erase(*st.rbegin());
		if(st.size())vl[i]=v1*(*st.begin())+v2;
		if(st.find((v[i]-v2)/v1)!=st.end())
		{
			ll nw=v[i];
			for(int j=i;j>ls;j--)
			{
				as[j]=nw,nw=v[j-1]-nw;
				if(!nw)nw=vl[j-1];
			}
			ls=i;l=0;r=v[i];fg=1;st.clear();v1=1;v2=0;
			continue;
		}
		v1*=-1;v2=v[i]-v2;
		if(!fg&&!st.size()){printf("NO\n");return 0;}
		st.insert((v[i]-v2)/v1);
	}
	if(fg)as[n-1]=l;else as[n-1]=v1*(*st.begin())+v2;
	for(int i=n-2;i>ls;i--)
	{
		as[i]=v[i]-as[i+1];
		if(!as[i])as[i]=vl[i];
	}
	int fg=1;
	for(int i=1;i<n;i++)
	{
		s1[i+1]=s1[i]+fg*as[i];
		if(i>1&&fg*(s1[i+1]-s1[i-1])>v[i-1])fg*=-1,s1[i+1]=s1[i]+fg*as[i];
	}
	printf("YES\n");
	ll mn=0;for(int i=1;i<=n;i++)mn=min(mn,s1[i]);
	for(int i=1;i<=n;i++)printf("%lld ",s1[i]-mn);
}