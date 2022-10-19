#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n;

int check(int x){
	ll l = 0 , r = 4e4;
	while(r - l > 1){
		ll mid = l + r >> 1;
		if(mid * mid <= x)	l = mid;
		else	r = mid;
	}
	return (l * l == x);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		int valid = 0;
		cin >> n;
		if(n % 2 == 0)	valid |= check(n / 2);
		if(n % 4 == 0)	valid |= check(n / 4);
		cout << (valid ? "YES" : "NO") << endl;
	}

    return 0;
}
/*

*/