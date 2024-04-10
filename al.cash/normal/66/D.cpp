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

int n, k, p[55];

const int base = 10000;
int a[100], l;

int main()
{
	scanf("%d", &n);
	if(n==2)
	{
		printf("-1\n");
		return 0;
	}
	p[0] = 2;
	k = 1;
	for(int i=3; k<n; i+=2)
	{
		bool pr = true;
		for(int j=1; j<k && p[j]*p[j]<=i; ++j) if(i%p[j]==0)
		{
			pr = false;
			break;
		}
		if(pr) p[k++] = i;
	}
	//REP(i, n) printf("%d ", p[i]); printf("\n");
	REP(i, n)
	{
		l=1;
		a[0]=1;
		REP(j, n) if(i!=j)
		{
			int r=0;
			for(int u=0; u<l; ++u)
			{
				r += p[j] * a[u];
				a[u] = r % base;
				r /= base;
			}
			while(r>0)
			{
				a[l] = r % base;
				r /= base;
				++l;
			}
		}
		printf("%d", a[l-1]);
		FORD(i, l-2, 0) printf("%04d", a[i]);
		printf("\n");
	}
	return 0;
}