#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000;
const int MAXN = 100010;

ll n, m, k;

pll f(ll x){
	ll res=0, cnt=0;
	for (int i=1; i<=min(n, x); i++){
		res+=min(x/i, m);
		if (min(x/i, m)*i==x) cnt++;
	}
	return {res-cnt+1, res};
}

ll bin(ll l, ll r){
	if (r-l<2) return l;
	ll mid=(r+l)/2;
	pll p=f(mid);
	ll low=p.first, up=p.second;
	//cerr<<mid<<' '<<low<<' '<<up<<endl;
	if (low<=k && k<=up) return mid;
	if (up<k) return bin(mid+1, r);
	return bin(l, mid);
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	if (m<n) swap(n, m);
	cout<<bin(1, n*m+1)<<endl;
	
	return 0;
}