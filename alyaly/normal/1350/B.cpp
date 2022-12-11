#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define int long long
#include<vector>
//#define P 998244353
using namespace std;
//struct aa{
//	int nb,bh;
//} t[100001];
int T,n,a[100001],s[100001],ans;
vector<int> ve[100001];
void ycl(){
	for(int i=1;i<=100000;i++){
		for(int j=1;i*j<=100000;j++){
			ve[i*j].push_back(i);
		}
	}
	return;
}
signed main(){
	ycl();
	cin>>T;
	while(T--){
		cin>>n;
		ans=1;
		for(int i=1;i<=n;i++) cin>>a[i];
		memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++){
			s[i]=1;
			for(int j=0;j<ve[i].size();j++){
				if(a[i]>a[ve[i][j]]) s[i]=max(s[i],s[ve[i][j]]+1);
			}
		}
		for(int i=1;i<=n;i++) ans=max(ans,s[i]);
		printf("%lld\n",ans);
//		for(int i=1;i<=n;i++){
//			cin>>t[i].nb;
//			t[i].bh=i;
//		}
//		sort(t+1,t+n+1,comp);
//		for(int i=1;i<=n;i++){
//			
//		}
	}
	return 0;
}
/*

*/