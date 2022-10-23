#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,cnt[3],a[100005];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;++i){
			int x;
			scanf("%d",&x);
			a[i]=x;
			if(x<3)++cnt[x];
		}
		sort(a+1,a+n+1);
		bool ok=1;
		for(int i=1;i<n;++i)if(a[i]+1==a[i+1])ok=0;
		if(!cnt[1])puts("YES");
		else if(!cnt[0]&&ok)puts("YES");
		else puts("NO");
	}
    return 0;
}