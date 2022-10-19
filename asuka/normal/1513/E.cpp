#include<bits/stdc++.h>
#define ll long long
#define N 200015
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
const int mod = 1e9+7;
using namespace std;
int n,a[N],pos,neg,zer,fac[N],inv[N];
int qpow(int a,int b){
	int res = 1;
	while(b){
		if(b&1) res = 1ll*res*a%mod;
		a = 1ll*a*a%mod;
		b >>= 1;
	}
	return res;
}
ll sum;
map<int,int> cnt;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	fac[0] = 1;
	rep(i,1,n) fac[i] = (1ll*fac[i-1]*i)%mod;
	inv[0] = 1;
	rep(i,1,n) inv[i] = qpow(fac[i],mod-2);
	rep(i,1,n) scanf("%d",&a[i]),sum += a[i];
	if(sum%n != 0){
		puts("0");
		return 0;
	}
	sum /= n;
	rep(i,1,n) {
		a[i] -= sum;
		if(a[i] == 0) zer++;
		else if(a[i] < 0) neg++;
		else pos++;
	}
	rep(i,1,n) cnt[a[i]]++;
	if(pos <= 1 || neg <= 1){
		int res = fac[n];
		for(auto x:cnt){
			res = (1ll*res*inv[x.se])%mod;
		}
		printf("%d\n",res);
	}else{
		int res = (1ll*fac[pos]*fac[neg])%mod;
		for(auto x:cnt){
			if(x.fi != 0) 
				res = (1ll*res*inv[x.se])%mod; 
		}
		// C(n,zer);
		res = (1ll*res*fac[n])%mod;
		res = (1ll*res*inv[zer])%mod;
		res = (1ll*res*inv[n-zer])%mod;
		res = (res+res)%mod;
		printf("%d\n", res);
	}
	return 0;
}