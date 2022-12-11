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

map<string, int> ma1, ma2;
string s[maxn];
int val[maxn];

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
	for(int i = 0; i < n; i++) {
		cin >> s[i] >> val[i];
		if(!ma1.count(s[i])) ma1[s[i]] = 0;
		ma1[s[i]] += val[i];
	}
	int mx = 0, cnt = 0;
	for(map<string, int>::iterator it = ma1.begin(); it != ma1.end(); it++) {
		if(mx < it -> sc)
			mx = it -> sc, cnt = 1;
		else
		if(mx == it -> sc)
			cnt++;
	}
	if(cnt > 1) {
		for(int i = 0; i < n; i++) {
			if(!ma2.count(s[i])) ma2[s[i]] = 0;
			ma2[s[i]] += val[i];
			if(ma1[s[i]] == mx && ma2[s[i]] >= mx) {
				cout << s[i] << endl;
				break;
			}
		}
	} else {
		for(map<string, int>::iterator it = ma1.begin(); it != ma1.end(); it++) {
			if(mx == it -> sc) {
				cout << it -> fs << endl;
				break;
			}
		}
	}

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