#include<cstdio>
#include<map>
#define Q 1000000007
using namespace std;
int qp(int x,int p){
	int r=1,a=x;
	while(p){
		if(p&1) r=1LL*r*a%Q;
		p>>=1;
		a=1LL*a*a%Q;
	}
	return r;
}
int rev(int x){
	return qp(x,Q-2);
}
int div=1;
int cmb(long long n,int m){
	int r=div;
	int i;
	for(i=n;i>n-m;i--) r=1LL*r*i%Q;
	if(r<0) r+=Q;
	return r;
}
int main(){
	int i,n,t,j,ans=0;
	long long s,f[30],id;
	map<long long,int> poly;
	map<long long,int>::iterator it;
	scanf("%d %I64d",&n,&s);
	for(i=0;i<n;i++){
		scanf("%I64d",&f[i]);
	}
	for(i=0;i<(1<<n);i++){
		t=1;
		id=0;
		for(j=0;j<n;j++){
			if((1<<j)&i){
				id+=f[j]+1;
			}
			else t*=-1;
		}
		if(!poly.count(id)) poly[id]=t;
		else poly[id]+=t;
	}
	for(i=1;i<=n-1;i++) div=1LL*div*rev(i)%Q;
	s+=n;
	for(it=poly.lower_bound(s);it!=poly.end();++it){
		ans+=1LL*it->second*cmb((n-1+it->first-s)%Q,n-1)%Q;
		ans%=Q;
		if(ans<0) ans+=Q;
	}
	printf("%d\n",ans);
	return 0;
}