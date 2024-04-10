#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define ms(x) memset(x, 0, sizeof(x));
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define y1 ngsdf
#define sqr(a) ( (a) * (a) )
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;
const ld E = 1e-9;
const int MAX = 1e6 + 1;

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int ans = 0;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (a != -1)
				ans |= a;
		}
		cout << ans << " ";
	}

}