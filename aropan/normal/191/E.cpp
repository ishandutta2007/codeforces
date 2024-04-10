#include <cstdio>
#include <cmath>
#include <iostream>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;


const int MAXN = 100007;
const long long INF = (long long)1e+18;

int n, m;
long long k;
long long a[MAXN];
int s[MAXN];
int f[MAXN];

void modify(int x, int d)
{
	for (int i = x + 1; 0 < i; i -= i & -i)
		f[i] += d;
}

int sum(int x)
{
	int res = 0;
	for (int i = x + 1; i <= n + 1; i += i & -i)
		res += f[i];
	return res;
}

bool opr_sort(const int &i, const int &j)
{
	return a[i] < a[j];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
    	int x;
    	cin >> x;
    	a[i] = a[i - 1] + x;
    }
    for (int i = 0; i <= n; i++)
    	s[i] = i;

	sort(s, s + n + 1, opr_sort);


	long long left = -INF, right = INF;
	while (left < right)
	{
		long long center = (left + right + 1) / 2;
		memset(f, 0, sizeof(f));

		long long res = 0;
		for (int i = 0, j = n; i <= n; i++)
		{
			while (0 <= j && a[s[j]] - a[s[i]] >= center)
			{
				modify(s[j], 1);
				j--;
			}
			while (j < n && a[s[j + 1]] - a[s[i]] < center)
			{
				modify(s[j + 1], -1);
				j++;
			}
			res += sum(s[i] + 1);
		}

		if (res >= k)
			left = center;
		else
			right = center - 1;
	}
	cout << left << endl;

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}