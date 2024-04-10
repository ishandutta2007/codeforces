#include <cstdio>
#include <iostream>
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

#define maxn 17
#define maxp 65700

int u[maxn], r[maxn];
bool gr[maxn][maxn];
int64 d[maxp];
int v[maxp];
int n,m,a,b,iter,cur;
int64 y;

int64 arr(int mask, int num)
{
	if(mask == 0) return 1;
	if(v[mask] == iter) return d[mask];
	v[mask] = iter;
	while(u[num]) num--;
	int64 res = 0;
	fore(i,n) if(mask & (1<<i))
	{
		bool ok = 1;
		fore(j,n)
		{
			if(mask & (1<<j))
			{
				if(gr[j][i])
				{
					ok = 0;
					break;
				}
			}
		}
		fore(j,cur+1)
		{
			if(gr[j][i] && r[j] < num)
			{
				ok = 0;
				break;
			}
			if(gr[i][j] && r[j] > num)
			{
				ok = 0;
				break;
			}
		}
		if(ok) res += arr(mask ^ (1<<i), num-1);
	}
	return d[mask] = res;
}

int main()
{
	cin >> n >> y >> m;
	y -= 2001;
	fore(i,m)
	{
		cin >> a >> b;
		a--; b--;
		gr[b][a] = 1;
	}
	for(cur = 0; cur < n; cur++)
	{
		for(int q = 0; q < n; q++) if(!u[q])
		{
			bool ok = 1;
			fore(i,cur)
			{
				if(gr[cur][i] && q < r[i])
					ok = 0;
				if(gr[i][cur] && q > r[i])
					ok = 0;
			}
			if(ok == 0) continue;
			iter = 1 + cur * n + q;
			r[cur] = q;
			u[q] = 1;
			int64 add = arr((1<<n)-(1<<cur+1), n-1);
			//printf("cur = %d, q = %d, y = %lld, add = %lld\n", cur, q, y, add);
			if(y < add)
			{
				break;
			}
			else
			{
				u[q] = 0;
				y -= add;
			}
		}
		if(u[r[cur]] == 0)
		{
			printf("The times have changed\n");
			return 0;
		}
	}
	if(y > 0)
	{
		printf("The times have changed\n");
		return 0;
	}
	fore(i,n) printf("%d ", r[i]+1);
	printf("\n");
}