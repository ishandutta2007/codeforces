#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES": "NO")
#define all(x) x.begin(),x.end()
#define ll long long
#define pii pair<int,int>
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 1010;
char temp[N];

int quer(int l, int r)
{
	printf("? %i ", r - l + 1);
	Loop(i, l, r + 1)
		printf("%i ", i);
	printf("\n");
	fflush(stdout);
	int ans;
	scanf("%i", &ans);
	return ans;
}

int bin(int n, int k)
{
	int l = 1, r = n;
	while (l < r)
	{
		int m = (l + r) / 2;
		int x = quer(l, m);
		if (x == k)
			r = m;
		else
			l = m + 1;
	}
	return l;
}

int belong[N];
int Ss[N];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(belong, -1, sizeof(belong));
		int n, k;
		scanf("%i%i", &n, &k);
		Loop(i, 0, k)
		{
			scanf("%i", &Ss[i]);
			Loop(j, 0, Ss[i])
			{
				int p;
				scanf("%i", &p);
				belong[p - 1] = i;
			}
		}
		int maax = quer(1, n);
		int ind = bin(n, maax) - 1;
		int h = belong[ind];
		int x;
		if (h == -1)
		{
			h = 0;
			x = maax;
		}
		else
		{
			printf("? %i ", n-Ss[h]);
			Loop(i, 0, n)
				if (belong[i] != h)
					printf("%i ", i + 1);
			printf("\n");
			fflush(stdout);
			scanf("%i", &x);
		}

		printf("! ");
		Loop(i, 0, h)
			printf("%i ", maax);
		printf("%i ", x);
		Loop(i, h+1, k)
			printf("%i ", maax);
		printf("\n");
		fflush(stdout);
		scanf("%s", &temp);
	}
}