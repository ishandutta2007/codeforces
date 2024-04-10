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

int n,m;
int d[1<<7][1<<7][40], v[1<<7][1<<7][40];

int get(int mask, int x)
{
	int res = 0;
	fore(i,n) if((mask&(1<<i)) == 0)
	{
		int a = 1<<i+1, b = 1<<i, c = 1<<i-1;
		bool ok = 0;
		if((x&a) || (x&b) || (x&c)) ok = 1;
		if(ok == 0) res |= 1<<i;
	}
	return res;
}

int go(int mask, int next, int pos)
{
	if(pos == m) return next == 0 ? 0 : 1e9;
	if(v[mask][next][pos]) return d[mask][next][pos];
	v[mask][next][pos] = 1;
	int res = 44;
	fore(x,1<<n) if((x&next) == next)
	{
		res = min(res, __builtin_popcount(x) + go(x, get(mask, x), pos+1));
	}
	return d[mask][next][pos] = res;
}

int main()
{
	scanf("%d%d", &n, &m);
	if(n>m) swap(n,m);
	printf("%d\n", n*m-go(0,0,0));
}