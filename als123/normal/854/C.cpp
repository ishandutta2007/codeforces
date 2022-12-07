#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Maxn=300010;
LL N,K; pair<LL,LL> pr[Maxn];
priority_queue<pair<LL,LL> >Q;
LL z[Maxn];
int main()
{
  scanf("%lld%lld",&N,&K);
  for(LL i=1;i<=N;i++) scanf("%lld",&pr[i].first),pr[i].second=i;
  for(LL i=1;i<=K;i++) Q.push(pr[i]); LL ans=0;
  for(LL i=K+1;i<=K+N;i++)
  {
	if(i<=N) Q.push(pr[i]);
	pair<LL,LL> x=Q.top(); ans+=(i-x.second)*x.first;
	z[x.second]=i; Q.pop();
  }
  printf("%lld\n",ans);
  for(LL i=1;i<N;i++) printf("%lld ",z[i]); printf("%lld\n",z[N]);
  return 0;
}