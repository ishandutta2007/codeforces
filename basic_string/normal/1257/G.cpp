#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
unordered_map<int,int>mp;
int n,r[400009];
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
void ntt(vector<int>&a,bool b=0){
	int i,j,k,l,*p,*q,u,v,w;
	for(i=0;i<n;++i)if(i<r[i])swap(a[i],a[r[i]]);
	for(i=1;i<n;i=l)
	for(j=0,l=i*2,u=qp(3,(P-1)/l);j<n;j+=l)
	for(k=0,v=1,p=&a[j],q=&p[i];k<i;++k,v=v*1ll*u%P)
	w=v*1ll*q[k]%P,q[k]=p[k]<w?p[k]-w+P:p[k]-w,p[k]=(p[k]+=w)<P?p[k]:p[k]-P;
	if(b)for(i=0,u=qp(n,P-2),reverse(&a[1],&a[n]);i<n;++i)a[i]=a[i]*1ll*u%P;
}
struct poly{
	int l;
	vector<int>a;
	bool operator<(poly x)const{return l>x.l;}
	poly(int x){for(l=x;~x;--x)a.push_back(1);}
	void mul(poly x){
		int i;
		for(n=1,l+=x.l;n<=l;n*=2);
		for(i=1;i<n;++i)r[i]=(r[i>>1]>>1)|((i&1)?(n>>1):0);
		a.resize(n),x.a.resize(n),ntt(a),ntt(x.a);
		for(i=0;i<n;++i)a[i]=a[i]*1ll*x.a[i]%P;
		ntt(a,1);
	}
}p(0);
priority_queue<poly>q;
int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;++i)scanf("%d",&j),++mp[j];
	for(auto o:mp)q.push(poly(o.second));
	while(q.size()>1)p=q.top(),q.pop(),p.mul(q.top()),q.pop(),q.push(p);
	printf("%d",q.top().a[n>>1]);
	return 0;
}