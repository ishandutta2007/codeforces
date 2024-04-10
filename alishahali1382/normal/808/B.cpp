#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 200010;

int n, k;
ll l, r, x;
ld ans, tmp;

int A[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &k);
	tmp=n-k+1;
	for (int i=0; i<n; i++) scanf("%d", &A[i]);
	for (int i=0; i<k; i++) x+=A[i];
	ans+=x/tmp;
	for (int i=k; i<n; i++){
		x+=A[i]-A[i-k];
		ans+=x/tmp;
	}
	cout<<setprecision(10)<<fixed<<ans<<endl;
	
	return 0;
}