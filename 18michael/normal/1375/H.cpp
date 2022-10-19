#include<bits/stdc++.h>
#define sq 256
using namespace std;
int n,q,t,res;
int a[4102],bl[4102],st[4102],ed[4102],to[4102],ans[65542];
vector<int> vec[262];
vector<int> Vec[1032][262],Vec2[262][262];
typedef pair<int,int> P;
vector<P> Ans;
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
inline void solve(int k,int l,int r,vector<int> &vec)
{
	if(l==r)return Vec[k][0].clear(),Vec[k][0].push_back(vec[0]);
	int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
	vector<int> vl,vr;
	for(int i=0;i<vec.size();++i)
	{
		if(a[vec[i]]<=mid)vl.push_back(vec[i]);
		else vr.push_back(vec[i]);
	}
	solve(ls,l,mid,vl),solve(rs,mid+1,r,vr);
	for(int i=0,ll=0,lr,rl=0,rr;i<vec.size();++i)
	{
		if(ll<vl.size() && vl[ll]<vec[i])++ll;
		if(rl<vr.size() && vr[rl]<vec[i])++rl;
		lr=ll,rr=rl,Vec[k][i].clear();
		for(int j=i;j<vec.size();++j)
		{
			if(lr<vl.size() && vl[lr]==vec[j])++lr;
			else ++rr;
			if(ll==lr)Vec[k][i].push_back(Vec[rs][rl][rr-rl-1]);
			else if(rl==rr)Vec[k][i].push_back(Vec[ls][ll][lr-ll-1]);
			else Vec[k][i].push_back(++t),Ans.push_back(P(Vec[ls][ll][lr-ll-1],Vec[rs][rl][rr-rl-1]));
		}
	}
}
int main()
{
	scanf("%d%d",&n,&q),t=n;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),to[a[i]]=i,bl[i]=(i-1)/sq+1;
	for(int i=1;i<=bl[n];++i)
	{
		st[i]=(i-1)*sq+1,ed[i]=min(i*sq,n);
		for(int j=st[i];j<=ed[i];++j)vec[i].push_back(to[j]);
		sort(vec[i].begin(),vec[i].end()),solve(1,st[i],ed[i],vec[i]);
		for(int j=st[i];j<=ed[i];++j)Vec2[i][j-st[i]]=Vec[1][j-st[i]];
	}
	for(int i=1,x,y;i<=q;++i)
	{
		scanf("%d%d",&x,&y),res=0;
		for(int i=1,l,r;i<=bl[n];++i)
		{
			l=lower_bound(vec[i].begin(),vec[i].end(),x)-vec[i].begin();
			r=lower_bound(vec[i].begin(),vec[i].end(),y+1)-vec[i].begin()-1;
			if(l<=r)
			{
				if(!res)res=Vec2[i][l][r-l];
				else Ans.push_back(P(res,Vec2[i][l][r-l])),res=(++t);
			}
		}
		ans[i]=res;
	}
	printf("%d\n",t);
	for(int i=0;i<Ans.size();++i)printf("%d %d\n",Ans[i].first,Ans[i].second);
	for(int i=1;i<=q;++i)printf("%d ",ans[i]);
	return 0;
}