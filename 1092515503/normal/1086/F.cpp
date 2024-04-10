/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int inv2=499122177;
const int inv6=166374059;
void ADD(int&x,int y){if((x+=y)>=mod)x-=mod;}
int T,n,m,X[2010],Y[2010],res;
vector<int>u,v;
struct Sec{int l,r,d;Sec(int L,int R,int D){l=L,r=R,d=D;}};
vector<Sec>w[4010];
#define all(x) x.begin(),x.end()
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
struct SegTree{int sum,tag,mn,mnsum;}seg[16010];
void MOD(int x,int val){
	seg[x].tag+=val;
	if(seg[x].mn>0){seg[x].mn+=val;if(!seg[x].mn)seg[x].sum-=seg[x].mnsum;}
	else{seg[x].mn+=val;if(seg[x].mn)seg[x].sum+=seg[x].mnsum;}
}
void pushdown(int x){if(seg[x].tag)MOD(lson,seg[x].tag),MOD(rson,seg[x].tag),seg[x].tag=0;}
void pushup(int x){
	seg[x].mn=min(seg[lson].mn,seg[rson].mn),seg[x].mnsum=0;
	if(seg[x].mn==seg[lson].mn)seg[x].mnsum+=seg[lson].mnsum;
	if(seg[x].mn==seg[rson].mn)seg[x].mnsum+=seg[rson].mnsum;
	seg[x].sum=seg[lson].sum+seg[rson].sum;
}
void modify(int x,int l,int r,int L,int R,int tag){
	// printf("%d %d %d %d %d %d\n",x,l,r,L,R,tag);
	if(l>=R||r<=L)return;if(L<=l&&r<=R)return MOD(x,tag);
	pushdown(x),modify(lson,l,mid,L,R,tag),modify(rson,mid,r,L,R,tag),pushup(x);
}
void build(int x,int l,int r){
	seg[x].tag=0,seg[x].mn=0,seg[x].mnsum=u[r]-u[l],seg[x].sum=0;
	if(l+1!=r)build(lson,l,mid),build(rson,mid,r);
}
int F(int t){
	// printf("%d:\n",t);
	for(int i=1;i<=n;i++)u.push_back(X[i]-t),u.push_back(X[i]+t+1),v.push_back(Y[i]-t),v.push_back(Y[i]+t+1);
	sort(all(u)),u.resize(unique(all(u))-u.begin());
	sort(all(v)),v.resize(unique(all(v))-v.begin());
	for(int i=1;i<=n;i++){
		int l=lower_bound(all(u),X[i]-t)-u.begin(),r=lower_bound(all(u),X[i]+t+1)-u.begin();
		w[lower_bound(all(v),Y[i]-t)-v.begin()].emplace_back(l,r,1),
		w[lower_bound(all(v),Y[i]+t+1)-v.begin()].emplace_back(l,r,-1);
	}
	build(1,0,u.size()-1);
	int ret=0;
	for(int i=0;i+1<v.size();i++){
		for(auto x:w[i])modify(1,0,u.size()-1,x.l,x.r,x.d);
		/*,printf("[%d,%d,%d]",x.l,x.r,x.d);puts("");*/
		w[i].clear();
		ret=(1ll*seg[1].sum*(v[i+1]-v[i])+ret)%mod;
	}
	w[v.size()-1].clear(),u.clear(),v.clear();
	// printf("%d\n",ret);
	return ret;
}
int cons(int x){return x+1;}
int mono(int x){return(1ll*x*(x+1)/2)%mod;}
int bina(int x){return 1ll*x*(x+1)%mod*(x<<1|1)%mod*inv6%mod;}
int inte(int a,int b,int c,int l,int r){
	// printf("inte:%dx^2+%dx+%d(%d<=x<=%d)\n",a,b,c,l,r);
	return(1ll*a*(bina(r)+mod-bina(l-1))+1ll*b*(mono(r)+mod-mono(l-1))+1ll*c*(cons(r)+mod-cons(l-1)))%mod;
}
void mina(){
	scanf("%d%d",&n,&m),res=0;
	for(int i=1;i<=n;i++)scanf("%d%d",&X[i],&Y[i]);
	for(int i=0;i<=m;){
		if(i+2>m){for(;i<=m;i++)ADD(res,F(i));break;}
		int a=F(i),b=F(i+1),c=F(i+2);
		int A=i,B=i+1,C=i+2;
		int f[3]={0,0,0};
		f[2]=(1ll*inv2*a+f[2])%mod,f[1]=((2ll*mod-B-C)*inv2%mod*a+f[1])%mod,f[0]=(1ll*B*C%mod*inv2%mod*a+f[0])%mod;
		ADD(f[2],mod-b),f[1]=(1ll*(A+C)*b+f[1])%mod,ADD(f[0],mod-1ll*A*C%mod*b%mod);
		f[2]=(1ll*inv2*c+f[2])%mod,f[1]=((2ll*mod-A-B)*inv2%mod*c+f[1])%mod,f[0]=(1ll*A*B%mod*inv2%mod*c+f[0])%mod;
		// printf("%d %d %d\n",f[0],f[1],f[2]);
		int l=i+2,r=m;
		while(l<r){
			int md=(l+r+1)>>1;
			if(F(md)==((1ll*f[2]*md+f[1])%mod*md+f[0])%mod)l=md;else r=md-1;
		}
		ADD(res,inte(f[2],f[1],f[0],i,r));
		i=l+1;
	}
	res=(1ll*(m+1)*F(m)+mod-res)%mod;
	printf("%d\n",res);
}
int main(){
    T=1;
	while(T--)mina();
	return 0;
}
/*
1
4 1
2 2
1 3
0 2
2 4
*/