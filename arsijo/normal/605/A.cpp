#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
#define y1 asd
#define left asdleft
#define right asdright
typedef long long ll;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-7;
const ll MOD = 1e9 + 9;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

int main() {
	sync;
	srand(time(NULL));

#ifdef LOCAL
	input;
	//output;
#else

#endif

	int n;
	cin >> n;

	bool used[n];
	ms(used, 0);
	int ans[n];
	ms(ans, 0);

	int res = 0;

	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		a--;
		if(a != 0 && used[a - 1]){
			ans[a] = ans[a - 1] + 1;
		}else{
			ans[a] = 1;
		}
		res = max(res, ans[a]);
		used[a] = true;
	}

	cout << n - res;



}