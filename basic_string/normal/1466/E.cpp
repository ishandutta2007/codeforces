#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const ull P=1e9+7,N=5e5+3;
ull a[N],c[99];
int main(){
	int T,n,i,j,k;
	ull u,v,s;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),s=0;
		for(i=1;i<=n;++i)scanf("%llu",a+i);
		memset(c,0,sizeof(c));
		for(i=0;i<62;++i)for(j=1;j<=n;++j)if(a[j]&(1ull<<i))++c[i];
		for(i=1;i<=n;++i){
			u=v=0;
			for(j=0;j<62;++j){
				if(a[i]&(1ull<<j)){
					u=(u+(1ull<<j)%P*c[j])%P;
					v=(v+(1ull<<j)%P*n)%P;
				}else{
					v=(v+(1ull<<j)%P*c[j])%P;
				}
			}
			s=(s+u*v)%P;
		}cout<<s<<'\n';
	}
	return 0;
}