#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],b[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		vector<int>v[2];
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		for(ri i=1;i<=n;++i)scanf("%d",b+i),v[a[i]].push_back(b[i]);
		for(ri i:{0,1})sort(v[i].rbegin(),v[i].rend());
		ri x=min(v[0].size(),v[1].size());
		ll sum=0;
		for(ri i=0;i<x;++i)sum+=2ll*(v[0][i]+v[1][i]);
		if(v[0].size()==v[1].size())sum-=min(v[0].back(),v[1].back());
		else if(v[1].size()==x)for(ri i=x;i<v[0].size();++i)sum+=v[0][i];
		else for(ri i=x;i<v[1].size();++i)sum+=v[1][i];
		printf("%lld\n",sum);
	}
	return 0;
}