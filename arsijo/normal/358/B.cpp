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
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
const ld E = 1e-7;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 100;
#else
const ll MAX = 2e5 + 1;
#endif

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	string res = "";
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		res += "<3" + s;
	}
	res += "<3";

	string s;
	cin >> s;

	int r = 0;
	for(int i = 0; i < (int) s.size() && r < (int) res.size(); i++)
		if(s[i] == res[r])
			r++;

	cout << ((int) res.size() == r ? "yes" : "no");

}