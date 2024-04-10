#include <iostream>
#define Loop int loop = 0; loop < t; loop++
#define LoopN int i = 0; i < n; i++
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int a, b, c, d, e, f;
	int ans = 0;
	cin >> a >> b >> c >> d >> e >> f;
	if (e > f)
	{
		ans = min(a, d)*e;
		ans += min((d - min(a, d)), min(b, c))*f;
	}
	else
	{
		ans = min(min(b, c), d)*f;
		ans += min(d - min(min(b, c), d), a)*e;
	}
	cout << ans << '\n';
}