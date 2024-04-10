#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define lli long long int
using namespace std;
lli n, m, t, T, x, s;
lli pat, sum1, sum2;
lli min1(lli a, lli b)
{
	if(a >= b) return b;
	return a;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> t >> T >> x >> s;
		if(T > t)
			sum1 = s*((m + (T - t - 1))/(T - t));
		else
			sum1 = x*m + s;
		sum2 = x*m + s;
		//cout << sum1 << " " << sum2 << endl;
		pat += min1(sum1, sum2);

	}
	cout << pat;
	return 0;
}