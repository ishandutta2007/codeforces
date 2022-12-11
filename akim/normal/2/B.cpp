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
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 1010;

pair<int, int> dp2[maxn][maxn];
pair<int, int> dp5[maxn][maxn];
int a2[maxn][maxn];
int a5[maxn][maxn];
int prev2[maxn][maxn];
int prev5[maxn][maxn];
bool zero = 0;

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

	int n;
	scanf("%d", &n);
	int zx = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int x;
			scanf("%d", &x);
			if(x == 0) {
				zero = 1;
				zx = i;
			}
			while(x && x % 2 == 0) {
				x /= 2;
				a2[i][j]++;
			}
			while(x && x % 5 == 0) {
				x /= 5;
				a5[i][j]++;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == 0 && j == 0) {
				dp2[i][j] = mp(a2[i][j], a5[i][j]);
				prev2[i][j] = 0;
				dp5[i][j] = mp(a5[i][j], a2[i][j]);
				prev5[i][j] = 0;
				continue;
			}
			if(i == 0) {
				dp2[i][j] = mp(dp2[i][j - 1].fs + a2[i][j], dp2[i][j - 1].sc + a5[i][j]);
				prev2[i][j] = 21;
				if(dp2[i][j] > mp(dp5[i][j - 1].sc + a2[i][j], dp5[i][j - 1].fs + a5[i][j])) {
					dp2[i][j] = mp(dp5[i][j - 1].sc + a2[i][j], dp5[i][j - 1].fs + a5[i][j]);
					prev2[i][j] = 51;
				}
				dp5[i][j] = mp(dp2[i][j - 1].sc + a5[i][j], dp2[i][j - 1].fs + a2[i][j]);
				prev5[i][j] = 21;
				if(dp5[i][j] > mp(dp5[i][j - 1].fs + a5[i][j], dp5[i][j - 1].sc + a2[i][j])) {
					dp5[i][j] = mp(dp5[i][j - 1].fs + a5[i][j], dp5[i][j - 1].sc + a2[i][j]);
					prev5[i][j] = 51;
				}
				continue;
			}
			if(j == 0) {
				dp2[i][j] = mp(dp2[i - 1][j].fs + a2[i][j], dp2[i - 1][j].sc + a5[i][j]);
				prev2[i][j] = 22;
				if(dp2[i][j] > mp(dp5[i - 1][j].sc + a2[i][j], dp5[i - 1][j].fs + a5[i][j])) {
					dp2[i][j] = mp(dp5[i - 1][j].sc + a2[i][j], dp5[i - 1][j].fs + a5[i][j]);
					prev2[i][j] = 52;
				}
				dp5[i][j] = mp(dp2[i - 1][j].sc + a5[i][j], dp2[i - 1][j].fs + a2[i][j]);
				prev5[i][j] = 22;
				if(dp5[i][j] > mp(dp5[i - 1][j].fs + a5[i][j], dp5[i - 1][j].sc + a2[i][j])) {
					dp5[i][j] = mp(dp5[i - 1][j].fs + a5[i][j], dp5[i - 1][j].sc + a2[i][j]);
					prev5[i][j] = 52;
				}
				continue;
			}
			dp2[i][j] = mp(dp2[i][j - 1].fs + a2[i][j], dp2[i][j - 1].sc + a5[i][j]);
			prev2[i][j] = 21;
			if(dp2[i][j] > mp(dp5[i][j - 1].sc + a2[i][j], dp5[i][j - 1].fs + a5[i][j])) {
				dp2[i][j] = mp(dp5[i][j - 1].sc + a2[i][j], dp5[i][j - 1].fs + a5[i][j]);
				prev2[i][j] = 51;
			}
			dp5[i][j] = mp(dp2[i][j - 1].sc + a5[i][j], dp2[i][j - 1].fs + a2[i][j]);
			prev5[i][j] = 21;
			if(dp5[i][j] > mp(dp5[i][j - 1].fs + a5[i][j], dp5[i][j - 1].sc + a2[i][j])) {
				dp5[i][j] = mp(dp5[i][j - 1].fs + a5[i][j], dp5[i][j - 1].sc + a2[i][j]);
				prev5[i][j] = 51;
			}
			if(dp2[i][j] > mp(dp2[i - 1][j].fs + a2[i][j], dp2[i - 1][j].sc + a5[i][j])) {
				dp2[i][j] = mp(dp2[i - 1][j].fs + a2[i][j], dp2[i - 1][j].sc + a5[i][j]);
				prev2[i][j] = 22;
			}
			if(dp2[i][j] > mp(dp5[i - 1][j].sc + a2[i][j], dp5[i - 1][j].fs + a5[i][j])) {
				dp2[i][j] = mp(dp5[i - 1][j].sc + a2[i][j], dp5[i - 1][j].fs + a5[i][j]);
				prev2[i][j] = 52;
			}
			if(dp5[i][j] > mp(dp2[i - 1][j].sc + a5[i][j], dp2[i - 1][j].fs + a2[i][j])) {
				dp5[i][j] = mp(dp2[i - 1][j].sc + a5[i][j], dp2[i - 1][j].fs + a2[i][j]);
				prev5[i][j] = 22;
			}
			if(dp5[i][j] > mp(dp5[i - 1][j].fs + a5[i][j], dp5[i - 1][j].sc + a2[i][j])) {
				dp5[i][j] = mp(dp5[i - 1][j].fs + a5[i][j], dp5[i - 1][j].sc + a2[i][j]);
				prev5[i][j] = 52;
			}
		}
	}

	int idx = n - 1, idy = n - 1, id = 0;
	int answ = min(min(dp2[idx][idy].fs, dp2[idx][idy].sc), min(dp5[idx][idy].fs, dp5[idx][idy].sc));
	if(zero && answ > 1) {
		if(zero) {
			printf("1\n");
			for(int i = 0; i < zx; i++) {
				printf("D");
			}
			for(int i = 0; i < n - 1; i++) {
				printf("R");
			}
			for(int i = zx; i < n - 1; i++) {
				printf("D");
			}
			return(0);
		}
	}
	printf("%d\n", answ);
	if(min(dp2[idx][idy].fs, dp2[idx][idy].sc) < min(dp5[idx][idy].fs, dp5[idx][idy].sc)) {
		id = prev2[idx][idy];
	} else {
		id = prev5[idx][idy];
	}
	string ans;
	while(id != 0) {
		ans += id % 10 == 1 ? 'R' : 'D';
		if(id % 10 == 1) {
			idy--;
			if(id > 25) {
				id = prev5[idx][idy];
			} else {
				id = prev2[idx][idy];
			}
		} else {
			idx--;
			if(id > 25) {
				id = prev5[idx][idy];
			} else {
				id = prev2[idx][idy];
			}
		}
	}

	reverse(ans.begin(), ans.end());

	cout << ans << endl;

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