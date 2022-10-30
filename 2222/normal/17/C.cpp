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

#define all(a)		(a).begin(),(a).end()
#define sz(a)		int((a).size())
#define FOR(i,a,b)	for(int i=a;i<b;++i)
#define REP(i,n)	FOR(i,0,n)
#define UN(v)		sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)		memset(a,b,sizeof a)
#define pb			push_back
#define X			first
#define Y			second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int mod = 51123987;

int n;
char s[155];

int B[155][55][55][55];
int res;
int F[55][55];
int prev[3][155];

int mul(int x, int y) { return x * ll(y) % mod; }

int f(int k, int s) {
	if (k < 0 || s < 0) return 0;
	if (k == 0) return s == 0;
	int &res = F[k][s];
	if (res < 0) {
		res = f(k, s - 1) + f(k - 1, s - 1);
		if (res >= mod) res -= mod;
	}
	return res;
}

int dfs(int i, int a, int b, int c) {
	if (a < 0 || b < 0 || c < 0) return 0;
	if (a + b + c == 0) return 1;
	int &res = B[i][a][b][c];
	if (res < 0) {
		res = 0;
		REP (k, 3) {
			int j = prev[k][i];
			if (j >= 0 && j != i) {
				res += dfs(j, a - (k == 0), b - (k == 1), c - (k == 2));
				if (res >= mod) res -= mod;
			}
		}
	}
	return res;
}

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin >> n >> s;
	CL(prev, -1);
	REP (i, n) {
		prev[s[i] - 'a'][i] = i;
		REP (k, 3) prev[k][i + 1] = prev[k][i];
	}
	CL(B, -1);
	CL(F, -1);
	int res = 0;
	vector <vi> T;
	REP (a, 55) REP(b, 55) REP (c, 55)
		if (a + b + c == n && abs(a - b) < 2 && abs(b - c) < 2 && abs(a - c) < 2) {
			vi t(3);
			t[0] = a;
			t[1] = b;
			t[2] = c;
			T.pb(t);
		}
	REP (a, 55) REP(b, 55) REP (c, 55) {
		int z = dfs(n, a, b, c);
		for (vector <vi> :: iterator q = T.begin(); q != T.end(); ++q) {
			int A = f(a, (*q)[0]), B = f(b, (*q)[1]), C = f(c, (*q)[2]);
			res += mul(mul(mul(A, B), C), z);
			if (res >= mod) res -= mod;
		}
	}
	cout << res << endl;
	return 0;
}