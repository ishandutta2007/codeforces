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
#define int				ll

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

char s[111111];
int f[256];

main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	gets(s);
	for (char *i = s; *i; ++i)
		f[(unsigned char)*i]++;
	string abc;
	int res = 0;
	REP (i, 256) if (i >= '0' && i <= '9' || i >= 'a' && i <= 'z') {
		res += f[i] * f[i];
	}
	cout << res << endl;
	return 0;
}