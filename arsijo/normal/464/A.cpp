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
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef map<int, int>::iterator mit;
const ld E = 1e-4;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 1e5;
//#define DEBUG
#else
const ll MAX = 5e5;
#endif

int main() {

	sync;
	cout.precision(20);

#ifdef LOCAL
	srand(time(NULL));
	input;
#else

#endif

	int n, q;
	cin >> n >> q;

	string st;
	cin >> st;

	char *s = new char[n + 2];
	s += 2;
	for(int i = 0; i < n; i++)
		s[i] = st[i];
	s[-1] = s[-2] = '!';

	for(int i = n - 1; i >= 0; i--) {
		for(int j = (s[i] - 'a' + 1); j < q; j++) {
			char c = 'a' + j;
			if(c != s[i - 1] && c != s[i - 2]) {
				s[i] = c;
				bool bol = true;
				for(int z = i + 1; z < n; z++) {
					bool check = false;
					for(int q = 0; q < n; q++) {
						char c = 'a' + q;
						if(c != s[z - 1] && c != s[z - 2]) {
							check = true;
							s[z] = c;
							break;
						}
					}
					if(!check) {
						bol = false;
						break;
					}
				}
				if(!bol) {
					for(int z = i; z < n; z++)
					s[i] = st[i];
					continue;
				}
				for(int z = 0; z < n; z++)
				cout << s[z];
				return 0;
			}
		}
	}

	cout << "NO";

}