#include<bits/stdc++.h>
using namespace std;

const int maxn=200111;
const int base1=443;
const int base2=33;

int mod1,mod2,p1[maxn],p2[maxn];
bool isp(int x){
	for(int i=2;i*i<=x;i++)if(x%i==0)return false;
	return true;
}
void gen_mod(){
	mt19937 rng(chrono::high_resolution_clock().now().time_since_epoch().count());
	do{
		mod1=uniform_int_distribution<int>(100000000,1000000000)(rng);
	}while(!isp(mod1));
	do{
		mod2=uniform_int_distribution<int>(100000000,1000000000)(rng);
	}while(!isp(mod2)||mod1==mod2);
	p1[0]=p2[0]=1;
	for(int i=1;i<maxn;i++){
		p1[i]=1ll*p1[i-1]*base1%mod1;
		p2[i]=1ll*p2[i-1]*base2%mod2;
	}
}

struct data{
	int h1,h2,len,lv,rv;
	data(){h1=h2=len=lv=rv=0;}
};
bool operator==(const data&a,const data&b){
	return (a.h1==b.h1&&a.h2==b.h2&&a.len==b.len&&a.lv==b.lv&&a.rv==b.rv);
}
data merge(const data&a,const data&b){
	data ret;
	if(a.len==0&&b.len==0){
		ret.lv=ret.rv=a.lv^b.rv;
		return ret;
	}
	if(a.len==0){
		ret=b;
		ret.lv^=a.lv;
		return ret;
	}
	if(b.len==0){
		ret=a;
		ret.rv^=b.rv;
		return ret;
	}
	ret.len=a.len+b.len;
	ret.lv=a.lv;
	ret.rv=b.rv;
	int mid=a.rv^b.lv;
	ret.h1=(a.h1+1ll*p1[a.len-1]*mid+1ll*p1[a.len]*b.h1)%mod1;
	ret.h2=(a.h2+1ll*p2[a.len-1]*mid+1ll*p2[a.len]*b.h2)%mod2;
	return ret;
}

char s[maxn];
int n,m;
data sgt[maxn*4];
void build(int l,int r,int t){
	if(l==r){
		if(s[l]=='1')sgt[t].lv=sgt[t].rv=1;
		else sgt[t].len=1;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,t*2);
	build(mid+1,r,t*2+1);
	sgt[t]=merge(sgt[t*2],sgt[t*2+1]);
}
data query(int l,int r,int tl,int tr,int t){
	if(l==tl&&tr==r)return sgt[t];
	int mid=(tl+tr)/2;
	if(r<=mid)return query(l,r,tl,mid,t*2);
	else if(l>mid)return query(l,r,mid+1,tr,t*2+1);
	else return merge(query(l,mid,tl,mid,t*2),query(mid+1,r,mid+1,tr,t*2+1));
}
int main(){
	gen_mod();
	scanf("%d%s%d",&n,s+1,&m);
	build(1,n,1);
	for(int i=1,t1,t2,l;i<=m;i++){
		scanf("%d%d%d",&t1,&t2,&l);
		puts((query(t1,t1+l-1,1,n,1)==query(t2,t2+l-1,1,n,1))?"Yes":"No");
	}
	return 0;
}