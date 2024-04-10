#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 1111

int n;
int a[maxn];
bool v[maxn][maxn];
int r[maxn][maxn], w[maxn][maxn][2];

void go(int,int);

void up(int x0, int f0, int x1, int f1, int V, int A, int B)
{
	go(x1, f1);
	int C = r[x1][f1] + V;
	if(C < r[x0][f0])
	{
		r[x0][f0] = C;
		w[x0][f0][0] = A;
		w[x0][f0][1] = B;
	}
}

void go(int x, int f)
{
	if(v[x][f]) return;
	v[x][f] = 1;
	if(f == n)
	{
		r[x][f] = a[x];
		w[x][f][0] = x;
		w[x][f][1] = -1;
		return;
	}
	if(f+1 == n)
	{
		r[x][f] = max(a[x], a[f]);
		w[x][f][0] = x;
		w[x][f][1] = f;
		return;
	}
	int y = f, z = f+1;
	int X = max(a[y], a[z]), Y = max(a[x], a[z]), Z = max(a[x], a[y]);
	r[x][f] = 1e9;
	up(x,f,x,f+2,X,y,z);
	up(x,f,y,f+2,Y,x,z);
	up(x,f,z,f+2,Z,x,y);
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	go(0,1);
	printf("%d\n", r[0][1]);
	int x = 0, f = 1;
	while(f <= n)
	{
		int y = w[x][f][0], z = w[x][f][1];
		if(z == -1) printf("%d\n", y+1);
		else printf("%d %d\n", y+1, z+1);
		int A = x, B = f, C = f+1;
		f += 2;
		if(A != y && A != z) x = A;
		else if(B != y && B != z) x = B;
		else x = C;
	}
}