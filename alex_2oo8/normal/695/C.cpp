#include <bits/stdc++.h>
#define MAXN 1005
#define MAXK 9

using namespace std;

struct node
{
	long long x, y;
};

struct node getVector (struct node a, struct node b)
{
	struct node res;
	res.x = b.x - a.x;
	res.y = b.y - a.y;
	return res;
}

long long getCrossProduct (struct node u, struct node v) {
	return u.x * v.y - u.y * v.x;
}

int main() {
	int K, N;
	scanf("%d %d", &K, &N);
	static struct node a[MAXK];
	static struct node m[MAXN];
	int i, j, k;
	for (i = 0; i < K; i++)
	{
		scanf("%lld %lld",&a[i].x, &a[i].y);
	}
	for (i = 0; i < N; i++)
	{
		scanf("%lld %lld",&m[i].x, &m[i].y);
	}

	static vector<int> data[MAXK][MAXN];
	for (i = 0; i < K; i++)
	{
		for (j = 0; j < N; j++)
		{
			int minx, maxx, miny, maxy, temp;
			minx = a[i].x; maxx = m[j].x;
			miny = a[i].y; maxy = m[j].y;
			if (minx > maxx) { temp = minx; minx = maxx; maxx = temp; }
			if (miny > maxy) { temp = miny; miny = maxy; maxy = temp; }
			for (k = 0; k < N; k++)
			{
				if (k != j)
				{
					if ((getCrossProduct(getVector(a[i], m[j]), getVector(a[i], m[k])) == 0) &&
						(m[k].x >= minx) && (m[k].x <= maxx) &&
						(m[k].y >= miny) && (m[k].y <= maxy))
					{
						data[i][j].push_back(k);
						if (data[i][j].size() > K+2) break;
					}
				}
			}
		}
	}

	static int p[MAXK];
	static int assigned[MAXK];
	static char b[MAXN];
	memset(b,0,sizeof(b));

	int res = 0;

	for (j = 0; j < N; j++)
	{
		for (i = 0; i < K; i++) p[i] = i;
		do
		{
			assigned[0] = j;
			b[assigned[0]] = 1;
			int cur = 1;
			char flag = 1;
			for (i = 0; i < cur; i++)
			{
				for (int it : data[p[i]][assigned[i]])
				{
					if (!b[it])
					{
						if (cur == K)
						{
							flag = 0;
							break;
						}
						assigned[cur] = it;
						b[assigned[cur]] = 1;
						cur++;
					}
				}
				if (!flag) break;
			}

			for (i = 0; i < cur; i++) b[assigned[i]] = 0;

			if (flag)
			{
				res++;
				break;
			}

		} while (next_permutation(p, p+K));		
	}

	printf("%d\n",res);
	return 0;
}