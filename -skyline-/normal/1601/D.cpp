#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#define X    first
#define Y    second
#pragma GCC optimize("O2")
using namespace std;
int n,d,dp[500005],N,cnt,_;
pair<pair<int,int>,int> p[500005];
int main(){
	scanf("%d%d",&N,&d);
	for(int i=1;i<=N;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x<d) continue;
		y=max(y,d);
		if(x<y)p[++n]=mp(mp(y,x),0);
		else p[++n]=mp(mp(x,y),1);
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;++i){
		dp[i]=dp[i-1];
		_=max(_,p[i].X.Y);
		if(!p[i].Y){
			if(p[i].X.Y>=_){
				int o=0;
				for(int z=262144;z;z>>=1)if((o|z)<=n&&p[o|z].X.X<=p[i].X.Y)o|=z;
				dp[i]=max(dp[i],dp[o]+1);
			}
		}
		else ++cnt;
	}
	printf("%d\n",dp[n]+cnt);
    return 0;
}