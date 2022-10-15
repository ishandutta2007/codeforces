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
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef double ld;
typedef map<int, int>::iterator mit;
const ld E = 1e-11;

#ifdef LOCAL
const ll MAX = 10000;
//#define DEBUG
#else
const ll MAX = 1e5 + 3;
#endif

int sum[MAX], mn[MAX], used[MAX], r[MAX];

void make(int x, int res, int g){
	for(int i = res; i <= 100 && x < MAX; i++, x *= 2){
		if(used[x] != g){
			used[x] = g;
			r[x]++;
			sum[x] += i;
			mn[x] = i;
		}else{
			if(i < mn[x]){
				sum[x] -= mn[x];
				mn[x] = i;
				sum[x] += mn[x];
			}
		}
	}
}

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	ms(sum);
	ms(mn);
	ms(used);
	ms(r);

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++){
		int a;
		cin >> a;
		for(int j = 0; j <= 100 && a > 0; j++){
			make(a, j, i);
			a >>= 1;
		}
	}

	int ans = INT_MAX;
	for(int i = 0; i < MAX; i++)
		if(r[i] == n)
			ans = min(ans, sum[i]);

	cout << ans;

}