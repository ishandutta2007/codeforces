//Created in CLion IDE, Ubuntu OS.

/**
	inline void print_hello()
	{
		string message = R"(
		Hello!

		My name is Andrey E. Kalendarov,
		And I'm waiting for OK (or AC) status.

		Yes, please, don't blame my code.
		I know that it's far from ideal.
		But it should pass all the tests.

		And everybody will be happy.
		And you, my dear reader, too.
		I'm sure.

		Goodbye.
		)";

		cout << message << endl;
	}
**/

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

int main()
{
	_prepare();

	int n, k;
	cin >> n >> k;

	set<int> s;

	int ans = 0;

	for(int i = 0; i < k; ++i)
	{
		int m;
		cin >> m;

		int last;
		cin >> last;

		for(int j = 0; j < m - 1; ++j)
		{
			int cur;
			cin >> cur;

			if(last + 1 != cur)
			{
				++ans;
				s.insert(last);
			}
			last = cur;
		}

		s.insert(last);
	}

	for(int i = 1; i < n; ++i)
	{
		if(s.find(i) == s.end())
		{
			continue;
		}
		++ans;
		int val = *s.lower_bound(i + 1);
		for(int j = i + 1; j < val; ++j)
		{
			s.insert(j);
			++ans;
		}
		s.erase(i);
	}

	cout << ans << endl;


	return 0;
}