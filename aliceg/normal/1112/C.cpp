#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define fi(n) for(int i = 0; i < (int)n; ++i)
#define fie(n) for(int i = 1; i <= (int)n; ++i)
#define fir(l, r) for(int i = (int)l; i <= (int)r; ++i)
#define fj(n) for(int j = 0; j < (int)n; ++j)
#define fje(n) for(int j = 1; j <= (int)n; ++j)
#define fjr(l, r) for(int j = (int)l; j <= (int)r; ++j)
#define fv(i, n) for(int i = 0; i < (int)n; ++i)
#define fve(i, n) for(int i = 1; i <= (int)n; ++i)
#define fvr(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define sqr(x) ((x) * (x))
#define rn(n) int n; cin >> n
//#define int ll

#pragma warning (disable : 4996)
//#pragma comment (linker, "STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<char> vc;

const ld EPS = 1e-8;
const int N = (int)5e5 + 10;
const int INF = (int)1e9 + 10;
const int MOD = (int)1e9 + 7;

signed main(){
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int m, k, n, s;
	cin >> m >> k >> n >> s;
	vi a(m), b(N), c(N);
	fi(m) cin >> a[i];
	int s1 = 0;
	fi(s){
		rn(x);
		b[x]++;
		c[x]++;
		if (b[x] == 1)
			++s1;
	}
	int r = 0, ans = -1, cnt = 0;
	for(int l = 0; l < m; ++l){
		int maxx = min(m, m - (k * (n - l / k - 1)));
		while (r < maxx){
			b[a[r]]--;
			if (b[a[r]] == 0)
				++cnt;
			++r;
		}

		if (cnt == s1 && maxx - l >= k) {
			ans = l;
			break;
		}

		b[a[l]]++;
		if (b[a[l]] == 1)
			--cnt;
	}
	if (ans == -1){
		cout << -1;
		return 0;
	}
	vc res(m);
	int l = ans, x = 0;
	cnt = 0;
	r = ans;
	while (cnt != s1){
		if (c[a[r]] > 0){
			res[r] = 1;
			++x;
		}
		c[a[r]]--;
		if (c[a[r]] == 0)
			++cnt;
		++r;
	}
	for(int i = l; x != k; ++i){
		if (!res[i]){
			res[i] = 1;
			++x;
		}
		r = max(r, i);
	}
	int p = l / k * k;
	fi(p)
		res[i] = 1;
	int d = 0;
	fi(r){
		if (!res[i])
			++d;
	}
	cout << d << endl;
	fi(r){
		if (!res[i])
			cout << i + 1 << ' ';
	}

	return 0;
}