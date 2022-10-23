#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,cnt[105];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;++i){
			int x;
			scanf("%d",&x);
			++cnt[abs(x)];
		}
		int ans=0;
		if(cnt[0])ans=1;
		for(int i=1;i<=100;++i)ans+=min(2,cnt[i]);
		printf("%d\n",ans);
	}
    return 0;
}