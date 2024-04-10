#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1111111;
int gcd(int x,int y){
	if(!y)
		return x;
	return gcd(y,x%y);
}

int n,m,e,a[N],b[N];
LL g,nn,mm,nc,mc,k,w,s,p[N];
int main(){
	int i,x;
	LL o;
	scanf("%d%d%lld",&n,&m,&k);
	g=gcd(n,m);
	w=(LL)n*m/g;
	nn=n/g,mm=m/g;
	for(i=0;i<N;i++)
		if(((LL)i*mm-1)%nn==0)
			break;
	nc=i;
	for(i=0;i<N;i++)
		if(((LL)i*nn-1)%mm==0)
			break;
	mc=i;
	for(i=0;i<N;i++)
		a[i]=-1,b[i]=-1;
	for(i=0;i<n;i++)
		scanf("%d",&x),a[x]=i;
	for(i=0;i<m;i=i+1)
		scanf("%d",&x),b[x]=i;
	for(i=0;i<N;i=i+1){
		if(a[i]<0||b[i]<0)
			continue;
		if(a[i]%g!=b[i]%g)
			continue;
		o=(LL)a[i]/g*nc*mm+(LL)b[i]/g*mc*nn;
		o%=(LL)nn*mm;
		p[++e]=(LL)o*g+a[i]%g;//cout<<p[e]<<endl;
	}
	p[0]=-1;
	p[e+1]=w;
	sort(p+1,p+e+1);
	o=(k-1)/(w-e);
	s=o*w;
	k-=o*(w-e);
	for(i=1;i<=e+1;i=i+1){
		o=p[i]-p[i-1]-1;
		if(k<=o){
			cout<<s+p[i-1]+k+1;
			return 0;
		}
		k-=o;
	}
	return 0;
}