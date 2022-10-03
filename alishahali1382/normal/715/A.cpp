#include <bits/stdc++.h>

using namespace std;

typedef signed long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 1<<15;

ll n, k;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);	
	cin>>n;
	cout<<2<<endl;
	for (ll k=2; k<=n; k++){
		cout<<k*(k+1)*(k+1)-k+1<<endl;
	}

	return 0;
}