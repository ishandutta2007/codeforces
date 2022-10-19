#include <iostream>
#include <string>
#define Loop int loop = 0; loop < t; loop++
#define LoopN int i = 0; i < n; i++
using namespace std;

int my_min(int a, int b)
{
	return a < b ? a : b;
}

int my_max(int a, int b)
{
	return a > b ? a : b;
}

int n, k;
char s[1000000];
char a[26];

bool test(char c)
{
	for (int i = 0; i < k; i++)
		if (c == a[i])
			return true;
	return false;
}

int main()
{
	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < k; i++)
		cin >> a[i];
	long long h = 0;
	long long ans = 0;
	for (LoopN)
	{
		if (test(s[i]))
			h++;
		else
		{
			ans += (h * (h + 1)) / 2;
			h = 0;
		}
	}
	ans += (h * (h + 1)) / 2;
	cout << ans << '\n';
}