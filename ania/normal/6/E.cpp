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

#define maxn 100100
#define M (1 << 17)

int n,K,am;
int h[maxn], r[maxn];
int mn[M*2+172], mx[M*2+95];

void build()
{
	fore(i,n) mx[M+i] = mn[M+i] = h[i];
	for(int i = n; i < M; i++) mn[M+i] = 1e9;
	for(int i = M-1; i > 0; i--)
	{
		mx[i] = max(mx[2*i], mx[2*i+1]);
		mn[i] = min(mn[2*i], mn[2*i+1]);
	}
}

int get_max(int p, int k)
{
	p += M;
	k += M;
	int res = mx[p];
	while(p+1 < k)
	{
		if(p%2 == 0) res = max(res, mx[p+1]);
		if(k%2 == 1) res = max(res, mx[k-1]);
		p /= 2;
		k /= 2;
	}
	return res;
}

int get_min(int p, int k)
{
	p += M;
	k += M;
	int res = mn[p];
	while(p+1 < k)
	{
		if(p%2 == 0) res = min(res, mn[p+1]);
		if(k%2 == 1) res = min(res, mn[k-1]);
		p /= 2;
		k /= 2;
	}
	return res;
}

bool check(int len)
{
	am = 0;
	fore(i,n-len+1)
	{
		r[i] = get_max(i,i+len) - get_min(i,i+len) <= K;
		if(r[i])
		{
			am++;
		}
	}
	return am>0;
}

int main()
{
	scanf("%d%d", &n, &K);
	fore(i,n) scanf("%d", &h[i]);
	build();
	int low = 1, high = n+1;
	while(low+1 < high)
	{
		int mid = (low+high) / 2;
		if(check(mid)) low = mid;
		else high = mid;
	}
	check(low);
	printf("%d %d\n", low, am);
	fore(i,n-low+1) if(r[i]) printf("%d %d\n", i+1, i+low);
}