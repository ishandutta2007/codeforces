#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	map<int, bool> ex;
	int arr[200000];
	int n, k;
	int size = 0;
	int p = -1;
	cin >> n >> k;
	Loop(i, 0, n)
	{
		int x;
		cin >> x;
		if (!ex[x])
		{
			p++;
			ex[x] = true;
			if (size < k)
				size++;
			else
				ex[arr[p % k]] = false;
			arr[p % k] = x;
		}
	}
	if (size < k)
	{
		cout << size << '\n';
		for (int i = p; i >= 0; i--)
			cout << arr[i] << ' ';
	}
	else
	{
		cout << k << '\n';
		for (int i = p; i > p - k; i--)
			cout << arr[i % k] << ' ';
	}
}