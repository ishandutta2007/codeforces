#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
typedef double db;
#define rdb register db
#define cdb const db
typedef long double ldb;
typedef unsigned long long ull;
#define pb push_back
#define mkp make_pair
#define pl pair<ll,int> 
#define pi pair<int,int>
namespace io{
	il char nc(){
		static char buf[100000],*p1=buf,*p2=buf;
		return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++; 
	}
	template <class I> 
	il void fr(I &num){
		num=0;register char c=nc();it p=1;
		while(c<'0'||c>'9') c=='-'?p=-1,c=nc():c=nc();
		while(c>='0'&&c<='9') num=num*10+c-'0',c=nc();
		num*=p;
	} 
	template <class I> 
	il I Max(I p,I q){return p>q?p:q;}
	template <class I> 
	il I Min(I p,I q){return p<q?p:q;}
	template <class I> 
	il I A(I x){return x<0?-x:x;}
	template <class I> 
	il void sp(I&p,I&q){I x=p;p=q,q=x;}
	template <class I>
	il void ckMax(I&p,I q){p=(p>q?p:q);}
	template <class I>
	il void ckMin(I&p,I q){p=(p<q?p:q);}
};
using io :: fr;
using io :: nc;
using io :: Max;
using io :: Min;
using io :: A;
using io :: sp;
using io :: ckMax;
using io :: ckMin;
const int N=1000005;
map<pi,int> mp;
int n,k,cn,d;
il void gcd(ct a,ct b){return !b?d=a,void():gcd(b,a%b);}
il db dis(ct x,ct y){return sqrt(1.0*x*x+1.0*y*y);}
struct ky{
	int x,y;db ds;
	bool operator < (const ky&p)const{return ds<p.ds;}
};
vector<ky> vec[N];
vector<db> o;
int main(){ 
	scanf("%d%d",&n,&k);ct kk=k>>1;rdb ans=0;
	for(it i=1,x,y;i<=n;++i){
		scanf("%d%d",&x,&y);
		if((!x)&&(!y)){vec[++cn].push_back((ky){x,y,0});continue;}
		gcd(A(x),A(y));pi p=mkp(x/d,y/d);
		if(!mp[p]) mp[p]=++cn;
		vec[mp[p]].push_back((ky){x,y,dis(x,y)});
	}
	for(it j=1,i;j<=cn;++j){
		ct sz=vec[j].size();it mn=Min(kk,sz);std::sort(vec[j].begin(),vec[j].end());
		for(i=1;i<=mn;++i) o.push_back(vec[j][sz-i].ds*((k-i)-(i-1)));
		db s=0;mn=Min(k,sz);
		for(i=kk+1;i<=mn;++i) o.push_back(vec[j][i-kk-1].ds*((k-kk-1)-kk)-2.0*s),s+=vec[j][i-kk-1].ds;
	}
	std::sort(o.begin(),o.end());
	for(it i=o.size()-1;(~i)&&k;--i) ans+=o[i],--k;
	printf("%.9lf",ans);
	return 0;
}