#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
const int MOD=1e9+7,MAXN=1000000;

int n,K,dp[MAXN+1];
pii a[MAXN+1];
lli L;

int main() {
	scanf("%d%lld%d",&n,&L,&K);
	for(int i=0;i<n;i++) scanf("%d",&a[i].fi),a[i].se=i;

	lli d=L/n;
	int p=L%n;
	K = min(1ll*K,d+1);
	sort(a,a+n);

	vector<pii> arr;
	int fc=0,sc=0;
	for(int i=0;i<n;i++) {
		if(i!=0 && a[i-1].fi!=a[i].fi){
			arr.push_back({fc,sc});
			fc=1; sc=a[i].se<p;
		} else {
			fc++; sc+=a[i].se<p;
		}
	}
	arr.push_back({fc,sc});

	int ans=0;
	for(int i=0;i<sz(arr);i++) {
		int ad = (1ll*(d-1+1)*arr[i].fi%MOD + arr[i].se)%MOD;
		ans = (ans + ad)%MOD;
		dp[1] = (dp[1] + arr[i].fi)%MOD;
		for(int x=2;x<=K;x++) {
			ad = (1ll*(d-x+1)*arr[i].fi%MOD*dp[x-1]%MOD + 1ll*arr[i].se*dp[x-1]%MOD)%MOD;
			ans = (ans + ad)%MOD;
			dp[x] = (dp[x] + 1ll*arr[i].fi*dp[x-1]%MOD)%MOD;
		}
	}
	printf("%d\n",ans);
	
	return 0;
}