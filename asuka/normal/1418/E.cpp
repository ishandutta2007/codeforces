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
int n,m,d[N],a[N],b[N],pre[N],suf[N];
int qpow(int a,int b){
	int res = 1;
	while(b){
		if(b&1) res = (res*a)%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return res;
}


signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld%lld",&n,&m);
 	rep(i,1,n) scanf("%lld",&d[i]);
 	rep(i,1,m) scanf("%lld%lld",&a[i],&b[i]);
 	sort(d+1,d+n+1); 
 	rep(i,1,n) pre[i] = pre[i-1]+d[i]%mod;
 	per(i,1,n) suf[i] = suf[i+1]+d[i]%mod;
 	rep(i,1,m){
 		int pos = lower_bound(d+1,d+n+1,b[i])-d;
 		//cout << pos << endl;
 		int k = n-pos+1;
 		if(a[i] > k || a[i] == n){
 			//puts("fuck");
 			printf("0\n");
 		}else{
 			int pr = ((pre[pos-1]*(k-a[i]+1)%mod)%mod*qpow(k+1,mod-2)%mod)%mod,su = ((suf[pos]*(k-a[i])%mod)%mod*qpow(k,mod-2)%mod)%mod;
 			//cout <<pr << ' ' << su << endl;
 			printf("%lld\n", (pr+su)%mod);
 		}
 	}
	return 0;
}