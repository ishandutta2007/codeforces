#include<bits/stdc++.h>
#define ll long long
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
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n;
vector<pii> ans;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n){
		rep(j,1,n){
			if(i&1) printf("%lld ",(1ll<<(i+j-2)));
			else printf("0 ");
		}
		printf("\n");
	}
	fflush(stdout);
	int q;
	scanf("%d",&q);
	while(q--){
		ll x; scanf("%lld",&x);
		ans.clear();
		ans.pb(mp(1,1));
		rep(i,1,2*n-2){
			if((1ll<<i)&x) {
				if(ans.back().fi&1) ans.pb(mp(ans.back().fi,ans.back().se+1));
				else ans.pb(mp(ans.back().fi+1,ans.back().se));
			}else {
				if(!(ans.back().fi&1)) ans.pb(mp(ans.back().fi,ans.back().se+1));
				else ans.pb(mp(ans.back().fi+1,ans.back().se));
			}
		}
		for(auto u:ans) printf("%d %d\n",u.fi,u.se);
		fflush(stdout);
	}
	return 0;
}