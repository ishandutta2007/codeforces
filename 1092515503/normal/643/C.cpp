#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,t[200100],ll,rr,sum;
double inv,res,f[200100],g[200100];
inline double calc(int l,int r){
	while(ll>l){
		--ll;
		inv+=1.0/t[ll];
		sum+=t[ll];
		res+=inv*t[ll];
	}
	while(rr<r){
		++rr;
		inv+=1.0/t[rr];
		sum+=t[rr];
		res+=1.0*sum/t[rr];
	}
	while(ll<l){
		res-=inv*t[ll];
		sum-=t[ll];
		inv-=1.0/t[ll];
		ll++;
	}
	while(rr>r){
		res-=1.0*sum/t[rr];
		sum-=t[rr];
		inv-=1.0/t[rr];
		rr--; 
	}
	return res;
}
inline void func(int l,int r,int L,int R){
	if(l>r||L>R)return;
	register int mid=(l+r)>>1;
	register int mp;
	register double mn=9e18;
	for(register int i=L;i<=R;i++)if(f[i]+calc(i+1,mid)<mn)mn=f[i]+calc(i+1,mid),mp=i;
	g[mid]=mn;
	func(l,mid-1,L,mp),func(mid+1,r,mp,R); 
}
inline void read(int &x){
	x=0;
	register char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
signed main(){
	read(n),read(m);
	for(register int i=1;i<=n;i++)read(t[i]),inv+=1.0/t[i],sum+=t[i],res+=1.0*sum/t[i],f[i]=res;
	ll=1,rr=n;
	while(--m)func(1,n,0,n-1),memcpy(f,g,sizeof(g));
	printf("%lf\n",f[n]);
	return 0;
}