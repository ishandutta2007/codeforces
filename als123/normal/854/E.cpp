#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Maxn=200010;
LL N,Q; LL tr[Maxn]; LL Y[Maxn];
LL low_bit(LL x){return x&(-x);}
void Add(LL x){while(x<=N){tr[x]++; x+=low_bit(x);}}
LL Query(LL x){LL ans=0; while(x>=1){ans+=tr[x]; x-=low_bit(x);} return ans;}
struct node{LL id,u,d; node(){} node(LL _id,LL _d,LL _u){id=_id; u=_u; d=_d;}};
vector<node>id[2][Maxn]; LL ans[Maxn];
LL Calc(LL x){return x*(x-1)/2;}
LL L[Maxn],R[Maxn],D[Maxn],U[Maxn];
int main()
{
  scanf("%lld%lld",&N,&Q); for(LL i=1;i<=N;i++) scanf("%lld",&Y[i]);
  for(LL i=1;i<=Q;i++)
  {
    scanf("%lld%lld%lld%lld",&L[i],&D[i],&R[i],&U[i]);
	id[0][L[i]].push_back(node(i,D[i],U[i]));
	id[1][R[i]].push_back(node(i,D[i],U[i]));
  }
  
  memset(tr,0,sizeof(tr));
  for(LL i=1;i<=N;i++)
  {
	for(LL j=0;j<id[0][i].size();j++)
	  ans[id[0][i][j].id]+=(Calc(Query(id[0][i][j].d-1))+Calc((i-1)-Query(id[0][i][j].u)));
	Add(Y[i]);
  }
  
  memset(tr,0,sizeof(tr));
  for(LL i=N;i>=1;i--)
  {
	for(LL j=0;j<id[1][i].size();j++)
	  ans[id[1][i][j].id]+=(Calc(Query(id[1][i][j].d-1))+Calc((N-i)-Query(id[1][i][j].u)));
    Add(Y[i]);
  }
  
  for(LL i=1;i<=Q;i++) ans[i]+=Calc(N)-Calc(L[i]-1)-Calc(N-R[i])-Calc(D[i]-1)-Calc(N-U[i]),printf("%lld\n",ans[i]);
  return 0;
}