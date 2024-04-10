#include<bits/stdc++.h>
#define int long long
#define N 300015
#define mod 998244353
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,m,inv[N],fac[N],a[25],b[25],dp[45][N],l[N],r[N],d[N];
bool vis[N];
int qpow(int a,int b){
	int res = 1;
	while(b){
		if(b&1) res = (res*a)%mod;
		a = a*a%mod;
		b>>=1;
	}
	return res%mod;
}
int C(int n,int m){
	if(n<0||m<0||n>m) return 0;
	return (fac[m]%mod*inv[n]%mod)*inv[m-n]%mod;
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	cin>>n>>m;
 	fac[0] = inv[0] = 1;
 	rep(i,1,n) fac[i] = fac[i-1]*i%mod;
 	rep(i,1,n) inv[i] = qpow(fac[i],mod-2);
 	rep(i,1,n){
 		cin>>l[i]>>r[i];
 		d[l[i]]++,d[r[i]+1]--;
 	}
 	rep(i,1,m) cin>>a[i]>>b[i];
 	rep(i,1,n) d[i] += d[i-1];
 	rep(i,1,n){
 		rep(j,0,m*2){
 			dp[j][i] = (dp[j][i-1] + C(i-j,d[i]-j))%mod;
 		}
 	}
 	set<int> S;
 	int top = (1<<m)-1;
 	int ans = 0;
 	rep(i,0,top){
 		S.clear();
 		int le = 1,ri = n;
 		rep(j,1,m){
 			if((1<<(j-1))&i){
 				S.insert(a[j]);S.insert(b[j]);
 				le = max({le,l[a[j]],l[b[j]]});
 				ri = min({ri,r[a[j]],r[b[j]]});
 			}
 		}
 		int sum = S.size(),res = (le <= ri)?(dp[sum][ri]-dp[sum][le-1]+mod)%mod:0;
 		if(__builtin_popcount(i) & 1) ans = (ans-res+mod)%mod;
 		else ans = (ans+res)%mod;
 	}
 	cout << ans << endl;
	return 0;
}