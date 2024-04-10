#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const ll mod = (ll)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

ll ans, nans, bu[26];
vector<int> vc;
bool used[26];
int main() {

	#ifdef SOL
	{
//		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	ans = 1;

	int n, k;
	scanf("%d%d\n", &n, &k);
	string s;
	getline(cin, s);
	for(int i = 0; i < (int)s.length(); i++) {
		nans = ((ans + ans - bu[s[i] - 'a']) + 3 * mod) % mod;
		bu[s[i] - 'a'] = ans;
		ans = nans;
	}

	for(int i = (int)s.length() - 1; i >= 0; i--) {
		if(used[s[i] - 'a']) continue;
		used[s[i] - 'a'] = 1;
		vc.pb(s[i] - 'a');
	}
	for(int i = 0; i < k; i++) {
		if(used[i]) continue;
		vc.pb(i);
	}
	reverse(vc.begin(), vc.end());

	for(int i = 0; i < n; i++) {

		int id = vc[i % k];

		nans = ((ans + ans - bu[id]) + 3 * mod) % mod;
		bu[id] = ans;
		ans = nans;
	}

	printf("%lld", ans);

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim