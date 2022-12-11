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

map<vector<int>, ll> ma;
string s[12];
int c[12];
ll ans = 0;
int n, m;
vector<int> vc;

void rec1(int i, int n) {
	if(i == n) {
		ma[vc]++;
		return;
	}

	for(int f = 0; f < m; f++) {
		if(s[f][i] == '0') {
			vc[f]++;
		}
	}
	rec1(i + 1, n);
	for(int f = 0; f < m; f++) {
		if(s[f][i] == '0') {
			vc[f]--;
		}
	}

	for(int f = 0; f < m; f++) {
		if(s[f][i] == '1') {
			vc[f]++;
		}
	}
	rec1(i + 1, n);
	for(int f = 0; f < m; f++) {
		if(s[f][i] == '1') {
			vc[f]--;
		}
	}
}

void rec2(int i, int n) {
	if(i == n) {

		for(int f = 0; f < m; f++) {
			vc[f] = c[f] - vc[f];
		}

		ans += ma[vc];

		for(int f = 0; f < m; f++) {
			vc[f] = c[f] - vc[f];
		}

		return;
	}

	for(int f = 0; f < m; f++) {
		if(s[f][i] == '0') {
			vc[f]++;
		}
	}
	rec2(i + 1, n);
	for(int f = 0; f < m; f++) {
		if(s[f][i] == '0') {
			vc[f]--;
		}
	}

	for(int f = 0; f < m; f++) {
		if(s[f][i] == '1') {
			vc[f]++;
		}
	}
	rec2(i + 1, n);
	for(int f = 0; f < m; f++) {
		if(s[f][i] == '1') {
			vc[f]--;
		}
	}
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
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

	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		cin >> s[i] >> c[i];
	}

	for(int i = 0; i < m; i++) {
		vc.pb(0);
	}

	int mid = n / 2;
	rec1(0, mid);
	rec2(mid, n);

	printf("%I64d", ans);

	return(0);
}

// by Kim Andrey