#include<bits/stdc++.h>
using namespace std;
#define int long long
int sy,a,b,n,pos[400100],sum[400100],q;
double getpp(int x,int y,int z){
	return 1.0*sy/y*(x-z)+z;
}
int getlp(int x,int y){
	if(getpp(x,y,pos[1])>a)return 1;
	if(getpp(x,y,pos[2*n])<a)return -1;
	int l=1,r=2*n;
	while(l<r){
		int mid=(l+r)>>1;
		if(getpp(x,y,pos[mid])>a)r=mid;
		else l=mid+1;
	}
	return r;
}
int getrp(int x,int y){
	if(getpp(x,y,pos[1])>b)return -1;
	if(getpp(x,y,pos[2*n])<b)return 2*n;
	int l=1,r=2*n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(getpp(x,y,pos[mid])<b)l=mid;
		else r=mid-1;
	}
	return l;
}
signed main(){
	scanf("%lld%lld%lld",&sy,&a,&b);
	scanf("%lld",&n);
	for(int i=1;i<=2*n;i++)scanf("%lld",&pos[i]);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+pos[i*2]-pos[i*2-1];
	scanf("%lld",&q);
	for(int i=1,x,y;i<=q;i++){
		scanf("%lld%lld",&x,&y);
		int l=getlp(x,y),r=getrp(x,y);
//		printf("L%d,R%d\n",l,r);
		if(l==-1||r==-1){puts("0");continue;}
		if(l>r){
			if(r&1)printf("%lld\n",b-a);
			else puts("0");
			continue;
		}
		double s1=0,s2=0;
		if(!(l&1))s1+=getpp(x,y,pos[l])-a;
		else l--;
		l>>=1;
		if(r&1)s1+=b-getpp(x,y,pos[r]),r--;
		r>>=1;
		s2=sum[r]-sum[l];
		s2*=1.0*(y-sy)/y;
		printf("%lf\n",s1+s2);
	}
	return 0;
}