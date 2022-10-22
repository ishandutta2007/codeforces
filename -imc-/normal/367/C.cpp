#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

long long getNeedCover (long long n)
{
	return (n % 2 == 0) ? (n * (n - 1) / 2 + n / 2) : (n * (n - 1) / 2 + 1);
}

int main()
{
	#ifdef LOCAL
	freopen ("c.in", "r", stdin);
	#endif
	
	int n, m;
	scanf ("%d %d", &n, &m);
	
	vector <int> w (m);
	for (int i = 0; i < m; i++)
		scanf ("%*d %d", &w[i]);
		
	sort (w.rbegin(), w.rend());
	
	long long answer = 0;
	
	for (int i = 0; i < m; i++)
	{
		long long needCover = getNeedCover (i + 1);
		if (needCover <= n)
			answer += w[i];
		else
			break;
	}
	
	cout << answer << endl;
	
	return 0;
}