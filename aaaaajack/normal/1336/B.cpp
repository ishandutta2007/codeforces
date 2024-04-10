#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
long long sq(int x){
	return 1LL*x*x;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n[3];
		long long ans=1LL<<62;
		vector<int> v[3];
		for(int i=0;i<3;i++) scanf("%d",&n[i]);
		for(int i=0;i<3;i++){
			v[i].resize(n[i]);
			for(int j=0;j<n[i];j++){
				scanf("%d",&v[i][j]);
			}
			sort(all(v[i]));
		}
		for(int i=0;i<3;i++){
			for(int k=0;k<n[i];k++){
				for(int j=1;j<=2;j++){
					int nxt=(i+j)%3,pre=(i+j+j)%3;
					auto nit=lower_bound(all(v[nxt]),v[i][k]);
					auto pit=upper_bound(all(v[pre]),v[i][k]);
					if(nit==v[nxt].end() || pit==v[pre].begin()) continue;
					int x=v[i][k],y=*nit,z=*(--pit);
					ans=min(sq(x-y)+sq(y-z)+sq(z-x),ans);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}