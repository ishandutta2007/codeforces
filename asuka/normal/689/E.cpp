#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+15;
const ll M = 1e9+7;
int n,k,l[N],r[N];
ll fac[N],ans;
vector<pair<int,int> > v;
bool gkp(int a,int b){return a>b;}
ll qpow(ll a,ll b){
	ll res = 1;
	while(b){
		if(b&1) res = res*a%M;
		a = a*a%M;
		b >>= 1;
	}
	return res;
}
ll inv(ll a){
	return qpow(a,M-2)%M;
}
ll comp(ll q,ll p){
	return fac[p]%M*inv(fac[q])%M*inv(fac[p-q])%M;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&k);
	fac[0] = 1;
	for(int i = 1;i <= n;++i) fac[i] = i*fac[i-1]%M;
	for(int i = 1;i <= n;++i) scanf("%d%d",&l[i],&r[i]);
	for(int i = 1;i <= n;++i) v.push_back(make_pair(l[i]-1,1)),v.push_back(make_pair(r[i],-1));
	sort(v.begin(),v.end());
	int cnt = 0,lst = -1e9;
	for(int i = 0;i < v.size();++i){
		if(cnt>=k) ans = (ans+comp(k,cnt)*(v[i].first-lst)%M)%M;
		lst = v[i].first;
		cnt += v[i].second;
	}
	printf("%lld",ans);
	return 0;
}