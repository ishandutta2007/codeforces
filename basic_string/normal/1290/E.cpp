#include<bits/stdc++.h>
using namespace std;
enum{N=150009};
using ll=long long;
ll res[N];
int p[N],a[N],n,u,v;
struct T{
	ll s;
	int a,a2,c,t,w;
}s[524299];
#define L k*2,l,m
#define R k*2+1,m+1,r
#define M int m=(l+r)>>1;
#define _ s[k],s[k*2],s[k*2+1]
#define I int k,int l,int r
void bd(I){
	if(s[k].s=s[k].a=s[k].c=s[k].t=s[k].w=0,s[k].a2=-N,l==r)return;
	M bd(L),bd(R);
}
auto up=[](T&k,T&a,T&b){
	if(k.s=a.s+b.s,k.w=a.w+b.w,a.a>b.a)k.a=a.a,k.a2=max(a.a2,b.a),k.c=a.c;
	else if(a.a<b.a)k.a=b.a,k.a2=max(a.a,b.a2),k.c=b.c;
	else k.a=a.a,k.a2=max(a.a2,b.a2),k.c=a.c+b.c;
};
auto cmn=[](T&k,int v){k.s+=(v-k.a)*1ll*k.c,k.a=v;};
auto ad=[](T&k,int v){k.s+=k.w*1ll*v,k.a+=v,k.a2+=v,k.t+=v;};
auto dn=[](T&k,T&a,T&b){
	if(k.t)ad(a,k.t),ad(b,k.t),k.t=0;
	if(k.a<a.a)cmn(a,k.a);
	if(k.a<b.a)cmn(b,k.a);
};
int add1(I){
	if(u<=l)return ad(s[k],1),s[k].w;
	M dn(_);int w=u>m?add1(R):add1(L)+add1(R);return up(_),w;
}
void umin(I){
	if(s[k].a<=v)return;
	if(r<=u&&s[k].a2<v)return cmn(s[k],v);
	M dn(_),m<u?(umin(L),umin(R)):umin(L),up(_);
}
void upd(I){
	if(l==r){s[k].a=s[k].s=v,s[k].c=s[k].w=1;return;}
	M dn(_),u>m?upd(R):upd(L),up(_);
}
void wk(){
	int i;
	for(bd(1,1,n),i=1;i<=n;++i){
		u=p[i]+1,v=i-add1(1,1,n);
		u=p[i]-1,umin(1,1,n);
		u=p[i],v=i+1,upd(1,1,n);
		res[i]+=s[1].s;
	}
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i;
	cin>>n;
	for(i=1;i<=n;++i)cin>>a[i],p[a[i]]=i;
	wk();
	for(i=1;i<=n;++i)p[i]=n+1-p[i];
	wk();
	for(i=1;i<=n;++i)cout<<res[i]-i*(i+2ll)<<'\n';
}