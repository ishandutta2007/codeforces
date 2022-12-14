/* ______ INCLUDES ______ */

#include <bits/stdc++.h>

/* _____ NAMESPACES _____ */

using namespace std;

/* ______ TEMPLATE ______ */

typedef long long ll;
typedef long double ld;

inline void _redirect_streams(const string input = "", const string output = "")
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

inline void _pre()
{
#ifdef ANDREIKKAA
	_redirect_streams("input.txt");
#else
	//_redirect_streams("input.txt", "output.txt");
#endif //ANDREIKKAA

	_speed_up_iostreams();
}

inline void _post()
{
#ifdef ANDREIKKAA
	cerr.precision(10);
	cerr << "Execution time: " << clock() / (ld) CLOCKS_PER_SEC << endl;
#endif
}

/* ________ CODE ________ */

namespace std
{
	template<typename S, typename T> struct hash<pair<S, T>>
	{
		inline size_t operator()(const pair<S, T>& v) const
		{
			return hash<int>()(v.first) ^ hash<int>()(v.second);
		}
	};
}

const int MAX_N = 30;

unordered_map<pair<int, int>, pair<int, string>> st;
int to;
int l[MAX_N], m[MAX_N], w[MAX_N];
char s[MAX_N * 2];

void gen(int i, int a, int b, int c)
{
	if(i == to)
	{
		s[2 * i] = '\0';

		pair<int, int> d = {b - a, c - a};

		if(st.find(d) != st.end())
		{
			if(st[d].first < a)
			{
				st[d] = {a, string(s)};
			}
		}
		else
		{
			st[d] = {a, string(s)};
		}

		return;
	}

	s[2 * i] = 'L';
	s[2 * i + 1] = 'M';
	gen(i + 1, a + l[i], b + m[i], c);

	s[2 * i] = 'L';
	s[2 * i + 1] = 'W';
	gen(i + 1, a + l[i], b, c + w[i]);

	s[2 * i] = 'M';
	s[2 * i + 1] = 'W';
	gen(i + 1, a, b + m[i], c + w[i]);
}

pair<int, string> ans = {-1000 * 1000 * 1000, ""};

void gen2(int i, int a, int b, int c, int p = 0)
{
	if(i == to)
	{
		s[2 * p] = '\0';
		pair<int, int> p = {a - b, a - c};
		if(st.find(p) != st.end())
		{
			if(st[p].first + a > ans.first)
			{
				ans = {st[p].first + a, st[p].second + string(s)};
			}
		}
		return;
	}

	s[2 * p] = 'L';
	s[2 * p + 1] = 'M';
	gen2(i + 1, a + l[i], b + m[i], c, p + 1);

	s[2 * p] = 'L';
	s[2 * p + 1] = 'W';
	gen2(i + 1, a + l[i], b, c + w[i], p + 1);

	s[2 * p] = 'M';
	s[2 * p + 1] = 'W';
	gen2(i + 1, a, b + m[i], c + w[i], p + 1);
}

inline void _solve()
{
	st.rehash(1000 * 1000);

	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> l[i] >> m[i] >> w[i];
	}

	to = n / 2;

	gen(0, 0, 0, 0);

	/*for(auto i : st)
	{
		cout << i.first.first << " " << i.first.second << " = " << i.second.first << " " << i.second.second << endl;
	}*/

	to = n;

	gen2(n / 2, 0, 0, 0);

	if(ans.first == -1000 * 1000 * 1000)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		for(int i = 0; i < 2 * n; i += 2)
		{
			cout << ans.second[i] << ans.second[i + 1] << endl;
		}
	}
}

int main()
{
	_pre();

	_solve();

	_post();

	return 0;
}