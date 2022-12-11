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

#define maxn 100100

int n;
int x[maxn], y[maxn], res[maxn];
vi occ[maxn];

void add(int x, int pos)
{
	for(int d = 1; d*d <= x; d++) if(x%d==0)
	{
		occ[d].pb(pos);
		if(d!=x/d) occ[x/d].pb(pos);
	}
}

int main()
{
	scanf("%d", &n);
	fore(i,n) scanf("%d%d", &x[i], &y[i]);
	fore(i,n) add(x[i], i);
	fore(i,maxn)
	{
		if(occ[i].size() == 0) continue;
		res[occ[i][0]]++;
		for(int j = 1; j < occ[i].size(); j++)
		{
			int back = y[occ[i][j]];
			if(occ[i][j-1] < occ[i][j] - back)
				res[occ[i][j]]++;
		}
	}
	fore(i,n) printf("%d\n", res[i]);
}