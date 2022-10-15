#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".IN", "r", stdin); freopen(x ".OUT", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
#ifdef LOCAL
typedef double ld;
#else
typedef double ld;
#endif
typedef vector<int>::iterator vit;
typedef pair<ld, int> li;
const ld E = 1e-8;

#ifdef LOCAL
const int MAX = 1e4;
#else
const int MAX = 3e4 + 1;
#endif

int powa(int a, int x){
	int ans = 1;
	for(int i=  0; i < x; i++)
		ans *= a;
	return ans;
}

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	int k = 0;
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
			for(int z = 1; z <= 3; z++)
				if(i + j + z == 6)
					k++;

	ll ans = 1;
	for(int i = 0; i < 3 * n; i++){
		ans = (ans * 3) mod;
	}

	ll r = 1;
	for(int i = 0; i < n; i++)
		r = (r * k) mod;

	cout << (ans + (int) 1e9 + 7 - r) mod;
}