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

const int h = 111;
int n, l,m;
char s[h][h], w[h], c;
bool y[h];

void repl (char &a, char b)
{
	if(isupper(a)) a = toupper(b);
	else a = b;
}

int main()
{
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
    scanf("%d", &n);
    REP(i, n) scanf("%s", s[i]);
    scanf("%s", w);
    l = strlen(w);
    REP(i, l) y[i] = false;
    REP(i, n)
    {
		m = strlen(s[i]);
		REP(u, m) s[i][u] = tolower(s[i][u]);
		REP(j, l-m+1)
		{
			bool ok = true;
			REP(u, m) if(s[i][u] != tolower(w[j+u]))
			{
				ok = false;
				break;
			}
			if(ok) REP(u, m) y[j+u] = true;
		}
    }
    c = 0;
    while(!islower(c)) scanf("%c", &c);
    REP(i, l) if(y[i])
    {
		char t = tolower(w[i]);
		if(t!=c) repl(w[i], c);
		else
		{
			if(t!='a') repl(w[i], 'a');
			else repl(w[i], 'b');
		}
	}
	printf("%s\n", w);
	//system("PAUSE");
	return 0;
}