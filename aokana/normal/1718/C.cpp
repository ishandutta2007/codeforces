#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],n,q,t_case;
vector<int>fac[maxn];
multiset<ll,greater<ll>>s[maxn];
vector<ll>sum[maxn];
int main(){
	for(ri i=2;i<=200000;++i)
		if(fac[i].empty())
			for(ri j=i;j<=200000;j+=i)
				fac[j].push_back(i);
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&q);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		for(ri ii:fac[n]){
			ri i=n/ii;
			s[i].clear(),sum[i]=vector<ll>(i+1);
			for(ri j=1;j<=i;++j){
				for(ri k=j;k<=n;k+=i)sum[i][j]+=a[k];
				s[i].insert(sum[i][j]);
			}
		}
		auto calc=[&](){
			ll ret=0;
			for(ri ii:fac[n]){
				ri i=n/ii;
				ckmax(ret,*s[i].begin()*i);
			}
			return ret;
		};
		printf("%lld\n",calc());
		while(q--){
			ri x,y;
			scanf("%d%d",&x,&y);
			for(ri ii:fac[n]){
				ri i=n/ii;
				ri p=(x-1)%i+1;
				s[i].erase(s[i].find(sum[i][p]));
				sum[i][p]+=y-a[x];
				s[i].insert(sum[i][p]);
			}
			a[x]=y;
			printf("%lld\n",calc());
		}
	}
	return 0;
}