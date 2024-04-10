#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=10000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 100010;

int n, k;
ll A[MAXN];
ll B[MAXN];

bool need(ll x){
	ll res=k;
	for (int i=0; i<n; i++){
		if (x*A[i]>B[i]) res-=x*A[i]-B[i];
		if (res<0) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i=0; i<n; i++) scanf("%lld", &A[i]);
	for (int i=0; i<n; i++) scanf("%lld", &B[i]);
	
	ll l=0, r=inf, mid;
	while (r-l>2){
		//printf("%lld %lld\n", l, r);
		mid=(r+l)/2;
		if (need(mid)) l=mid;
		else r=mid;
	}
	if (need(l+1)) printf("%lld\n", l+1);
	else printf("%lld\n", l);
	
	return 0;
}