#include<bits/stdc++.h>
#define LL long long
#define mod 1000000007
#define inf 0x1f3f3f3f3f3f3f3f
using namespace std;
int n,q,las,l,r,mid;
int a[100002],ans[100002];
LL prea[100002],pw[100002],ipw[100002];
vector<LL> pre;
typedef pair<int,int> P;
vector<P> Vec;
vector<P> vec[100002];
struct aaa
{
	int t;
	LL val,val2;
}tmp;
vector<aaa> v;
inline aaa merge(aaa a,aaa b)
{
	if((a.t<47 && ((inf>>a.t)<b.val || (a.val+=(b.val<<a.t))>inf)) || (a.t>=47 && b.val))a.val=inf;
	(a.val2+=b.val2*pw[a.t])%=mod,a.t+=b.t;
	return a;
}
int main()
{
	scanf("%d%d",&n,&q),pre.push_back(0),pw[0]=ipw[0]=1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),prea[i]=(prea[i-1]+a[i]*(pw[i]=(pw[i-1]<<1)%mod))%mod,ipw[i]=(ipw[i-1]*500000004)%mod;
	for(int i=1,x,y;i<=q;++i)scanf("%d%d",&x,&y),vec[y].push_back(P(x,i));
	for(int i=1;i<=n;++i)
	{
		for(las=i,tmp=(aaa){1,a[i],a[i]};v.size() && tmp.val>=0;v.pop_back(),Vec.pop_back(),pre.pop_back())tmp=merge(v.back(),tmp),las=Vec.back().first;
		v.push_back(tmp),Vec.push_back(P(las,i)),pre.push_back((pre.back()+tmp.val2)%mod);
		for(int j=0;j<vec[i].size();++j)
		{
			for(l=0,r=Vec.size()-1;l<=r;)
			{
				mid=((l+r)>>1);
				if(vec[i][j].first<=Vec[mid].second)r=mid-1;
				else l=mid+1;
			}
			ans[vec[i][j].second]=((((prea[Vec[l].second]-prea[vec[i][j].first-1])*ipw[vec[i][j].first]+(pre.back()-pre[l+1])*2)%mod)+mod)%mod;
		}
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
}