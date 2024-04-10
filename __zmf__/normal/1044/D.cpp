//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int pre[400009],q,cnt,opt,l,r,p,fa[400009],x,px,py,val[400009],res,lst;
map<int,int> mp;
inline int find(int x)
{
	if(fa[x]==x)return x;
	int X=fa[x];
	fa[x]=find(fa[x]);
	val[x]^=val[X];
	return fa[x];
}
int main()
{
	q=read();
	for(int ttt=1;ttt<=q;ttt++)
	{
		opt=read();l=read()^lst,r=read()^lst;
		if(l>r)swap(l,r);
		l--;
		if(opt==1)
		{
			p=read()^lst;
			if(mp[l]==0)mp[l]=++cnt,fa[cnt]=cnt;
			if(mp[r]==0)mp[r]=++cnt,fa[cnt]=cnt;
			px=find(mp[l]),py=find(mp[r]);
			p^=val[mp[l]]^val[px]^val[mp[r]]^val[py];
			if(px==py)continue;
			else
			{
				fa[px]=py;val[px]=p;
			}
		}
		else
		{
			if(mp[l]==0||mp[r]==0)
			{
				puts("-1");lst=1;
				continue;
			}
			px=find(mp[l]);py=find(mp[r]);
			if(px!=py)
			{
				puts("-1");lst=1;continue;
			}
			else
			{
				lst=val[mp[l]]^val[mp[r]];
				printf("%d\n",lst);continue;
			}
		}
	}
	return 0;
}