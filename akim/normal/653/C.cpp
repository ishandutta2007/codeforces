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

int a[maxn], used[maxn];
vector<int> bad;
int n;

bool check(int i) {
	bool ok = 1;
	if(i > 0) {
		if(i & 1) {
			if(a[i - 1] >= a[i]) {
				ok = 0;
			}
		} else {
			if(a[i - 1] <= a[i]) {
				ok = 0;
			}
		}
	}
	if(i < n - 1) {
		if(i & 1) {
			if(a[i + 1] >= a[i]) {
				ok = 0;
			}
		} else {
			if(a[i + 1] <= a[i]) {
				ok = 0;
			}
		}
	}
	for(int k = 0; k < (int)bad.size(); k++) {
		int i = bad[k];
		if(i > 0) {
			if(i & 1) {
				if(a[i - 1] >= a[i]) {
					ok = 0;
				}
			} else {
				if(a[i - 1] <= a[i]) {
					ok = 0;
				}
			}
		}
		if(i < n - 1) {
			if(i & 1) {
				if(a[i + 1] >= a[i]) {
					ok = 0;
				}
			} else {
				if(a[i + 1] <= a[i]) {
					ok = 0;
				}
			}
		}
	}
	return(ok);
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
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++) {
		bool ok = 1;
		if(i > 0) {
			if(i & 1) {
				if(a[i - 1] >= a[i]) {
					ok = 0;
				}
			} else {
				if(a[i - 1] <= a[i]) {
					ok = 0;
				}
			}
		}
		if(i < n - 1) {
			if(i & 1) {
				if(a[i + 1] >= a[i]) {
					ok = 0;
				}
			} else {
				if(a[i + 1] <= a[i]) {
					ok = 0;
				}
			}
		}
		if(!ok) {
			bad.pb(i);
		}
	}

	if(bad.size() > 10) {
		printf("0");
		return(0);
	}

//	cout << bad.size();
	int ans = 0;
	for(int k = 0; k < (int)bad.size(); k++) {
		int id = bad[k];
		used[id] = 1;
		for(int i = 0; i < n; i++) {
			if(used[i]) continue;
			swap(a[id], a[i]);
			ans += check(i);
			swap(a[id], a[i]);
		}
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