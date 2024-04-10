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

const int K = 1003;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 2000;
#else
const ll MAX = 1e5 + 1;
#endif

bool check(int n){
	int a = 0;
	int q = sqrt(n);
	for(int i = 2; i <= q; i++){
		if(n % i == 0){
			a++;
			while(n % i == 0)
				n /= i;
		}
	}
	if(n != 1)
		a++;
	return a <= 1;

}

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	vector<int> ans;
	for(int i = 2; i <= n; i++)
		if(check(i))
			ans.push_back(i);

	cout << ans.size() << endl;
	for(int i = 0; i < (int) ans.size(); i++)
		cout << ans[i] << " ";

}