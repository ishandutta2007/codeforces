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

typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	ull A, B;
	cin >> A >> B;
	if (A < B || (A - B) % 2) {
		puts("-1");
		return 0;
	}
	A = (A - B) / 2;
	ull X = 0, Y = 0;
	for (ull i = 1; i; i <<= 1) {
		if (A & i) {
			if (B & i) {
				puts("-1");
				return 0;
			}
			X |= i;
			Y |= i;
		} else if (B & i) 
			Y |= i;
	}
	cout << X << ' ' << Y << endl;
	return 0;
}