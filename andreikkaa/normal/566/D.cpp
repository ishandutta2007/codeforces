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

const int MAX_N = 200 * 1000 + 1;

int dsu[MAX_N];
set<int> fst;

int dsu_get(int x)
{
	if(dsu[x] == x)
		return x;

	dsu[x] = dsu_get(dsu[x]);

	return dsu[x];
}

void dsu_unite(int a, int b)
{
	a = dsu_get(a);
	b = dsu_get(b);

	dsu[a] = b;
}

int main()
{
	_prepare();

	int n, q;
	scanf("%d %d", &n, &q);

	for(int i = 0; i < n; ++i)
	{
		fst.insert(i);
		dsu[i] = i;
	}

	for(int i = 0; i < q; ++i)
	{
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);
		--x;
		--y;

		if(t == 1)
		{
			dsu_unite(x, y);
		}
		else if(t == 2)
		{
			auto it = --fst.upper_bound(x);
			auto ar = it;
			int val = *it;

			while(it != fst.end() and *it <= y)
			{
				dsu_unite(val, *it);
				++it;
			}

			fst.erase(++ar, it);
		}
		else
		{
			if(dsu_get(x) == dsu_get(y))
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}
	
	return 0;
}