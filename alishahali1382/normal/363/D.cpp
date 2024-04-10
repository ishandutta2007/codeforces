#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000;
const int MAXN = 1000010;

ll n, m, a, ans, s, tmp;
ll A[MAXN];
ll B[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>a;
	for (int i=0; i<n; i++) cin>>A[i];
	for (int i=0; i<m; i++) cin>>B[i];
	sort(A, A+n);
	sort(B, B+m);
	ll l=0, r=min(n, m)+1;
	while (r-l>1){
		ll mid=(l+r)/2;
		ll val=0, xx=0;
		for (int i=n-mid, j=0; j<mid; i++, j++) val+=max(0LL, B[j]-A[i]);
		//cerr<<mid<<' '<<val<<endl;
		if (val<=a){
			ans=max(ans, mid);
			l=mid;
		}
		else r=mid;
	}
	for (int i=n-ans, j=0; j<ans; i++, j++) s+=B[j];
	cout<<ans<<' '<<max(0LL, min(s, s-a))<<endl;
	
	return 0;
}