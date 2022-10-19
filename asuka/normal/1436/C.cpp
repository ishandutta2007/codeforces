#include<bits/stdc++.h>
#define int long long
#define N 1005
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
using namespace std;
const int mod = 1e9+7;
int n,x,pos,a[N],fac[N],inv[N];
int qpow(int a,int b){
	int res = 1;
	while(b){
		if(b&1) res = (1ll*res*a)%mod;
		a = (1ll*a*a)%mod;
		b >>= 1;
	}
	return res;
}
int C(int n,int m){
	if(n == 0) return 1;
	if(n == 1) return m;
	return (1ll*C(n-1,m-1)*m)%mod;
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld%lld%lld",&n,&x,&pos);
 	fac[0] = inv[0] = 1;
 	rep(i,1,n) fac[i] = (fac[i-1]*i)%mod;
 	rep(i,1,n) inv[i] = qpow(fac[i],mod-2)%mod;
 	int l = 0,r = n;
 	//cout << qpow(2,10)-1 << endl;
 	int Big,Sma;Big = Sma = 0;
 	while(l < r){
 		int mid = (l+r)>>1;
 		if(mid <= pos){
 			if(mid < pos) Sma++;
 			l = mid+1;
 		}else{
 			Big++;
 			a[mid] = 1;
 			r = mid;
 		}
 	}
 	// cout << l << endl;
 	// a[pos] = 100;
 	// int Big,Sma;Big = Sma = 0;
 	// rep(i,0,n-1){
 	// 	cout << a[i] << ' ';
 	// 	if(a[i] == 1) Big++;
 	// 	if(a[i] == -1) Sma++;
 	// }
 	int ans = ((1ll*C(Big,n-x)*C(Sma,x-1))%mod*fac[n-1-Big-Sma])%mod;
 	printf("%lld\n",ans);
	return 0;
}