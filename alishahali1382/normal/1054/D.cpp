#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 200010;

ll n, k, kk, tmp, x, y;
ll A[MAXN];
ll ps[MAXN];

map<ll, ll> mp;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	ll ans=n*(n+1)/2, out;
	kk=(1LL<<k)-1;
	mp[0]=1;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		tmp=A[i]^kk;
		x=ps[i-1]^A[i];
		y=ps[i-1]^tmp;
		if (mp[x]<mp[y]) ps[i]=x;
		else ps[i]=y;
		ans-=mp[ps[i]]++;
	}
	cout<<ans<<endl;
	return 0;
}