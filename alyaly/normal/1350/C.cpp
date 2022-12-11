#include<bits/stdc++.h>
//#pragma GCC optimize(2)
#define int long long
#include<vector>
//#define P 998244353
using namespace std;
//struct aa{
//	int nb,bh;
//} t[100001];
int T,n,a[200001],pr[200001],ppr,fpr[200001],d[200001],dm[200001],dm2[200001],ans=1,gm[200001];
void ycl(){
	for(int i=2;i<=500;i++){
		bool nfl=0;
		for(int j=2;j<=sqrt(i);j++){
			if(i%j==0){
				nfl=1;
				break;
			}
		}
		if(!nfl) pr[++ppr]=i;
	}
	for(int i=1;i<=ppr;i++) fpr[pr[i]]=i;
	for(int i=1;i<=200000;i++) dm[i]=dm2[i]=-1;
//	printf("%lld\n",ppr);
}
void fj(int x){
	for(int i=1;pr[i]<=sqrt(x)&&i<=ppr;i++){
		while(x%pr[i]==0){
			x/=pr[i];
			d[pr[i]]++;
		}
	}
	if(x!=1) d[x]++;
	for(int i=1;i<=ppr;i++){
//		if(!d[pr[i]]) continue;
		if(dm[pr[i]]==-1) dm[pr[i]]=d[pr[i]];
		else if(d[pr[i]]<=dm[pr[i]]){
			dm2[pr[i]]=dm[pr[i]];
			dm[pr[i]]=d[pr[i]];
		}
		else if(dm2[pr[i]]==-1||d[pr[i]]<=dm2[pr[i]]) dm2[pr[i]]=d[pr[i]];
	}
	if(x>500&&x!=1){
		gm[x]++;
	}
	
	if(x!=1) d[x]=0;
	for(int i=1;i<=ppr;i++) d[pr[i]]=0;
	return;
}
int gcd(int x,int y){
	if(x>y) swap(x,y);
	return (y%x==0)?x:gcd(y%x,x);
}
signed main(){
	ycl();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		fj(a[i]);
	}
//	vector<int> ve;
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			ve.push_back(a[i]/gcd(a[i],a[j])*a[j]);
//		}
//	}
//	int nans=ve[0];
//	for(int i=1;i<ve.size();i++) nans=gcd(nans,ve[i]);
//	printf("%lld\n",nans);
	for(int i=1;i<=500;i++){
		if(dm2[i]>0){
			for(int j=1;j<=dm2[i];j++) ans*=i;
		}
	}
	for(int i=1;i<=200000;i++){
		if(gm[i]>=n-1) ans*=i;
	}
	printf("%lld\n",ans);
	return 0;
}
/*

*/