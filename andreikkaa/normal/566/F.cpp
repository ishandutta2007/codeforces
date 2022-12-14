/* ______ INCLUDES ______ */

#include <bits/stdc++.h>

/* _____ NAMESPACES _____ */

using namespace std;

/* ______ TEMPLATE ______ */

typedef long long ll;
typedef long double ld;

inline void _redirect_streams(const string input="", const string output="")
{
	if(not input.empty())
		assert(freopen(input.c_str(), "r", stdin) != nullptr);

	if(not output.empty())
		assert(freopen(output.c_str(), "w", stdout) != nullptr);
}

inline void _speed_up_iostreams()
{
	//IMPORTANT NOTE: don't mix iostreams and stdio when next line is active
	ios_base::sync_with_stdio(false);

	cin.tie(nullptr);
}

inline void _prepare()
{
#ifdef ANDREIKKAA
	_redirect_streams("input.txt");
#else
	//_redirect_streams("input.txt", "output.txt");
#endif //ANDREIKKAA

	_speed_up_iostreams();
}

/* ________ CODE ________ */

const int MAX_N = 1000 * 1000 + 1;

int dp[MAX_N];

int main()
{
	_prepare();

	int n;
	scanf("%d", &n);

	int ans = 0;

	for(int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);

		int val = (dp[a] + 1);

		ans = max(ans, val);

		for(int j = a + a; j < MAX_N; j += a)
		{
			dp[j] = max(dp[j], val);
		}
	}

	printf("%d\n", ans);
	
	return 0;
}