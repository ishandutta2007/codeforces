#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int** mat = new int* [n];
	int** arr = new int* [m];
	Loop(i, 0, n)
	{
		mat[i] = new int[m];
		Loop(j, 0, m)
		{
			cin >> mat[i][j];
			mat[i][j]--;
			//mat[i][j] = i + j;
		}
	}
	int ans = 0;
	Loop(j, 0, m)
	{
		arr[j] = new int[n] {0};
		Loop(i, 0, n)
		{
			int x = mat[i][j];
			if (x < n * m && x % m == j)
				arr[j][(n + i - x / m) % n]++;
		}
		int max = 0;
		Loop(i, 1, n)
		{
			if (arr[j][i] - i > arr[j][max])
				max = i;
		}
		ans += max + n - arr[j][max];
	}
	cout << ans;
}