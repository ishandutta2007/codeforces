#include <cstdio>
#include <algorithm>
using namespace std;

#define MOD 1000000007

char fig[14][3][4] = {{"...", "...", "..."}, {"...", ".O.", "..."}, {"..O", "...", "O.."}, {"..O", ".O.", "O.."}, {"O.O", "...", "O.O"}, {"O.O", ".O.", "O.O"}, {"O.O", "O.O", "O.O"},
	{"...", "...", "..."}, {"...", ".O.", "..."}, {"O..", "...", "..O"}, {"O..", ".O.", "..O"}, {"O.O", "...", "O.O"}, {"O.O", ".O.", "O.O"}, {"OOO", "...", "OOO"}};
bool good[7] = {1, 1, 0, 0, 1, 1, 0};

int t[333][333];
int r[333];
int d[333];
int n,m;
char buf[3][1111];

bool hor(int i, int j)
{
	if(t[i][j] <= 6 && !good[t[i][j]]) return 0;
	if(t[i][j+1] <= 6 && !good[t[i][j+1]]) return 0;
	return 1;
}

bool ver(int i, int j)
{
	if(t[i][j] > 6) return 0;
	if(t[i+1][j] > 6) return 0;
	return 1;
}

int f(int pos)
{
	r[0] = 1;
	r[1] = hor(0,pos);
	//printf("%d\n", r[1]);
	for(int i = 2; i <= n; i++)
	{
		if(hor(i-1,pos)) r[i] = r[i-1];
		else r[i] = 0;
		if(ver(i-2, pos) && ver(i-2,pos+1))
			r[i] += r[i-2];
		if(r[i] >= MOD) r[i] -= MOD;
		//printf("r[%d] = %d\n", i, r[i]);
	}
	if(n%2 == 0)
	{
		int w = 1;
		for(int i = 0; i < n; i++) if(t[i][pos] > 6 || t[i][pos+1] > 6) w = 0;
		if(w) return r[n]-1;
	}
	return r[n];
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf(" %*s %s %s %s", buf[0], buf[1], buf[2]);
		int q = 0;
		for(int j = 0; j < m; j++)
		{
			q++;
			for(int d = 0; d < 14; d++)
			{
				bool ok = 1;
				for(int a = 0; a < 3; a++) for(int b = 0; b < 3; b++)
					if(buf[a][q+b] != fig[d][a][b]) ok = 0;
				if(ok)
				{
					t[i][j] = d;
					break;
				}
			}
			q += 3;
		}
	}
	d[0] = 1;
	d[1] = 1;
	if(n&1) d[1] = 0;
	for(int i = 0; i < n; i++) if(t[i][0] > 6) d[1] = 0;
	for(int i = 2; i <= m; i++)
	{
		bool ok = n%2==0;
		for(int j = 0; j < n; j++) if(t[j][i-1] > 6) ok = 0;
		if(ok) d[i] = (1LL * d[i-2] * f(i-2) + d[i-1]) % MOD;
		else d[i] = 1LL * d[i-2] * f(i-2) % MOD;
		//printf("\td[%d] = %d\n", i, d[i]);
	}
	printf("%d\n", d[m]);
}