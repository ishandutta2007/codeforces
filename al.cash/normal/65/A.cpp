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

int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
	if(d==0) printf("Hermione\n");
	else if(c==0) printf("Ron\n");
		else if(b==0) printf("Hermione\n");
			else if(a==0) printf("Ron\n");
				else
				{
					if(a*c*e < b*d*f) printf("Ron\n");
					else printf("Hermione\n");
				}
	return 0;
}