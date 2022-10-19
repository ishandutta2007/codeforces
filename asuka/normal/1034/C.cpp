#include<bits/stdc++.h>
#define int long long
#define N 1000015
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
const int mod = 1e9+7;
int n,a[N],p[N],s[N],f[N],ans[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld",&n);
	rep(i,1,n) scanf("%lld",&a[i]);
	rep(i,2,n) scanf("%lld",&p[i]);
	per(i,1,n) a[p[i]] += a[i];
	rep(i,1,n) {
		int k = a[1]/__gcd(a[1],a[i]);
		if(k <= n) f[k]++;
	}
	// rep(i,1,n) assert(f[i] <= i);
	per(i,1,n) for(int j = i+i;j <= n;j += i) (f[j] += f[i]) %= mod;
	ans[1] = 1;
	rep(i,1,n){
		if(f[i] != i) continue; 
		for(int j = i+i;j <= n;j += i) if(f[j] == j) (ans[j] += ans[i]) %= mod;
	}
	int res = 0;
	rep(i,1,n) (res += ans[i]) %= mod;
	printf("%lld\n",res);
	return 0;
}