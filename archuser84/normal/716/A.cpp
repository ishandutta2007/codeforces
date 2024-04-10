#include <iostream>
#include <string.h>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
using namespace std;

int main()
{
	int n,c;
	int ans = 0;
	int last = 0;
	cin >> n >> c;
	for (LoopN)
	{
		int t;
		cin >> t;
		if (t - last > c)
			ans = 1;
		else
			++ans;
		last = t;
	}
	cout << ans << '\n';
}