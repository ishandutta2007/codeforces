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

struct event
{
	int t; //0 - bridge, 1 - open
	int n;
	ll x;
	ll cls;

	inline event(const ll _x, const int _t, const int _n, const ll _cls = -1)
	{
		x = _x;
		t = _t;
		n = _n;
		cls = _cls;
	}

	inline bool operator<(const event& a) const
	{
		if(x != a.x)
			return x < a.x;

		return t == 1;
	}
};

bool cmp(const event* a, const event* b)
{
	if(a->x != b->x)
		return a->x < b->x;

	return a->t > b->t;
}

int main()
{
	_prepare();

	int used[200000];
	vector<event*> v;

	int n, m;
	scanf("%d %d", &n, &m);

	ll lo = -1, ro = -1;

	for(int i = 0; i < n; ++i)
	{
		ll l, r;
		scanf("%lld %lld", &l, &r);
		if(i > 0)
		{
			v.push_back(new event(l - ro, 1, i - 1, r - lo));
		}

		lo = l;
		ro = r;

		used[i] = -1;
	}

	for(int i = 0; i < m; ++i)
	{
		ll x;
		scanf("%lld", &x);
		v.push_back(new event(x, 0, i));
	}

	stable_sort(v.begin(), v.end(), cmp);

	set<pair<ll, int>> s; //{closing time, number}
	
	for(const auto& i : v)
	{
		if(i->t == 0)
		{
			while(not s.empty() and s.begin()->first < i->x)
			{
				s.erase(s.begin());
			}
			if(not s.empty())
			{
				auto p = *s.begin();
				s.erase(s.begin());

				used[p.second] = i->n;
			}
		}
		else
		{
			s.insert({i->cls, i->n});
		}
	}

	if(find(used, used + n - 1, -1) != used + n - 1)
	{
		printf("No\n");
		return 0;
	}
	
	printf("Yes\n");
	for(int i = 0; i < n - 1; ++i)
		printf("%d ", used[i] + 1);
	printf("\n");

	return 0;
}