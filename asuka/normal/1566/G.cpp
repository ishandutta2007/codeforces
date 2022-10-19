#include<bits/stdc++.h>
#define int long long
#define N 100015
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define infll 0x3f3f3f3f3f3f3f3f
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define VI vector<int>
#define L(x) ((int)x.size())
using namespace std;using ED=pair<int,pii>;int n,m,q;map<pii,int> M,Z;multiset<int> F;multiset<pii> S[N];set<ED> e;bool ok(ED a,ED b){return a.se.fi!=b.se.fi&&a.se.fi!=b.se.se&&a.se.se!=b.se.fi&&a.se.se!=b.se.se;}pii O(int u,int v){if(u>v)return mp(v,u);else return mp(u,v);}void upd(int x,int y,int w,bool FG){int sum;sum=0;int cnt=1;for(auto it=S[x].begin();cnt<=3&&it!=S[x].end();it++,cnt++){if(Z[O((*it).se,x)]==2)e.erase(mp((*it).fi,O((*it).se,x)));Z[O((*it).se,x)]--;sum+=(*it).fi;}if(L(S[x])>=3) F.erase(F.find(sum));if(FG) S[x].insert(mp(w,y));else S[x].erase(S[x].find(mp(w,y)));sum=0;cnt=1;for(auto it=S[x].begin();cnt<=3&&it!=S[x].end();it++,cnt++) {if(Z.count(O((*it).se,x))==0)Z[O((*it).se,x)]=1;else Z[O((*it).se,x)]++;if(Z[O((*it).se,x)]==2)e.insert(mp((*it).fi,O(x,(*it).se)));sum += (*it).fi;}if(L(S[x]) >= 3) F.insert(sum);}void MD(int u,int v,int w,bool FG){if(FG)M[O(u,v)]=w;else M[O(u,v)]=-1;upd(u,v,w,FG);upd(v,u,w,FG);}int solve(){int ans=infll;if(L(F)>0)ans=min(ans,*F.begin());int cx=1;for(auto x=e.begin();x!=e.end()&&cx<=6;++x,++cx){int cy=cx;for(auto y=x;y!=e.end()&&cy<=6;++y,++cy){if(ok(*x,*y)){ans=min(ans,(*x).fi+(*y).fi);}}}return ans;}signed main(){scanf("%lld%lld",&n,&m);rep(i,1,m){int u,v,w;scanf("%lld%lld%lld",&u,&v,&w);MD(u,v,w,1);}printf("%lld\n",solve());scanf("%lld",&q);while(q--){int opt,u,v,w;scanf("%lld%lld%lld",&opt,&u,&v);if(opt==0){MD(u,v,M[O(u,v)],0);}else{scanf("%lld",&w);MD(u,v,w,1);}printf("%lld\n",solve());}return 0;}