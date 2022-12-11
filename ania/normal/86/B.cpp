#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define err(...) fprintf(stderr, __VA_ARGS__)
//#define err(...)

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;

#define x first
#define y second
#define tr(i,v) for(typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

int px[4] = {1,0,-1,0}, py[4] = {0,1,0,-1};
int n,m,Q;
int t[1010][1010];
char s[1010][1010];
int C[1000100];
vi g[1000100];
int f[111];

inline bool ok(int x, int y)
{
	if(x < 0 || y < 0 || x >= n || y >= m) return 0;
	return 1;
}

void fill(int x, int y)
{
	int fnd = 0;
	for(int k = 0; k < 4; k++)
	{
		int nx = x+px[k], ny = y+py[k];
		if(!ok(nx,ny)) continue;
		if(s[nx][ny] == '#') continue;
		if(t[nx][ny] > 0)
		{
			fnd = t[nx][ny];
			continue;
		}
		fnd = -k-1;
		break;
	}
	if(fnd == 0)
	{
		printf("-1\n");
		exit(0);
	}
	if(fnd < 0)
	{
		int k = -fnd-1;
		int nx = x+px[k], ny = y+py[k];
		t[x][y] = t[nx][ny] = Q++;
	}
	else
	{
		t[x][y] = fnd;
	}
}

int main()
{
	scanf("%d%d", &n ,&m);
	for(int i = 0; i < n; i++) scanf("%s", s[i]);
	Q = 1;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(s[i][j] == '.' && t[i][j] == 0) fill(i,j);
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(s[i][j] == '.')
	{
		for(int k = 0; k < 4; k++)
		{
			int nx = i+px[k], ny=j+py[k];
			if(!ok(nx,ny) || s[nx][ny] != '.') continue;
			g[t[i][j]].push_back(t[nx][ny]);
		}
	}
	for(int i = 1; i < Q; i++)
	{
		for(int j = 0; j < 10; j++) f[j] = 0;
		tr(j,g[i]) if(*j < i) f[C[*j]] = 1;
		for(int j = 0; j < 10; j++) if(f[j] == 0)
		{
			C[i] = j;
			break;
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++) if(s[i][j] == '.') printf("%d", C[t[i][j]]);
		else printf("#");
		printf("\n");
	}
}