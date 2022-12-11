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

bool go(int a, int b, int n)
{
	if(n == 0) return 0;
	return 1-go(b,a,n-__gcd(a,n));
}

int main()
{
	int a,n,b;
	scanf("%d%d%d", &a, &b, &n);
	printf("%d\n", 1-go(a,b,n));
}