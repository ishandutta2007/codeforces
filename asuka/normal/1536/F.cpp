#include<bits/stdc++.h>
#define ll long long
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
int n,fac[N],pd[N],ifac[N];
const int mod = 1e9+7;
int C(int a,int b){
	if(a < b || b < 0) return 0;
	return (ll) fac[a] * ifac[b] % mod * ifac[a-b] % mod;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	pd[0] = fac[0] = ifac[0] = ifac[1] = 1;
	rep(i,1,n+1) fac[i] = (ll) fac[i-1] * i % mod;
	rep(i,2,n+1) ifac[i] = (ll) (mod - mod/i) * ifac[mod%i] % mod;
	rep(i,2,n+1) ifac[i] = (ll) ifac[i-1] * ifac[i] % mod;
	rep(i,1,n+1) pd[i] = (ll) pd[i-1] * 2 % mod;
	int res = 0;
	rep(i,0,n){
		if((n-i)%2 == 0) res = (res + (ll) (C(n-i-1,i-1) + C(n-i,i)) * fac[n-i] % mod * 2 % mod) % mod;
		// printf("%d\n",res);
	}
	printf("%d\n",res);
	return 0;
}
/*
69420
629909355
*/