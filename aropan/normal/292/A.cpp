#include <ctime>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

int main()
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	int n;
	cin >> n;
	long long l = 0;
	long long s = 0;
	long long m = 0;
	for (int i = 0; i < n; i++)
	{
		long long t, c;
		cin >> t >> c;
		
		s = max(s - (t - l), 0LL);
		s += c;
		l = t;
		if (s > m)
		{
			m = s;
		}
	}
	cout << l + s << " " << m << endl;
	fprintf(stderr, "Time execute: %.3lfs\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}