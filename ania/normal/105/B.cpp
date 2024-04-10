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

int n,A;
int b[11], l[11];

double get()
{
	double res = 0;
	fore(m,1<<n)
	{
		int B = 0;
		double p = 1;
		int c = __builtin_popcount(m);
		fore(i,n)
		{
			if(m&(1<<i))
			{
				p *= 0.1 * l[i];
			}
			else
			{
				p *= 0.1 * (10-l[i]);
				B += b[i];
			}
		}
		res += p * ((2*c>n) ? 1 : (1.0 * A / (A+B)));
	}
	return res;
}

double go(int pos, int k)
{
	if(pos == n) return get();
	double res = 0;
	for(int i = 0; i <= k; i++)
	{
		if(l[pos] + i > 10) break;
		l[pos] += i;
		res = max(res, go(pos+1, k-i));
		l[pos] -= i;
	}
	return res;
}

int main()
{
	int k;
	scanf("%d%d%d", &n, &k, &A);
	fore(i,n) scanf("%d%d", &b[i], &l[i]);
	fore(i,n) l[i] /= 10;
	printf("%.8lf\n", go(0, k));
}