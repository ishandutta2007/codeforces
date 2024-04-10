#include<bits/stdc++.h>
#define int long long
#define N
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int t,p,a,b,c;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lld%lld",&p,&a,&b,&c);
		printf("%lld\n",min({(a-(p%a))%a,(b-(p%b))%b,(c-(p%c))%c}));
	}
	return 0;
}