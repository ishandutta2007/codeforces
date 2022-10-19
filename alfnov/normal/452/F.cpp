#include<bits/stdc++.h>
#define ull unsigned long long 
using namespace std;
struct apple
{
	int x,wz;
	bool operator<(const apple &other)const
	{
		return x<other.x;
	}
}e[300005];
int n,a[300005];
ull mo=111339248186143ull,bs[300005];
ull c1[300005],c2[300005];
void add1(int x,ull s)
{
	while(x<=n)
	{
		c1[x]+=s;
		x+=x&-x;
	}
}
void add2(int x,ull s)
{
	while(x<=n)
	{
		c2[x]+=s;
		x+=x&-x;
	}
}
ull query1(int x)
{
	ull ans=0;
	while(x)
	{
		ans+=c1[x];
		x-=x&-x;
	}
	return ans;
}
ull query2(int x)
{
	ull ans=0;
	while(x)
	{
		ans+=c2[x];
		x-=x&-x;
	}
	return ans;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		e[a[i]].x=i,e[a[i]].wz=a[i];
	}
	bs[0]=1;
	for(int i=1;i<=n;i++)bs[i]=bs[i-1]*mo;
	sort(e+1,e+n+1);
	int flag=0;
	for(int i=1;i<=n;i++)c1[i]=c2[i]=0;
	for(int i=1;i<=n;i++)
	{
		int x=e[i].wz,len=min(x,n-x+1);
		int L=x-len+1,R=x+len-1;
		ull U1=query1(R)-query1(L-1),U2=query2(R)-query2(L-1);
		if(L==1)U1*=bs[n-R];
		else U2*=bs[L-1];
		if(U1!=U2)
		{
			printf("YES\n");
			flag=1;
			break;
		}
		add1(x,bs[x-1]);
		add2(x,bs[n-x]);
	}
	if(!flag)printf("NO\n");
	return 0;
}