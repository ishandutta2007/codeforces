#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int m,n,t_case;
ll a[maxn],sum;
multiset<ll>s;
bool dfs(ll x){
	auto it=s.find(x);
	if(it!=s.end()){
		s.erase(it);
		return true;
	}
	if(x==1)return false;
	if(dfs(x>>1))return dfs(x+1>>1);
	return false;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);	
		s.clear(),sum=0;
		for(ri i=1;i<=n;++i)scanf("%lld",a+i),s.insert(a[i]),sum+=a[i];
		puts(dfs(sum)?"YES":"NO");
	}
	return 0;
}