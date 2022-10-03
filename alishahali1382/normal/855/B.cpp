#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 100010;

int n;
ll p, q, r, ans=-inf*inf*3;
ll A[MAXN];
ll L[MAXN], R[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d %lld %lld %lld", &n, &p, &q, &r);
	for (int i=1; i<=n; i++) scanf("%lld", &A[i]);
	
	L[1]=A[1];
	R[n]=A[n];
	
	for (int i=2; i<=n; i++){
		if (p>0) L[i]=max(L[i-1], A[i]);
		else L[i]=min(L[i-1], A[i]);
	}
	for (int i=n-1; i; i--){
		if (r>0) R[i]=max(R[i+1], A[i]);
		else R[i]=min(R[i+1], A[i]);
	}
	
	for (int i=1; i<=n; i++){
		ans=max(ans, p*L[i] + q*A[i] + r*R[i]);
	}
	printf("%lld", ans);
	
	
	return 0;
}