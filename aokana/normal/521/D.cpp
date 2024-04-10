#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=5e5+10,mod=1e9+7;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],k,m,n,op[maxn];
vector<int>ans;
typedef pair<int,int> pii;
pii q1[maxn];
vector<pii>q2[maxn];
typedef pair<__int128,__int128> pll;
typedef pair<pll,int> ppi;
#define fi first
#define se second
vector<ppi>q3;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	for(ri i=1,pos,val;i<=m;++i){
		scanf("%d%d%d",op+i,&pos,&val);
		if(op[i]==1)ckmax(q1[pos],pii{val,i});
		else if(op[i]==2)q2[pos].emplace_back(val,i);
		else q3.emplace_back(pll{val,1},i);
	}
	for(ri i=1;i<=n;++i){
		if(q1[i].fi>a[i])q2[i].emplace_back(q1[i].fi-a[i],q1[i].se);
		sort(q2[i].begin(),q2[i].end(),greater<pii>());
		ll tot=a[i];
		for(auto j:q2[i])q3.emplace_back(pll{tot+j.fi,tot},j.se),tot+=j.fi;
	}
	sort(q3.begin(),q3.end(),[&](const ppi &x,const ppi &y){return x.fi.fi*y.fi.se>y.fi.fi*x.fi.se;});
	for(ri i=0;i<min((int)q3.size(),k);++i)ans.push_back(q3[i].se);
	printf("%d\n",(int)ans.size());
	sort(ans.begin(),ans.end(),[&](const int &x,const int &y){return op[x]<op[y];});
	for(auto i:ans)printf("%d ",i);
	return 0;
}