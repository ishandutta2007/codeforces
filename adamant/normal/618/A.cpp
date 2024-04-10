// Moscow IPT Hello
#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	#endif
	int n;
	cin >> n;
	for(int i = 25; i >= 0; i--)
	{
		if(n >= (1 << i))
		{
			cout << i + 1 << ' ';
			n -= 1 << i;
		}
	}
	return 0;
}