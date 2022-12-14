/**
	inline void print_hello()
	{
		string message = R"(Hello!

		My name is Andrey E. Kalendarov,
		And I'm waiting for OK (or AC) status.

		Yes, please, don't blame my code.
		I know that it's far from ideal.
		But it should pass all the tests.

		And everybody will be happy.
		And you, my dear reader, too.
		I'm sure.

		Goodbye.)";

		cout << message << endl;
	}
**/

/* _____ INCLUDES _____ */

#include <bits/stdc++.h>

/* _____ NAMESPACES _____ */

using namespace std;

/* _____ CODE _____ */

int main()
{
#ifdef ANDREIKKAA
	assert(freopen("input.txt", "r", stdin) != nullptr);
#endif
	//freopen("output.txt", "w", stdout);

    set<int> vs, hs;
    multiset<long long> vl, hl;

    vs.insert(0);
    hs.insert(0);

    int w, h, n;
    cin >> w >> h >> n;

    vs.insert(w);
    hs.insert(h);

    vl.insert(w);
    hl.insert(h);

    for(int i = 0; i < n; ++i)
	{
		char c;
		int x;
		cin >> c >> x;

		if(c == 'V')
		{
			int r = *vs.upper_bound(x);
			int l = *(--vs.upper_bound(x));

			vs.insert(x);

			int d1 = r - l, d2 = x - l, d3 = r - x;

			vl.erase(vl.find(d1));
			vl.insert(d2);
			vl.insert(d3);
		}
		else if(c == 'H')
		{
			int r = *hs.upper_bound(x);
			int l = *(--hs.upper_bound(x));

			hs.insert(x);

			int d1 = r - l, d2 = x - l, d3 = r - x;

			hl.erase(hl.find(d1));
			hl.insert(d2);
			hl.insert(d3);
		}
		else
			assert(false);

		cout << *--vl.end() * *--hl.end() << endl;
	}





    return 0;
}