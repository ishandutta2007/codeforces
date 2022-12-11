#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;

#define fore(i,n) for(int i = 0; i < (n); i++)
#define fort(i,n) for(typeof((n).begin()) i = (n).begin(); i != (n).end(); i++)

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;

#define err(...) fprintf(stderr, __VA_ARGS__);

int main()
{
	int n,m,a;
	scanf("%d%d%d", &n, &m, &a);
	printf("%I64d\n", 1LL * ((n+a-1)/a) * ((m+a-1)/a));
}