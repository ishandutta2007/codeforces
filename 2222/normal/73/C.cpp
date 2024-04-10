#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

char s[128];
int k, n;
int f[30][30];

bool u[30][128][128];
int G[30][128][128];

int g(int last, int i, int k) {
	if (k < 0) return -1000000000;
	if (i == n) return 0;
	int &res = G[last][i][k];
	if (!u[last][i][k]) {
		u[last][i][k] = true;
		res = -1000000000;
		REP (j, 26) 
			res = max(res, f[last][j] + g(j, i + 1, k - (s[i] != j)));
	}
	return res;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	scanf("%s%d%d", s, &k, &n);
	REP (i, n) {
		char x, y;
		scanf(" %c %c", &x, &y);
		scanf("%d", &f[x - 'a'][y - 'a']);
	}
	n = strlen(s);
	REP (i, n) s[i] -= 'a';
	cout << g(26, 0, k) << endl;
	return 0;
}