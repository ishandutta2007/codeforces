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
typedef unsigned short int usi;

#ifdef LOCAL
const int MAX = 1e4;
#else
const int MAX = 3e4 + 1;
#endif

bool prime(int a) {
	int q = sqrt(a);
	for (int i = 2; i <= q; i++)
		if (a % i == 0)
			return false;
	return a != 1;
}

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	if(prime(n)) {
		cout << 1 << endl << n << endl;
	} else {
		cout << 3 << endl;
		for(int i = n - 2; i >= 0; i -= 2) {
			if(prime(i)) {
				int q = n - i;
				for(int j = 3; j <= q - 3; j++)
				if(prime(j) && prime(q - j)) {
					cout << i << " " << j << " " << q - j << endl;
					return 0;
				}
			}
		}
	}

}