#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 300005;

int n, m;
char a[N];
int b[11];
long long ans;
int main()
{
	int i, j, k;
	cin >> a;
	n = strlen(a);
	for (i = 0; i < n; ++i)
	{
		if ((a[i]-'0') % 4 == 0)
			++ans;
		if (i > 0 && ((a[i - 1]-'0') * 10 + (a[i]-'0')) % 4 == 0)
		{
			ans += i;
		}
	}
	cout << ans << endl;
//	system("pause");
	return 0;
}