#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define N 100500
int n,m,s,t,v[N],v2[N],g;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int exgcd(int a,int b,long long &x,long long &y){if(!b){x=1,y=0;return a;}int g=exgcd(b,a%b,y,x);y-=a/b*x;return g;}
int getinv(int a,int p){long long x,y;exgcd(a,p,x,y);return (x%p+p)%p;}
struct sth{int a,t;friend bool operator <(sth a,sth b){return a.a==b.a?a.t>b.t:a.a<b.a;}};
struct que{
	vector<sth> t1,t2;
	void add1(int x,int a){if(x==1)t1.push_back((sth){(int)(1ll*a*getinv(m,n)%(n/g)),-1});else t2.push_back((sth){(int)(1ll*a*getinv(n,m)%(m/g)),-1});}
	void add2(int x,int a,int t){if(x==1)t1.push_back((sth){(int)(1ll*a*getinv(m,n)%(n/g)),t});else t2.push_back((sth){(int)(1ll*a*getinv(n,m)%(m/g)),t});}
	long long solve()
	{
		int s1=t1.size(),s2=t2.size(),las,last;
		long long as=0;
		if(!s1)return -1;
		las=-1,last=0;
		sort(t1.begin(),t1.end());
		for(int i=0;i<s1;i++)
		{
			if(las!=-1)
			{
				if(t1[i].a!=(t1[i==0?s1:i-1].a+1)%(n/g)&&t1[i].a!=(t1[i==0?s1:i-1].a)%(n/g))
				{
					long long su=1ll*(t1[i].a-las-1)*m+last;
					if(su>as)as=su;//printf("%lld\n",su);
				}
			}
			if(t1[i].t!=-1)las=t1[i].a,last=t1[i].t;
			}
			for(int i=0;i<s1;i++)
			{
				if(t1[i].a!=(t1[i==0?s1:i-1].a+1)%(n/g)){
				long long su=1ll*(t1[i].a+n/g-las-1)*m+last;
				if(su>as)as=su;//printf("%lld\n",su);
				}
			if(t1[i].t!=-1)break;
		}
		if(!s2)return -1;
		las=-1,last=0;
		sort(t2.begin(),t2.end());
		for(int i=0;i<s2;i++)
		{
			if(las!=-1)
			{
				if(t2[i].a!=(t2[i==0?s2:i-1].a+1)%(m/g)&&(t2[i].a!=(t2[i==0?s2:i-1].a)%(m/g)))
				{
					long long su=1ll*(t2[i].a-las-1)*n+last;
					if(su>as)as=su;//printf("%lld\n",su);
				}
			}
			if(t2[i].t!=-1)las=t2[i].a,last=t2[i].t;
		}
		for(int i=0;i<s2;i++)
		{
			if(t2[i].a!=(t2[i==0?s2:i-1].a+1)%(m/g)){
			long long su=1ll*(t2[i].a+(m/g)-las-1)*n+last;
			if(su>as)as=su;//printf("%lld\n",su);
			
			}
			if(t2[i].t!=-1)break;
		}
		return as;
	}
}tp[N];
map<int,int> tp1,tp2;
int main()
{
	scanf("%d%d",&n,&m);
	g=gcd(n,m);
	if(g>200000){printf("-1\n");return 0;}
	scanf("%d",&s);for(int i=1;i<=s;i++)scanf("%d",&v[i]),tp1[v[i]]=1;
	scanf("%d",&t);for(int i=1;i<=t;i++)scanf("%d",&v2[i]),tp2[v2[i]]=1;
	int la=0,lb=0;
	for(int i=0;i<=234567;i++)
	{
		if(tp1.size()+tp2.size()==n+m){printf("%d\n",i==0?0:i-1);return 0;}
		if(tp1.count(la)||tp2.count(lb))tp1[la]=tp2[lb]=1;
		la=(la+1)%n;lb=(lb+1)%m;
	}
	for(int i=1;i<=s;i++)
	{
		int s1=v[i]/g;
		tp[v[i]%g].add1(1,s1);
		tp[v[i]%g].add2(2,s1%(m/g),v[i]);
		tp[v[i]%g].add2(1,(s1+m/g)%(n/g),v[i]+m);
	}
	for(int i=1;i<=t;i++)
	{
		int s1=v2[i]/g;
		tp[v2[i]%g].add1(2,s1);
		tp[v2[i]%g].add2(1,s1%(n/g),v2[i]);
		tp[v2[i]%g].add2(2,(s1+n/g)%(m/g),v2[i]+n);
	}
	long long mn=0;
	for(int i=0;i<g;i++)
	{
		long long t1=tp[i].solve();
		if(t1==-1){printf("-1\n");return 0;}
		if(mn<t1)mn=t1;
	}
	printf("%lld\n",mn);
}