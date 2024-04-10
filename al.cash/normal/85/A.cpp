#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i=(a), _b=(b); i>=_b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define INF 1000000000
#define INF_LL 1000000000000000000LL
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n;
char s[4][111];

int main()
{
	scanf("%d", &n);
	s[0][0] = s[1][0] = 'x';
	for(int i=1; i+1<n; i+=2)
		s[0][i] = s[0][i+1] = (i&2) ? 'a' : 'b';
	for(int i=1; i+1<n; i+=2)
		s[1][i] = s[1][i+1] = (i&2) ? 'c' : 'd';
	for(int i=0; i+1<n; i+=2)
		s[2][i] = s[2][i+1] = (i&2) ? 'e' : 'f';
	for(int i=0; i+1<n; i+=2)
		s[3][i] = s[3][i+1] = (i&2) ? 'g' : 'h';
	if(n&1) s[2][n-1] = s[3][n-1] = 'y';
	else s[0][n-1] = s[1][n-1] = 'y';
	REP(i, 4) printf("%s\n", s[i]);
	//system("PAUSE");
	return 0;
}