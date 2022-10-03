#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=500000000000000010LL;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 10010;

ll a, b, x, y;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>a>>b>>x>>y;
	ll g=__gcd(x, y);
	x/=g;
	y/=g;
	cout<<min(a/x, b/y)<<endl;
	
	return 0;
}