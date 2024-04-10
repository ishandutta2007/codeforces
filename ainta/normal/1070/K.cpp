#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,n) for(int i=1;i<=n;i++)

int n, k;
ll A[100010];

int main() {
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++) {
		int x; scanf("%d", &x);
		A[i] = A[i-1] + x;
	}
	if(A[n] % k != 0) { puts("No"); return 0; }
	vector <int> ans;
	ll t = A[n] / k;
	for(int i=1;i<=n;i++) {
		if(A[i] % t == 0) ans.pb(i);
	}
	if(szz(ans) != k) {
		puts("No"); return 0;
	}
	puts("Yes");
	for(int i=0;i<szz(ans);i++) {
		int a = ans[i];
		if(i > 0) a -= ans[i-1];
		printf("%d ", a);
	} puts("");
}