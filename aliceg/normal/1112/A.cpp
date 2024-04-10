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
const int N = (int)1e5 + 10;
const int INF = (int)1e9 + 10;
const int MOD = (int)1e9 + 7;

signed main(){
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m, k;
	cin >> n >> m >> k;
	vi p(n);
	vi most(m, -1);
	vc is_p(n);
	fi(n) cin >> p[i];
	fi(n){
		int x;
		cin >> x;
		--x;
		if (most[x] == -1 || p[i] > p[most[x]]){
			if (most[x] != -1)
				is_p[most[x]] = 0;
			most[x] = i;
			is_p[i] = 1;
		}
	}
	int cnt = 0;
	fi(k){
		int x;
		cin >> x;
		--x;
		if (!is_p[x])
			++cnt;
	}
	cout << cnt;

	return 0;
}