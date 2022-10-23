#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  998244353
#pragma GCC optimize("O2")
using namespace std;
int n,x;
ll pw[150005];
ll sol(vector<int> v,int l,int x){
	if(v.empty()) return 0;
	if(l==0){
		sort(v.begin(),v.end());
		vector<pair<int,int> >p;
		int a=v[0],cnt=1;
		for(int i=1;i<v.size();++i){
			if(v[i]==a)++cnt;
			else p.pb(mp(a,cnt)),a=v[i],cnt=1;
		}
		p.pb(mp(a,cnt));
		ll ret=0;
		for(int i=0;i<p.size();++i){
			int o=0;
			for(int j=max(0,i-1);j<i;++j)if((p[j].first^p[i].first)<=x)o+=p[j].second;
			(ret+=(pw[p[i].second]-1ll)*pw[o])%=orz;
		}
		return ret;
	}
	if(!(x&(1<<l))){
		vector<int> v0,v1;
		for(int i=0;i<v.size();++i){
			if(v[i]&(1<<l))v1.pb(v[i]^(1<<l));
			else v0.pb(v[i]);
		}
		return (sol(v0,l-1,x)+sol(v1,l-1,x))%orz;
	}
	vector<int> v00,v01,v10,v11;
	int n00,n01,n10,n11;
	for(int i=0;i<v.size();++i){
		int k=(v[i]>>(l-1));
		if(k==0)v00.pb(v[i]);
		else if(k==1)v01.pb(v[i]);
		else if(k==2)v10.pb(v[i]);
		else v11.pb(v[i]);
	}
	n00=v00.size();
	n01=v01.size();
	n10=v10.size();
	n11=v11.size();
	if(x&(1<<(l-1))){
		vector<int> v0,v1;
		for(int i=0;i<n00;++i)v0.pb(v00[i]);
		for(int i=0;i<n01;++i)v1.pb(v01[i]);
		for(int i=0;i<n10;++i)v1.pb(v10[i]^(1<<l));
		for(int i=0;i<n11;++i)v0.pb(v11[i]^(1<<l));
		return ((sol(v0,l-1,x^(1<<l))+1ll)*(sol(v1,l-1,x^(1<<l))+1ll)-1ll)%orz;
	}
	ll ret=(pw[n00+n01]-1)+(pw[n10+n11]-1);
	vector<int> v0,v1;
	for(int i=0;i<n00;++i)v0.pb(v00[i]);
	for(int i=0;i<n01;++i)v1.pb(v01[i]);
	for(int i=0;i<n10;++i)v0.pb(v10[i]^(3<<(l-1)));
	for(int i=0;i<n11;++i)v1.pb(v11[i]^(3<<(l-1)));
	ret+=sol(v0,l-1,x^(3<<(l-1)))-(pw[n00]-1)-(pw[n10]-1);
	ret+=sol(v1,l-1,x^(3<<(l-1)))-(pw[n01]-1)-(pw[n11]-1);
	return ret%orz;
}
int main(){
	scanf("%d%d",&n,&x);
	pw[0]=1;
	for(int i=1;i<=n;++i)pw[i]=pw[i-1]*2ll%orz;
	vector<int> v;
	for(int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		v.pb(x);
	}
	ll ans=sol(v,29,x);
	printf("%lld\n",(ans%orz+orz)%orz);
    return 0;
}