#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
#define x first
#define y second
typedef unsigned long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef ii point;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
const ld E = 1e-8;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 2000;
#else
const ll MAX = 2000;
#endif

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	cout << "2000\n";

	for(int i = 1; i <= 1000; i++){
		cout << i << " 1 " << i << " 2\n";
	}
	for(int i = 1000; i >= 1; i--){
		cout << i << " 1 " << i << " 2\n";
	}

}