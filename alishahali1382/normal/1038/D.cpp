#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 500 * 1000 + 10;

ll n, mn=inf, mx=-inf, ans;
ll A[MAXN];

ll ab(ll a){ return max(a, -a);}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		mn=min(mn, A[i]);
		mx=max(mx, A[i]);
		ans+=ab(A[i]);
	}
	if (n==1){
		cout<<A[1]<<endl;
		return 0;
	}
	if (mn<=0 && mx>=0){
		cout<<ans<<endl;
		return 0;
	}
	mn=inf;
	for (int i=1; i<=n; i++) mn=min(mn, ab(A[i]));

	cout<<ans-mn*2<<endl;
	
	return 0;
}