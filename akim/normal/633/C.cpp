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
const int maxn = 1000100;

int dp[maxn];
string wd[maxn];
map<char, int> bor[maxn];
int id[maxn], sz = 1;

void add(string &s, int q) {
	int cur = 0;
	for(int i = 0; i < (int)s.length(); i++) {
		char c = tolower(s[i]);
		if(!bor[cur].count(c)) {
			bor[cur][c] = sz;
			sz++;
		}
		cur = bor[cur][c];
	}
	id[cur] = q;
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

	int n;
	scanf("%d\n", &n);
	string s;
	getline(cin, s);
	int m;
	scanf("%d\n", &m);
	for(int i = 1; i <= m; i++) {
		getline(cin, wd[i]);
		add(wd[i], i);
	}

	dp[0] = -1;
	for(int i = 0; i < n; i++) {
		int cur = 0;
		for(int j = 0; j <= i; j++) {
			char c = tolower(s[i - j]);
//			cout << i << " " << j << " " << c << endl;
			if(!bor[cur].count(c)) break;
			cur = bor[cur][c];
			if(id[cur] != 0 && dp[i - j] != 0) {
				dp[i + 1] = id[cur];
//				cout << id[cur] << endl;
			}
		}
	}

//	return(0);
	if(dp[n] == 0) assert(0);

	vector<int> vc;
	while(n) {
		vc.pb(dp[n]);
		n -= wd[dp[n]].length();
	}
	for(int i = (int)vc.size() - 1; i >= 0; i--) {
		printf("%s ", wd[vc[i]].c_str());
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