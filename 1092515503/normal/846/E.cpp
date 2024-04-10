#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll lim=1e18; 
int n;
ll a[100100],b[100100];
vector<pair<int,int> >v[100100];
ll ksc(ll x,int y){
	ll z=0;
	for(;y;y>>=1,x*=2){
		if(x<-lim){puts("NO");exit(0);}
		if(y&1){
			z+=x;
			if(z<-lim){puts("NO");exit(0);}
		}
	}
	return z;
}
ll dfs(int x){
	ll ret=0;
	for(auto y:v[x]){
		ll tmp=dfs(y.first);
		if(tmp>=0)ret+=tmp;
		else{
			tmp=ksc(tmp,y.second);
			ret+=tmp;
			if(ret<-lim){puts("NO");exit(0);}
		}
	}
	ret+=b[x]-a[x];
	if(ret<-lim){puts("NO");exit(0);}
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=2,x,y;i<=n;i++)scanf("%d%d",&x,&y),v[x].push_back(make_pair(i,y));
	ll tmp=dfs(1);
	puts(tmp>=0?"YES":"NO");
	return 0;
}