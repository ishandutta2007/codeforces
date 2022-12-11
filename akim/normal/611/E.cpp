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
const int maxn = 200100;

int t[maxn];
int ms[3];
int n;

bool check(int m) {
	int cnt[3] = {m, m, m};
	for(int i = n - 1; i >= 0; i--) {
//		cout << i << " " << cnt[2] << " " << cnt[1] << " " << cnt[0] << endl;
		if(ms[0] >= t[i] && cnt[0]) {
			cnt[0]--;
		} else
		if(ms[1] >= t[i] && cnt[1]) {
			cnt[1]--;
		} else
		if(ms[2] >= t[i] && cnt[2]) {
			cnt[2]--;
		} else
		if(ms[0] + ms[1] >= t[i] && cnt[0] && cnt[1] && m) {
			cnt[0]--;
			cnt[1]--;
			m--;
		} else
		if(ms[0] + ms[2] >= t[i] && cnt[0] && cnt[2] && m) {
			cnt[0]--;
			cnt[2]--;
			m--;
		} else
		if(ms[1] + ms[2] >= t[i] && cnt[1] && cnt[2] && m) {
			cnt[1]--;
			cnt[2]--;
			m--;
		} else
		if(ms[0] + ms[1] + ms[2] >= t[i] && cnt[0] && cnt[1] && cnt[2] && m) {
			cnt[0]--;
			cnt[1]--;
			cnt[2]--;
			m--;
		} else {
			return(0);
		}
	}
	return(1);
}

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

	scanf("%d", &n);
	scanf("%d%d%d", &ms[0], &ms[1], &ms[2]);
	for(int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
	}

	sort(&ms[0], &ms[3]);
	sort(&t[0], &t[n]);

	int l = 0, r = n + 1;
	while(l + 1 < r) {
		int md = (l + r) >> 1;
		if(check(md)) {
			r = md;
		} else {
			l = md;
		}
	}

	printf("%d", r == n + 1 ? -1 : r);

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