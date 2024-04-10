#include<bits/stdc++.h>
#define int long long
#define N 5005
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
int t,n,tag[N],s[N],f[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		rep(i,1,n) scanf("%lld",&tag[i]);
		rep(i,1,n) scanf("%lld",&s[i]);
		rep(i,0,n) f[i] = 0;
		rep(i,1,n) per(j,1,i-1){
			if(tag[i]==tag[j]) continue;
			int fi = f[i],fj = f[j],val = abs(s[i]-s[j]);
			f[i] = max(f[i],fj+val);
			f[j] = max(f[j],fi+val);
		}
		printf("%lld\n",*max_element(f+1,f+n+1));
	}
	return 0;
}