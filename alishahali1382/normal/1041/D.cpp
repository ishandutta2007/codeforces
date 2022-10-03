#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=500000000000000010LL;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 200 * 1000 + 10;

int n, h, j;
ll tmp, ans, r;

int A[MAXN][2];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &h);
	for (int i=0; i<n; i++) scanf("%d %d", &A[i][0], &A[i][1]);
	
	r=A[0][0]+h;
	
	for (int i=0; i<n; i++){
		if (i) r+=A[i][0]-A[i-1][1];
		for (; j<n && r>A[j][0]; j++) r+=A[j][1]-A[j][0];
		ans=max(ans, r-A[i][0]);
	}
	
	cout<<ans<<endl;
	
	return 0;
}