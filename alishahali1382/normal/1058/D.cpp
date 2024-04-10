#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=10000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 110;

ll n, m, k, s;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	if (k==2){
		cout<<"YES"<<endl;
		cout<<"0 0"<<endl;
		cout<<n<<" 0"<<endl;
		cout<<"0 "<<m<<endl;
		return 0;
	}
	if ((n*m*2)%k){
		cout<<"NO"<<endl;
		return 0;
	}
	s=n*m*2/k;
	ll g=__gcd(n, s);
	ll x=g, y=s/g;
	if (x>n || y>m){
		g=__gcd(m, s);
		x=s/g;
		y=g;
	}
	cout<<"YES"<<endl;
	cout<<"0 0"<<endl;
	cout<<"0 "<<y<<endl;
	cout<<x<<" 0"<<endl;
	
	return 0;
}