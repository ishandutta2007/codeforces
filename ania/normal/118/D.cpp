#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define err(...) fprintf(stderr, __VA_ARGS__)

typedef pair<int,int> pi;
typedef long long int64;
typedef vector<int> vi;

#define fore(i,n) for(int i = 0; i < (n); i++)
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define x first
#define y second
#define mp make_pair
#define pb push_back

#define MOD 100000000

int k1, k2;
int v[111][111][2];
int d[111][111][2];

int rec(int n1, int n2, bool q)
{
	if(n1 == 0 && n2 == 0) return 1;
	if(v[n1][n2][q]) return d[n1][n2][q];
	v[n1][n2][q] = 1;
	int res = 0;
	if(q == 0)
	{
		for(int i = 1; i <= n1 && i <= k1; i++)
		{
			res += rec(n1-i, n2, 1);
			if(res >= MOD) res -= MOD;
		}
	}
	else
	{
		for(int i = 1; i <= n2 && i <= k2; i++)
		{
			res += rec(n1, n2-i, 0);
			if(res >= MOD) res -= MOD;
		}
	}
	return d[n1][n2][q] = res;
}

int main()
{
	int n1,n2;
	scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
	int res = rec(n1,n2,0) + rec(n1,n2,1);
	res %= MOD;
	printf("%d\n", res);
}