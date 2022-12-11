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

int n,w[1010];

int main()
{
	scanf("%d", &n);
	int q = 0;
	for(int i = 1; i < n; i += 2) w[q++] = i;
	for(int i = 2; i < n; i += 2) w[q++] = i;
	fore(i,n-1)
	{
		fore(j,n-1) if(i == j) printf("0 ");
		else printf("%d ", (j+i)%(n-1)+1);
		printf("%d\n", w[i]);
	}
	fore(i,n-1) printf("%d ", w[i]);
	printf("0\n");
}