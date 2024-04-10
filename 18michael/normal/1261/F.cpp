#include<bits/stdc++.h>
#define M 60
#define LL long long
#define mod 998244353
using namespace std;
const LL Mx=(1LL<<M)-1;
int S_t;
LL a,ans=0,las=0;
LL pw[62];
vector<LL> vec[62];
typedef pair<LL,LL> P;
vector<P> Vec;
struct aaa
{
	int n;
	LL X[102],Y[102];
}A,B;
struct SegTree
{
	int lson[24002],rson[24002];
	inline void ins(int k,LL l,LL r,LL l1,LL r1)
	{
		if(l>=l1 && r<=r1)return ;
		LL mid=((l+r)>>1);
		if(l1<=mid)
		{
			if(!lson[k])lson[k]=(++S_t);
			ins(lson[k],l,mid,l1,r1);
		}
		if(r1>mid)
		{
			if(!rson[k])rson[k]=(++S_t);
			ins(rson[k],mid+1,r,l1,r1);
		}
	}
	inline void dfs(int k,LL l,LL r,int d)
	{
		if(!k)return ;
		vec[d].push_back(l);
		LL mid=((l+r)>>1);
		dfs(lson[k],l,mid,d-1),dfs(rson[k],mid+1,r,d-1);
	}
	inline void ins2(LL l,LL r,LL l1,LL r1,int d)
	{
		if(l>=l1 && r<=r1)
		{
			for(int i=0;i<vec[d].size();++i)a=(((vec[d][i]^l)>>d)<<d),Vec.push_back(P(a,a+pw[d]-1));
			return ;
		}
		LL mid=((l+r)>>1);
		if(l1<=mid)ins2(l,mid,l1,r1,d-1);
		if(r1>mid)ins2(mid+1,r,l1,r1,d-1);
	}
}S;
inline LL F(LL a,LL b)
{
	return a%=mod,b%=mod,(((a+b)*(b-a+1))>>1)%mod;
}
inline void solve(aaa &A,aaa &B)
{
	S_t=1,memset(S.lson,0,sizeof(S.lson)),memset(S.rson,0,sizeof(S.rson));
	for(int i=0;i<=M;++i)vec[i].clear();
	for(int i=1;i<=A.n;++i)S.ins(1,0,Mx,A.X[i],A.Y[i]);
	S.dfs(1,0,Mx,M);
	for(int i=1;i<=B.n;++i)S.ins2(0,Mx,B.X[i],B.Y[i],M);
}
int main()
{
	for(int i=pw[0]=1;i<=M;++i)pw[i]=(pw[i-1]<<1);
	scanf("%d",&A.n);
	for(int i=1;i<=A.n;++i)scanf("%lld%lld",&A.X[i],&A.Y[i]);
	scanf("%d",&B.n);
	for(int i=1;i<=B.n;++i)scanf("%lld%lld",&B.X[i],&B.Y[i]);
	solve(A,B),solve(B,A),sort(Vec.begin(),Vec.end());
	for(int i=0;i<Vec.size();++i)if((las=max(las,Vec[i].first))<=Vec[i].second)ans+=F(las,Vec[i].second),las=Vec[i].second+1;
	return 0&printf("%lld",((ans%mod)+mod)%mod);
}