#include<cstdio>
#include<algorithm>
using namespace std;

int n,m;
int t[55][55];

int go(int a, int b)
{
	int res = n*m;
	for(int x = 0; x+a <= n; x++) for(int y = 0; y+b <= m; y++)
	{
		int cur = 0;
		for(int i = 0; i < a; i++) for(int j = 0; j < b; j++) cur += t[x+i][y+j];
		res = min(res, cur);
	}
	return res;
}

int main()
{
	int res = 55*55;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) scanf("%d", &t[i][j]);
	int a,b;
	scanf("%d%d", &a, &b);
	res = go(a,b);
	res = min(res, go(b,a));
	printf("%d\n", res);
}