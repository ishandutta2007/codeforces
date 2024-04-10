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
void outp(int i)
{
	fore(j,(n-i)*2) printf(" ");
	fore(j,i) printf("%d ", j);
	printf("%d",i);
	for(int j=i-1;j>=0;j--) printf(" %d", j);
	printf("\n");

}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i <= n; i++)
	{
		outp(i);
	}
	for(int i = n-1; i >= 0; i--) outp(i);
	return 0;
}