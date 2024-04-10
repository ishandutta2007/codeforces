#include<bits/stdc++.h>
//#pragma GCC optimize(2)
//#define int long long
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
int T,n,a[200001],ans;
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		ans=1;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(i>=a[i]) ans=max(ans,i+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*

*/