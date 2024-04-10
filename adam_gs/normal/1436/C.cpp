#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
typedef long long ll;
const int LIM=1e3+7;
const ll MOD=1e9+7;
ll sil[LIM], osil[LIM];
ll pot(ll a,ll b){ll ans=1;while(b)if(b%2){ans=ans*a%MOD;--b;}else{a=a*a%MOD;b/=2;}return ans;}
ll C(ll n, ll k) {
	if(k>n) return 0;
	return sil[n]*osil[k]%MOD*osil[n-k]%MOD;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	sil[0]=osil[0]=1;
	rep(i, LIM-1) {
		sil[i+1]=sil[i]*(i+1)%MOD;
		osil[i+1]=pot(sil[i+1], MOD-2);
	}
	int x, n, pos;
	cin >> n >> x >> pos;
	int pduze=0, pmale=0, left=0, right=n, imale=x-1, iduze=n-x;
	while(left<right) {
		int middle=(left+right)/2;
		if(middle<=pos) {
			if(middle<pos) ++pmale;
			left=middle+1;
		} else {
			++pduze;
			right=middle;
		}
	}
	int izost=n-pduze-pmale-1;
	ll ans=C(imale, pmale)*sil[pmale]%MOD*C(iduze,pduze)%MOD*sil[pduze]%MOD*sil[izost]%MOD;
	cout << ans;
}