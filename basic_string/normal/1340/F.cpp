#include<bits/stdc++.h>
using namespace std;
enum{N=100009};
namespace H{
	const int P1=1e9+97,P2=1e9+99,B=131;
	int _1[N*2],_2[N*2],*w1=_1+N,*w2=_2+N;
	void exgcd(int a,int b,int&x,int&y){b?(exgcd(b,a%b,y,x),y-=a/b*x):(x=1,y=0);}
	void in(int n){
		int i1,i2,i;
		exgcd(B,P1,i1,i),exgcd(B,P2,i2,i),w1[0]=w2[0]=1,i1=(i1+P1)%P1,i2=(i2+P2)%P2;
		for(i=1;i<=n;++i)w1[i]=w1[i-1]*1ll*B%P1,w2[i]=w2[i-1]*1ll*B%P2,
		w1[-i]=w1[-i+1]*1ll*i1%P1,w2[-i]=w2[-i+1]*1ll*i2%P2;
	}
	struct S{
		int x1,x2,l;
		S():x1(),x2(),l(){}
		S(int v):x1(v),x2(v),l(1){}
		S(int u,int v,int w):x1(u),x2(v),l(w){}
		bool operator==(S b){return x1==b.x1&&x2==b.x2&&l==b.l;}
		S operator+(S b){return S((x1+b.x1*1ll*w1[l])%P1,(x2+b.x2*1ll*w2[l])%P2,l+b.l);}
		S operator-(S b){return S((x1-b.x1+P1)*1ll*w1[-b.l]%P1,(x2-b.x2+P2)*1ll*w2[-b.l]%P2,l-b.l);}
	};
}
using H::S;
struct T{
	bool b;
	S l,r;
	T():b(),l(),r(){}
	T(int x){b=0,x>0?r=x:l=-x;}
}s[N*4];
S w[99];
int u,v,o,n,t[99];
S gl(int k,int l){
	if(!l)return S();
	if(l==s[k].l.l)return s[k].l;
	if(l<=s[k*2].l.l)return gl(k*2,l);
	return s[k*2].l+(gl(k*2+1,l-s[k*2].l.l+s[k*2].r.l)-s[k*2].r);
}
S gr(int k,int l){
	if(!l)return S();
	if(l==s[k].r.l)return s[k].r;
	if(l<=s[k*2+1].r.l)return gr(k*2+1,l);
	return s[k*2+1].r+(gr(k*2,l-s[k*2+1].r.l+s[k*2+1].l.l)-s[k*2+1].l);
}
void up(int k){
	if(s[k].b=s[k*2].b|s[k*2+1].b)return;
	s[k].l=s[k*2].l,s[k].r=s[k*2+1].r;
	if(s[k*2].r.l<s[k*2+1].l.l){
		if(s[k*2].r==gl(k*2+1,s[k*2].r.l))s[k].l=s[k].l+(s[k*2+1].l-s[k*2].r);
		else s[k].b=1;
	}else{
		if(s[k*2+1].l==gr(k*2,s[k*2+1].l.l))s[k].r=s[k].r+(s[k*2].r-s[k*2+1].l);
		else s[k].b=1;
	}
}
void bd(int k,int l,int r){
	if(l==r){int x;cin>>x,s[k]=x;return;}
	int m=l+r>>1;
	bd(k*2,l,m),bd(k*2+1,m+1,r),up(k);
}
void upd(int k,int l,int r){
	if(l==r){s[k]=v;return;}
	int m=l+r>>1;
	if(u<=m)upd(k*2,l,m);else upd(k*2+1,m+1,r);
	up(k);
}
void get(int k,int l,int r){
	if(u<=l&&r<=v){t[++o]=k;return;}
	int m=l+r>>1;
	if(u<=m)get(k*2,l,m);
	if(m<v)get(k*2+1,m+1,r);
}
S gt(int x,int l){
	if(!l)return S();
	if(l==w[x].l)return w[x];
	if(l<=s[t[x]].r.l)return gr(t[x],l);
	return s[t[x]].r+(gt(x-1,l-s[t[x]].r.l+s[t[x]].l.l)-s[t[x]].l);
}
bool qry(int l,int r){
	u=l,v=r,o=0,get(1,1,n);
	for(int i=1;i<=o;++i){
		if(s[t[i]].b||w[i-1].l<s[t[i]].l.l)return 0;
		if(s[t[i]].l==gt(i-1,s[t[i]].l.l))w[i]=s[t[i]].r+(w[i-1]-s[t[i]].l);
		else return 0;
	}
	return!w[o].l;
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int q,i,l,r;
	cin>>n>>i,H::in(n),bd(1,1,n);
	for(cin>>q;q--;)if(cin>>i>>l>>r,i==1)u=l,v=r,upd(1,1,n);else cout<<(qry(l,r)?"Yes":"No")<<'\n';
}