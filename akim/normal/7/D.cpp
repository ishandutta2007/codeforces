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
const int maxn = 5000100;

ll deg[maxn];
vector<int> d1 (maxn);
vector<int> d2 (maxn);

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

	ll ans = 0;
	string s;
	s.reserve(maxn);
	for(char c = getchar(); c >= 28 && c <= 140; c = getchar()) {
		s.pb(c);
	}
	int n = s.length();
	int l=0, r=-1, i, k;
	for(i = 0; i < n; i++){
	if(i > r) k = 1;
	else k = min(d1[l + r - i], r - i);

	while(0 <= i-k && i+k < n && s[i - k] == s[i + k]) k++;
	d1[i] = k;
	if(i + k - 1 > r)
	r = i + k - 1, l = i - k + 1;
	}
	l=0, r=-1;
	for(i = 0; i < n; i++){
	if(i > r) k = 0;
	else k = min(d2[l + r - i + 1], r - i + 1);

	while(i + k < n && i - k - 1 >= 0 && s[i+k] == s[i - k - 1]) k++;
	d2[i] = k;

	if(i + k - 1 > r)
	l = i - k, r = i + k - 1;
	}

	ans += deg[0] = 1;
	for(int i = 1; i < n; i++) {
		if(i & 1) {
			if(d2[i / 2 + 1] >= (i + 1) / 2) {
				ans += deg[i] = deg[(i + 1) / 2 - 1] + 1;
			}
		} else {
			if(d1[(i + 1) / 2] >= (i + 1) / 2 + 1) {
				ans += deg[i] = deg[(i + 1) / 2 - 1] + 1;
			}
		}
	}

	cout << ans;

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