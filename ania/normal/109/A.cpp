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

int main()
{
	int n,best,b4;
	scanf("%d", &n);
	best = n+1;
	for(int a4 = 0; a4*4 <= n; a4++)
	{
		int a7 = (n-a4*4) / 7;
		if(a4*4+a7*7 != n) continue;
		if(a4+a7 < best)
		{
			best = a4+a7;
			b4 = a4;
		}
	}
	if(best == n+1)
	{
		printf("-1\n");
		return 0;
	}
	for(int i = 0; i < b4; i++) printf("4");
	for(int i = 0; i < best-b4; i++) printf("7");
	printf("\n");
}