#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define FAST ios::sync_with_stdio(false);cin.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	FAST;
	int N;
	int n;
	cin >> N; n = N;
	int a = -1, b = -1;
	int h;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			a = i;
			h = i + 1;
			while (n % i == 0)
				n /= i;
			break;
		}
	}
	if (a == -1)
	{
		cout << "NO\n";
		return 0;
	}

	for (int i = h; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			b = i;
			break;
		}
	}
	if (b == -1)
	{
		if (n > 1)
			b = n;
		else
		{
			cout << "NO\n";
			return 0;
		}
	}

	int k1 = -1, k2 = -1;
	for (int k = 1; k * a < N - 1; k++)
	{
		if ((N - 1 - k * a) % b == 0)
		{
			k1 = k;
			k2 = (N - 1 - k * a) / b;
			break;
		}
	}
	if (k1 == -1)
	{
		cout << "NO\n";
		return 0;
	}

	printf("YES\n2\n%i %i\n%i %i\n", k1, N / a, k2, N / b);
}