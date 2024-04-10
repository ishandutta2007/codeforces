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

char s[8][8];

vector <string> ans;

void L(int i) {
	char t[3] = {'L', i + '1', 0};
	ans.pb(t);
	s[i][6] = s[i][0];
	REP (j, 6) s[i][j] = s[i][j + 1];
}

void R(int i) {
	char t[3] = {'R', i + '1', 0};
	ans.pb(t);
	for (int j = 6; j > 0; --j) s[i][j] = s[i][j - 1];
	s[i][0] = s[i][6];
}

void U(int j) {
	char t[3] = {'U', j + '1', 0};
	ans.pb(t);
	s[6][j] = s[0][j];
	REP (i, 6) s[i][j] = s[i + 1][j];
}

void D(int j) {
	char t[3] = {'D', j + '1', 0};
	ans.pb(t);
	for (int i = 6; i > 0; --i) s[i][j] = s[i - 1][j];
	s[0][j] = s[6][j];
}

void L(int i, int k) { 
	for (; k > 0; --k) L(i); 
	for (; k < 0; ++k) R(i);
}
void R(int i, int k) { 
	for (; k > 0; --k) R(i); 
	for (; k < 0; ++k) L(i); 
}
void U(int i, int k) { for (; k > 0; --k) U(i); }
void D(int i, int k) { for (; k > 0; --k) D(i); }

void solve15() {
	for (int q = 0; q < 30; ++q) {
		int r = q / 6, c = q % 6;
		if (s[r][c] == q) continue;
		REP (j, 6) if (s[r][j] == q) {
			D(c);
			D(j);
			R(r + 1, c - j);
			U(c);
			U(j);
			break;
		}
		if (s[r][c] == q) continue;
		FOR (i, r + 1, 6) REP (j, 6) 
			if (s[i][j] == q) {
				if (j == c) {
					L(i);
					D(c, i - r);
					R(i);
					U(c, i - r);
				} else {
					D(c, i - r);
					R(i, c - j);
					U(c, i - r);
				}
			}
		for (; s[r][c] != q; );
	}
}

void rot6(int i) {
	int j = i + 1, k = j + 1;
	L(5);
	D(i); U(j);
	R(0); L(4);
	D(i); U(j);
	R(5);
	D(j); U(i);
	R(4); L(0);
	D(j); U(i);
}

void print() {
	#ifdef LocalHost
	puts("");
	REP (i, 6) {
		REP (j, 6) 
			putchar(s[i][j] < 10 ? s[i][j] + '0' : s[i][j] - 10 + 'A');
		puts("");
	}
	#endif	
}

void solve6() {
	REP (i, 4) {
		int q = 30 + i;
		REP (j, 6) if (s[5][j] == q) {
			for (; j - 2 >= i; rot6(j -= 2));
			if (i < j) {
				rot6(i);
				rot6(i);
			}
		}
	}
	if (s[5][5] != 35) {
		rot6(2);
		rot6(0);
		L(5);
	}
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	REP (i, 6) {
		gets(s[i]);
		REP (j, 6) s[i][j] -= s[i][j] <= '9' ? '0' : 'A' - 10;
	}
	solve15();
	solve6();
	for (; sz(ans) > 10000; );
	REP (i, 6) REP (j, 6) for (; s[i][j] != i * 6 + j; );
	cout << sz(ans) << endl;
	REP (i, sz(ans)) cout << ans[i] << endl;
	return 0;
}