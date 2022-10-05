#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int a[N],l[N],r[N],ld[N],rd[N],lv[N][2],rv[N][2],lw[N][2],rw[N][2],lg[N][2],rg[N][2],pr[N],sf[N],ll[N],rr[N];
int main(){
	int n,i,j,k,s=0;
	scanf("%d",&n),memset(lv,-9,sizeof lv),memset(rv,-9,sizeof rv);
	memset(lg,-9,sizeof lg);memset(rg,-9,sizeof rg);
	memset(lw,-9,sizeof lw);memset(rw,-9,sizeof rw);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	ll[1]=1,rr[n]=n;
	for(i=2;i<=n;++i){
		if(a[i-1]>a[i]){
			ld[i]=ld[i-1]+1;
		}
	}
	for(i=n-1;i;--i){
		if(a[i+1]>a[i]){
			rd[i]=rd[i+1]+1;
		}
	}
	for(i=1;i<=n;++i)pr[i]=max(pr[i-1],max(ld[i],rd[i]));
	for(i=n;i;--i)sf[i]=max(sf[i+1],max(ld[i],rd[i]));
	lv[1][1]=max(ld[1],rd[1]);
	lg[1][1]=ld[1];
	rv[n][n&1]=max(ld[n],rd[n]);
	rg[n][n&1]=rd[n];
	for(i=2;i<=n;++i){
		if(a[i-1]<a[i]){
			l[i]=l[i-1]+1,ll[i]=ll[i-1];
			lv[i][0]=lv[i-1][0];
			lv[i][1]=lv[i-1][1];
			lv[i][i&1]=max(lv[i][i&1],max(ld[i],rd[i]));
			lg[i][0]=lw[i][0]=lg[i-1][0];
			lg[i][1]=lw[i][1]=lg[i-1][1];
			lg[i][i&1]=max(lg[i][i&1],ld[i]);
		}else{
			ll[i]=i;
			lv[i][i&1]=max(ld[i],rd[i]);
			lg[i][i&1]=ld[i];
		}
	}
	for(i=n-1;i;--i){
		if(a[i+1]<a[i]){
			r[i]=r[i+1]+1,rr[i]=rr[i+1];
			rv[i][0]=rv[i+1][0];
			rv[i][1]=rv[i+1][1];
			rv[i][i&1]=max(rv[i][i&1],max(ld[i],rd[i]));
			rg[i][0]=rw[i][0]=rg[i+1][0];
			rg[i][1]=rw[i][1]=rg[i+1][1];
			rg[i][i&1]=max(rg[i][i&1],rd[i]);
		}else{
			rr[i]=i;
			rv[i][i&1]=max(ld[i],rd[i]);
			rg[i][i&1]=rd[i];
		}
	}
	for(i=1;i<=n;++i){
		
		if(max(l[i],r[i])>max(pr[ll[i]-1],sf[rr[i]+1])&&r[i]>lv[i][!(i&1)]&&l[i]>rv[i][!(i&1)]
		&&max(l[i],r[i])>max(lw[i][i&1],rw[i][i&1]))++s;
	}
	printf("%d",s);
	return 0;
}