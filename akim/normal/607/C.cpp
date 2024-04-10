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
const int maxn = 2000100;

int pf[maxn];

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
	scanf("%d", &n); n--;
	string a, b, s;
	{
		a.reserve(n);
		scanf("\n");
		for(int i = 0; i < n; i++) {
			a.pb(getchar());
		}
	}
	{
		b.reserve(n);
		scanf("\n");
		for(int i = 0; i < n; i++) {
			b.pb(getchar());
			b.back() = b.back() == 'S' ? 'N' :
					b.back() == 'N' ? 'S' :
					b.back() == 'W' ? 'E' :
					b.back() == 'E' ? 'W' : 'X';
		}
		reverse(b.begin(), b.end());
	}

	s = b + '#' + a;
	for(int i = 1; i <= n * 2; i++) {
		int j = pf[i - 1];

		while(j && s[j] != s[i]) j = pf[j - 1];
		if(s[j] == s[i]) j++;
		pf[i] = j;
	}

	cout << (pf[2 * n] == 0 ? "YES" : "NO");

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