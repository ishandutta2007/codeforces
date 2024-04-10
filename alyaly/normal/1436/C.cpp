#include<bits/stdc++.h>
#define int long long
#define P 1000000007
using namespace std;
int n,x,p,m1,m2;
int jc[1001],njc[1001];
int ksm(int x,int y){int nans=1;for(;y;y>>=1,x=x*x%P)if(y&1)nans=nans*x%P;return nans;
}
int qny(int x){return ksm(x,P-2);
}
int C(int x,int y){if(x<y)return 0;return jc[x]*njc[y]%P*njc[x-y]%P;}
signed main(){
	cin>>n>>x>>p;jc[0]=njc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%P,njc[i]=qny(jc[i]);
	int l=0,r=n,mid;
	while(l!=r){
		mid=(l+r)/2;
		if(p>=mid){
			if(p!=mid)m1++;
			l=mid+1;
		}
		else{
			if(p!=mid)m2++;
			r=mid;
		}
	}
	printf("%lld\n",jc[n-m1-m2-1]*C(x-1,m1)%P*jc[m1]%P*C(n-x,m2)%P*jc[m2]%P);
	return 0;
}