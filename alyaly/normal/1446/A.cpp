//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
#define inf 9999999999999999
#define P 998244353
using namespace std;
struct na{
	int x,p;
}a[200001];
int T,n,K,ans,fl[200001],ffl;
bool comp(na x,na y){return x.x<y.x;
}
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>K;ans=ffl=0;int nans=0;
		for(int i=1;i<=n;i++)cin>>a[i].x,fl[i]=0,a[i].p=i;
		sort(a+1,a+n+1,comp);
		for(int i=n;i>=1;i--){
			if(ans+a[i].x<=K){
				ans+=a[i].x,fl[a[i].p]=1;nans++;
				if(ans>=(K+1)/2){
					ffl=1;printf("%lld\n",nans);
					for(int i=1;i<=n;i++)if(fl[i])printf("%lld ",i);printf("\n");
					break;
				}
			}
		}
		if(!ffl)printf("-1\n");
	}
	return 0;
}
/*

*/