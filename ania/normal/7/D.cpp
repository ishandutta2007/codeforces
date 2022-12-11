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


#define maxn 5000100

int n;
char t[maxn];
int rad[2][maxn], h[maxn];

void manacher(int r)
{
	if(t[0] == t[r]) rad[r][0] = 1;
	for(int i = 0; i < n;)
	{
		int k;
		for(k = 1; k < rad[r][i] && i+k < n; k++)
			if(rad[r][i-k] != rad[r][i]-k) rad[r][i+k] = min(rad[r][i-k], rad[r][i]-k);
			else
			{
				rad[r][i+k] = rad[r][i-k];
				break;
			}
		i += k;
		for(k = rad[r][i]; i+k+r < n && i >= k && t[i+k+r] == t[i-k]; k++) ;
		rad[r][i] = k;
	}
}

bool isPal(int x)
{
	if(x&1)
	{
		return rad[1][x/2] * 2 == x+1;
	}
	else
	{
		return rad[0][x/2] * 2 == x+2;
	}
}

int main()
{
	scanf("%s", t);
	for(n=0;t[n];n++) ;
	manacher(0);
	manacher(1);
	h[0] = 1;
//	fore(i,n) printf("%d ", rad[0][i]); printf("\n");
//	fore(i,n) printf("%d ", rad[1][i]); printf("\n");
	long long res = 1;
	for(int i = 1; i < n; i++)
	{
		if(isPal(i)) h[i] = h[(i+1)/2-1] + 1;
		else h[i] = 0;
//		printf("h[%d] = %d\n", i, h[i]);
		res += h[i];
	}
	printf("%lld\n", res);
}