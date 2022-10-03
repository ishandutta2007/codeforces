#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000000007;
const int MAXN = 2010;

ll n, k, ans, u, v;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	ll i=1;
	for (; i*i<n; i++){
		if (n%i==0) ans+=2;
	}
	if (i*i==n) ans++;
	
	cout<<ans<<endl;
	return 0;
}