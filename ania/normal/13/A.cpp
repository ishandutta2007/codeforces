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

inline int gcd(int a, int b)
{
	return b ? gcd(b,a%b) : a;
}

int cnt(int n, int b)
{
	int res = 0;
	while(n)
	{
		res += n % b;
		n /= b;
	}
	return res;
}

int main()
{
	int n;
	scanf("%d", &n);
	int res = 0, q = n-2;
	for(int b = 2; b < n; b++) res += cnt(n,b);
	int g = gcd(res,q);
	res /= g;
	q /= g;
	printf("%d/%d\n", res, q);
}