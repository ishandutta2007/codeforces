#include<bits/stdc++.h>
using namespace std;
vector<int>g[11],h[11];
vector<long long>se[11];
long long zt[11];
long long qz[41],hz[41];
int main(){
	int n,k;
	cin>>n>>k;
	if(n==1){
		printf("ACCEPTED\n");
		return 0;
	}
	long long Z=(1ll<<n)-1;
	se[0].emplace_back(0ll);
	for(int i=1;i<=k;++i){
		zt[i]=zt[i-1];
		int gs;
		scanf("%d",&gs);
		int gg=0;
		qz[0]=Z,hz[gs+1]=0;
		for(int j=0;j<gs;++j){
			int aa;
			scanf("%d",&aa);
			g[i].emplace_back(aa);
			long long tz=zt[i];
			zt[i]|=1ll<<(n-aa);
			if(zt[i]!=tz)++gg;
			qz[j+1]=qz[j]^(1ll<<(n-aa));
		}
		for(int j=gs-1;j>=0;--j)
			hz[j+1]=hz[j+2]|(1ll<<(n-g[i][j]));
		for(auto cu:se[i-1]){
			int ss=__builtin_popcountll(cu&hz[1]);
			for(int tt=ss;tt<=ss+gg;++tt){
				if(tt>gs)break;
				long long zz=cu;
				zz&=qz[gs-tt];
				zz|=hz[gs-tt+1];
				se[i].emplace_back(zz);
			}
		}
	}
	if(zt[k]!=Z){
		printf("REJECTED\n");
		return 0;
	}
	for(auto cu:se[k]){
		if((cu+1)&cu){
			printf("REJECTED\n");
			return 0;
		}
	}
	printf("ACCEPTED\n");
	return 0;
}