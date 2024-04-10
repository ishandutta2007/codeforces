#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int* Card[3000] = { 0 };
map<ll , unsigned int> Co;
int n, k;

int Third(int a, int b)
{
	ll ans = 0;
	for (int i = 0; i < k; ++i)
	{
		ans *= 3;
		if (Card[a][i] == Card[b][i])
			ans += Card[a][i];
		else
			ans += 3 - (Card[a][i] + Card[b][i]);
	}
	return Co[ans];
}

int main()
{
	cin >> n >> k;
	for (LoopN)
	{
		Card[i] = new int[k];
		char* card = new char[k+2];
		cin >> card;
		ll h = 0;
		for (int j = 0; j < k; ++j)
		{
			//Card[i][j] = (i + j) % 3;
			Card[i][j] = card[j];
			switch (card[j])
			{
			case 'S': Card[i][j] = 0; break;
			case 'E': Card[i][j] = 1; break;
			case 'T': Card[i][j] = 2; break;
			}
			h *= 3;
			h += Card[i][j];
		}
		++Co[h];
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			ans += Third(i, j);
		}
	}
	cout << ans / 3 << '\n';
}

/*int main()
{
	int n;
	cin >> n;
	int p[200];
	int x[2] = { n,n };
	for (LoopN)
	{
		cin >> p[i];
		if (p[i] == 0)
			p[i] = -1;
		else
		{
			p[i] %= 2;
			--x[p[i]];
		}
	}
	int ans = 0;
	for (int i=1;i<)
	{

	}
}*/