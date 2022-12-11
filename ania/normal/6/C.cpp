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

int n,i,j,ta,tb;
int t[100100];

int main()
{
	scanf("%d", &n);
	fore(k,n) scanf("%d", &t[k]);
	for(i = 0, j = n-1; i <= j; )
	{
		if(ta <= tb)
		{
			ta += t[i];
			i++;
		}
		else
		{
			tb += t[j];
			j--;
		}
	}
	printf("%d %d\n", i, n-i);
}