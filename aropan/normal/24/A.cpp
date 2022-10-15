#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 111;

int a[MAXN], b[MAXN], c[MAXN];
int n, x, z;

int main()
{
	/*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    //*/
    scanf("%d", &n);
    int s = 0;
    for (int i = 0; i < n; i++)
    {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		s += c[i];
	}
	
	x = 1;
	z = 0;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < n; j++)
			if (a[j] == x || b[j] == x)
			{
				if (b[j] == x)
					z += c[j];
				if (a[j] == x)
					x = b[j]; else
					x = a[j];
				a[j] = b[j] = 0;
				break;
			}
	}
	printf("%d\n", min(z, s - z));
    return 0;
}