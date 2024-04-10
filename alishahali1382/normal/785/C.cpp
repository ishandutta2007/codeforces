#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000000;
const int mod = 998244353;
const int MAXN = 200010;

ll n, m, ans;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	if (n<=m){
		cout<<n<<endl;
		return 0;
	}
	n-=m+1;
	ll y=sqrt(8*n+1);
	ll x=(y-1)/2;
	while ((2*x+1)*(2*x+1)<=8*n+1) x++;
	//cerr<<x<<endl;
	cout<<m+x<<endl;
	return 0;
}