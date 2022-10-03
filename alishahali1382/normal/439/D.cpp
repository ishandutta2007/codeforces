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

ll n, m;
ll A[MAXN];
ll B[MAXN];

ll calc(ll x){
	ll res=0;
	for (int i=0; i<n; i++) res+=max(0LL, x-A[i]);
	for (int i=0; i<m; i++) res+=max(0LL, B[i]-x);
	return res;
}
ll ternary(ll l, ll r){
	if (r-l==1) return calc(l);
	if (r-l==2) return min(calc(l), calc(l+1));
	ll dis=(r-l)/3;
	ll m1=l+dis, m2=l+2*dis;
	if (calc(m1)<calc(m2)) return ternary(l, m2);
	return ternary(m1, r);
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<n; i++) cin>>A[i];
	for (int i=0; i<m; i++) cin>>B[i];
	
	cout<<ternary(0, inf)<<endl;
	
	//cout<<calc(3)<<endl;
	
	return 0;
}