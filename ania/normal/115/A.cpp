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

int n;
int p[2020];
int r[2020];

int go(int u)
{
	if(r[u] > 0) return r[u];
	if(p[u] < 0) return r[u] = 1;
	return r[u] = 1+go(p[u]);
}

int main()
{
	scanf("%d", &n);
	fore(i,n) scanf("%d", &p[i]);
	fore(i,n) p[i]--;
	int res = 0;
	fore(i,n) res = max(res, go(i));
	printf("%d\n",res);
}