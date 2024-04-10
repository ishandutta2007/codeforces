#include<bits/stdc++.h>
using namespace std;
#define ll long long
mt19937 rd(time(0));
const int N=5e5+5,P1=1e9+7,P2=1e9+9,B=rd()%N+N;
vector<int>e[N];
map<pair<ll,ll>,ll>mp;
ll a[N];
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
int main(){
	int T,n,m,i,j,k;
	ll s,t,h1,h2;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),s=0,mp.clear();
		for(i=1;i<=n;++i)e[i].clear(),scanf("%lld",a+i);
		while(m--){
			scanf("%d%d",&i,&j);
			e[j].push_back(i);
		}
		for(i=1;i<=n;++i){
			if(e[i].empty())continue;
			sort(e[i].begin(),e[i].end()),h1=h2=0;
			for(auto j:e[i])h1=(h1*B+j)%P1,h2=(h2*B+j)%P2;
			mp[{h1,h2}]+=a[i];
		}
		for(auto t:mp)s=gcd(s,t.second);
		printf("%lld\n",s);
	}
	return 0;
}