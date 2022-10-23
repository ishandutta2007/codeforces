#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#define fi   first
#define se   second
using namespace std;
int T,n,a[105][105];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)scanf("%1d",a[i]+j);
		}
		int ans=0;
		for(int i=1;i<=n/2;++i){
			for(int j=1;j<=(n+1)/2;++j){
				int cnt[2]={};
				++cnt[a[i][j]];
				++cnt[a[j][n+1-i]];
				++cnt[a[n+1-i][n+1-j]];
				++cnt[a[n+1-j][i]];
				ans+=min(cnt[0],cnt[1]);
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}