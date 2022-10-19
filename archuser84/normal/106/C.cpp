#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int N;
ll M[12][1001] = { 0 };
int n[11];
int w[11];
int v[11];

int main()
{
	FAST;
	n[0] = 1000;
	int W;
	cin >> W >> N >> w[0] >> v[0]; N++;
	Loop(i, 1, N)
	{
		int a, b;
		cin >> a >> b >> w[i] >> v[i];
		n[i] = a / b;
	}

	Loop(i, 0, N)
	{
		Loop(u, 0, W + 1)
		{
			Loop(k, 0, n[i] + 1)
			{
				if (k * w[i] > u)
					break;
				ll x = M[i][u - k * w[i]] + k * v[i];
				if (x > M[i + 1][u])
					M[i + 1][u] = x;
			}
		}
	}

	cout << M[N][W];
}