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
const int maxn = 100100;

int blizh[maxn];

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

	int n, k;
	scanf("%d%d\n", &n, &k);
	string s;
	getline(cin, s);

	{
		int lfree = mod;
		for(int i = 0; i < n; i++) {
			if(s[i] == '0') lfree = i;
			blizh[i] = lfree;
		}
		int rfree = mod;
		for(int i = n - 1; i >= 0; i--) {
			if(s[i] == '0') rfree = i;
			if(abs(blizh[i] - i) > rfree - i)
				blizh[i] = rfree;
		}
	}

	int cnt = 0, ans = mod;
	for(int i = 0, j = 0; i < n; i++) {
		while(j < n && cnt < k + 1) {
			cnt += (s[j] == '0');
			j++;
		}
		if(cnt < k + 1) {
			break;
		}
		int mid = (i + j - 1) / 2;
		ans = min(ans, min(max(abs(blizh[mid] - i), abs(j - 1 - blizh[mid])), max(abs(blizh[mid + 1] - i), abs(j - 1 - blizh[mid + 1]))));
		cnt -= s[i] == '0';
	}

	printf("%d", ans);

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