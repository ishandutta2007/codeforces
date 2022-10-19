#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int ksm(int x,ll y){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;} 
int n;
map<int,pair<ll,ll> >mp[110];
map<int,ll>res;
void print(){int ans=1;for(auto x:res)ans=1ll*ans*ksm(x.first,x.second)%mod;printf("%d\n",ans);}
void check(){
//	for(auto x:res)printf("[%d,%d]",x.first,x.second);puts("");
	for(int i=1;i<=n;i++)for(auto x:res){
		if(mp[i].find(x.first)==mp[i].end())return puts("-1"),void();
		auto y=mp[i][x.first];
		if(x.second<y.first)return puts("-1"),void();
		if(x.second==y.first)continue;
		if(!y.second)return puts("-1"),void();
		if((x.second-y.first)%y.second)return puts("-1"),void();
	}
	print();
}
void only(int i,ll k){
//	printf("%d:%d\n",i,k);
	for(auto x:mp[i])if(x.second.first+k*x.second.second)res[x.first]=x.second.first+k*x.second.second;
	check();exit(0);
}
void exgcd(ll a,ll b,ll&x,ll&y){if(!b){x=1,y=0;return;}exgcd(b,a%b,y,x),y-=a/b*x;}
void fasten(ll a,ll b,ll c){
//	printf("[%d,%d,%d]\n",a,b,c);
	ll x,y,u,v;
	if(!c)u=0,v=a*b;else{
		exgcd(a,b,x,y);
		x*=c;
		x=(x%b+b)%b,y=(c-a*x)/b;
		if(y>0){
			ll t=(y-1)/(a*b)+1;
			x+=t*b,y-=t*a;
		}
		if(x<0){puts("-1");exit(0);} 
		u=x,v=b;
	}
	for(auto&i:mp[0])i.second.first+=u*i.second.second,i.second.second*=v;
}
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		for(int j=2;j*j<=x;j++){
			if(x%j)continue;
			while(!(x%j))mp[i][j].first++,x/=j;
		}
		if(x!=1)mp[i][x].first++;
		scanf("%d",&x);
		for(int j=2;j*j<=x;j++){
			if(x%j)continue;
			while(!(x%j))mp[i][j].second++,x/=j;
		}
		if(x!=1)mp[i][x].second++;
	}
	mp[0]=mp[1];
	for(int i=2;i<=n;i++){
//		printf("%d\n",i);
		for(auto x:mp[0])if(mp[i].find(x.first)==mp[i].end())only(0,0);
		for(auto x:mp[i])if(mp[0].find(x.first)==mp[0].end())only(i,0);
		ll X=-1,Y=-1,Z=-1;
		for(auto j:mp[0]){
			auto x=j.second;
			auto y=mp[i][j.first];
//			printf("%d[%d,%d][%d,%d]\n",j.first,x.first,x.second,y.first,y.second);
			if(!x.second&&!y.second){
				if(x.first==y.first)continue;
				return puts("-1"),0;
			}
			if(!x.second)only(i,(x.first-y.first)/y.second);
			if(!y.second)only(0,(y.first-x.first)/x.second);
			ll u=x.second,v=y.second,w=y.first-x.first;
			ll gcd=__gcd(u,v);
			if(w%gcd)return puts("-1"),0;
			u/=gcd,v/=gcd,w/=gcd;
			if(X==-1&&Y==-1&&Z==-1){X=u,Y=v,Z=w;continue;}
//			printf("%d %d %d\n",X,Y,Z);
//			printf("%d %d %d\n",u,v,w);
			if(Y*u==v*X){
				if(Z*u==w*X)continue;
				return puts("-1"),0;
			}
			if((Z*u-w*X)%(Y*u-v*X))return puts("-1"),0;
			ll q=(Z*u-w*X)/(Y*u-v*X);
			if((Z-q*Y)%X)return puts("-1"),0;
			ll p=(Z-q*Y)/X;
			if(p<0)return puts("-1"),0;
			only(0,p);
		}
		fasten(X,Y,Z);
	}
	only(0,0);
	return 0;
}