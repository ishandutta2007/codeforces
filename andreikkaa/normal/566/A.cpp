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

const int MAX_N = 200 * 1000 + 10;

pair<string, int> s[MAX_N];
int nxt[MAX_N];
int prv[MAX_N];
int ans[MAX_N];
bool used[MAX_N];

inline int lcp(const string& s, const string& t)
{
	int to = (int) min(s.size(), t.size());

	for(int i = 0; i < to; ++i)
	{
		if(s[i] != t[i])
		{
			return i;
		}
	}

	return to;
}

int main()
{
	_prepare();

	int n;
	cin >> n;

	for(int i = 1; i <= n + n; ++i)
	{
		cin >> s[i].first;
		s[i].second = i;

		nxt[i] = i + 1;
		prv[i] = i - 1;
	}

	sort(s + 1, s + 2 * n + 1);

	/*for(int i = 1; i <= n + n; ++i)
	{
		cout << s[i].first << " " << s[i].second << endl;
	}*/

	set<pair<int, pair<int, int>>> bst;

	for(int i = 1; i < n + n; ++i)
	{
		//cout << s[i].first << " " << s[i + 1].first << endl;
		if((s[i].second > n) != (s[i + 1].second > n))
		{
			//cout << "GO" << endl;
			bst.insert({-lcp(s[i].first, s[i + 1].first), {i, i + 1}});
		}
	}

	int sum = 0;

	while(not bst.empty())
	{
		auto p = *bst.begin();
		bst.erase(bst.begin());

		int a = p.second.first, b = p.second.second;

		//cout << s[a].second << " " << s[b].second << endl;

		if(used[a] or used[b])
		{
			continue;
		}

		//cout << "GOOD" << endl;

		used[a] = true;
		used[b] = true;

		sum -= p.first;

		ans[min(s[a].second, s[b].second)] = max(s[a].second, s[b].second);

		nxt[prv[a]] = nxt[b];
		prv[nxt[b]] = prv[a];

		a = prv[a];
		b = nxt[b];

		if(min(a, b) == 0 or max(a, b) == n + n + 1)
		{
			continue;
		}

		if((s[a].second > n) != (s[b].second > n))
		{
			bst.insert({-lcp(s[a].first, s[b].first), {a, b}});
		}
	}

	cout << sum << endl;

	for(int i = 1; i <= n; ++i)
	{
		cout << i << " " << ans[i] - n << endl;
	}
	
	return 0;
}