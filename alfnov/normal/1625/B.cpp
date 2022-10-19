#include<bits/stdc++.h>
using namespace std;
int a[200005],mn[200005],mx[200005];
set<int>se[200005];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i],se[a[i]].emplace(i);
		int ans=-1;
		for(int i=1;i<=n;++i){
			int L=i;
			auto it=se[a[i]].upper_bound(i);
			if(it==se[a[i]].end())continue;
			int R=*it;
			ans=max(ans,n+L-R);
		}
		for(int i=1;i<=n;++i)se[a[i]].clear();
		cout<<ans<<endl;
	}
	return 0;
}