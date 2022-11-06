//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=2e5+9;
int maxn,m,a,b,k,p,qwq,pwp,flag;
int w[N],ans,res;
bool vis[N];
inline int Gcd(int x,int y)
{
	if(y==0)return x;
	else return Gcd(y,x%y);
}
signed main()
{
	m=read(),a=read(),b=read();
	k=Gcd(a,b);a=a/k,b=b/k;
	p=a*b;
	int now=0,maxn=0;w[0]++,vis[0]=1,res=1;
	while(1)
	{
		now=now+a;maxn=max(maxn,now);
		while(now>=0)
		{
			if(vis[now]!=1)w[maxn]++,vis[now]=1,res++;
			now-=b;
		}
		now=now+b;now=now%b;
		if(res==a+b)break;
		vis[now]=1;
	//	cout<<now<<endl;
	}
	now=0;
	for(int i=0;i<=a+b-1&&i<=m;i++)
	{
		//cout<<w[i]<<endl;
		ans=ans+w[i]*max((long long)0,(m-i*k+1));
	}
	maxn=a+b-1;qwq=m/k;
	if((maxn+1)*k<=m)ans=ans+(qwq-maxn)*(2*m-k*(qwq+maxn+1)+2)/2;
	cout<<ans<<endl;
	return 0;
}