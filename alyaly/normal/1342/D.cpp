#include<bits/stdc++.h>
#include<vector>
#define int long long
using namespace std;
int n,K,a[200001],b[200001],sz[200001],psz;
vector<int> ve[200001];
signed main(){
	cin>>n>>K;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=K;i++) cin>>b[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		if(psz==0){
			sz[++psz]--;
			ve[psz].push_back(a[i]);
		}else{
			int np=upper_bound(sz+1,sz+psz+1,-b[a[i]])-sz;
			if(np>psz) psz=np;
			sz[np]--;
			ve[np].push_back(a[i]);
		}
	}
	printf("%lld\n",psz);
	for(int i=1;i<=psz;i++){
		printf("%lld ",ve[i].size());
		for(int j=0;j<ve[i].size();j++){
			printf("%lld ",ve[i][j]);
		}
		printf("\n");
	}
	return 0;
}
/*

*/