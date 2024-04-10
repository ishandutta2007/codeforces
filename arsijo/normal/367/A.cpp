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
const ll MAX = 1e5 + 1;
//#define DEBUG
#else
const ll MAX = 1e6 + 1;
#endif

int *x, *y, *z;

bool solve(string s, int l, int r){

	int ar[3] = {x[r] - x[l - 1], y[r] - y[l - 1], z[r] - z[l - 1]};
	//cout << ar[0] << " " << ar[1] << " " << ar[2] << endl;
	sort(ar, ar + 3);
	//cout << ar[0] << " " << ar[1] << " " << ar[2] << endl;
	return abs(ar[0] - ar[2]) <= 1 || r - l + 1 < 3;

}

int main() {

	sync;

#ifdef LOCAL
	srand(time(NULL));
	input;
#else

#endif

	string s;
	cin >> s;

	x = new int[s.size() + 1], y = new int[s.size() + 1], z = new int[s.size() + 1];
	x[0] = y[0] = z[0];
	x++, y++, z++;

	for(int i = 0; i < (int) s.size(); i++){
		x[i] = x[i - 1], y[i] = y[i - 1], z[i] = z[i - 1];
		if(s[i] == 'x')
			x[i]++;
		else if(s[i] == 'y')
			y[i]++;
		else if(s[i] == 'z')
			z[i]++;
	}

	int q;
	cin >> q;

	while(q--){
		int l, r;
		cin >> l >> r;
		cout << (solve(s, l - 1, r - 1) ? "YES" : "NO") << endl;
	}

}