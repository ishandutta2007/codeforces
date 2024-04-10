#include<bits/stdc++.h>
#define int long long
#define N 1000000
#define inf 999999999
using namespace std;
int L,R,pans,n,gg;
struct bian{
	int p,q,r;
}bi[N+1];
void lb(int np,int nq,int nr){bi[++pans]=(bian){np,nq,nr};}
void ycl(){
	for(int i=21;i>=2;i--){
		for(int j=i+1;j<=22;j++){
			if(j==22)lb(i,j,1);
			else lb(i,j,1<<(21-j));
		}
	}
}
void pp(){
	printf("YES\n%lld %lld\n",n,pans);
	for(int i=1;i<=pans;i++)printf("%lld %lld %lld\n",bi[i].p,bi[i].q,bi[i].r);
}
signed main(){
	n=22;
	cin>>L>>R;int nl=L;
	ycl();
	if(L!=1){
		for(int i=0;i<=19;i++){
			if((R-L+1)&(1<<i)){
				lb(1,21-i,nl-1);nl+=(1<<i);
			}
		}
	}else{
		lb(1,22,1),nl++;
		for(int i=0;i<=19;i++){
			if((R-L)&(1<<i)){
				lb(1,21-i,nl-1);nl+=(1<<i);
			}
		}
	}
	pp();
	return 0;
}