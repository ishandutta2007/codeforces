//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=1e5+9,INF=1e13;
int n,m,cl,ce,v,q,xx,x2,yy,y2,ans,res,pos1;
int l[N],e[N];
signed main()
{
	n=read(),m=read(),cl=read(),ce=read(),v=read();
	for(int i=1;i<=cl;i++)l[i]=read();l[++cl]=INF;
	for(int i=1;i<=ce;i++)e[i]=read();e[++ce]=INF;
	q=read();
	for(int i=1;i<=q;i++)
	{
		xx=read(),yy=read();x2=read(),y2=read();
		ans=INF;
		if(xx==x2)
		{
			printf("%lld\n",abs(yy-y2));
			continue;
		}
		res=abs(xx-x2);
		pos1=lower_bound(l+1,l+cl+1,yy)-l;
		res+=(l[pos1]-yy);res+=abs(l[pos1]-y2);
		ans=min(ans,res);res=abs(xx-x2);//cout<<res<<endl;
		if(pos1!=1)pos1--;
		res+=abs(yy-l[pos1]);res+=abs(l[pos1]-y2);
		ans=min(ans,res);//cout<<res<<endl;
		res=(abs(xx-x2)+v-1)/v;
		pos1=lower_bound(e+1,e+ce+1,yy)-e;
		res+=(e[pos1]-yy);res+=abs(e[pos1]-y2);//cout<<res<<endl;
		ans=min(ans,res);res=(abs(xx-x2)+v-1)/v;
		if(pos1!=1)pos1--;
		res+=abs(yy-e[pos1]);res+=abs(e[pos1]-y2);
		ans=min(ans,res);//cout<<res<<endl;
		printf("%lld\n",ans);
	}
	return 0;
}