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

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	bool bol[MAX];
	ms(bol);

	int res[MAX];
	ms(res);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		bol[a] = true;
	}

	int ans = 1;

	for(int i = MAX - 1; i >= 1; i--){
		if(!bol[i])
			continue;
		res[i] = 1;
		for(int j = i * 2; j < MAX; j += i)
			if(bol[i])
				res[i] = max(res[i], res[j] + 1);
		ans = max(ans, res[i]);
	}

	cout << ans;


}