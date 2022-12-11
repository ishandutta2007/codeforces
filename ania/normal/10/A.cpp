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

int l[111], r[111];

int main()
{
	int n,p1,p2,t1,t2,p3;
	scanf("%d%d%d%d%d%d", &n, &p1, &p2, &p3, &t1, &t2);
	fore(i,n) scanf("%d%d", &l[i], &r[i]);
	int res = 0;
	fore(i,n) res += p1 * (r[i] - l[i]);
	fore(i,n-1)
	{
		int T = l[i+1] - r[i];
		if(T < t1) res += T * p1;
		else
		{
			if(T < t1+t2) res += t1 * p1 + (T-t1) * p2;
			else res += t1 * p1 + t2 * p2 + (T-t1-t2) * p3;
		}
	}
	printf("%d\n", res);
}