/*
 * C++11 code template for contests.
 * @author: Andrey Kalendarov
 * @e-mail: andreykalendarov@gmail.com
 */

/* ______ TEMPLATE ______ */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

template<class T>
class vec : public vector<T>
{
	using vector<T>::vector;
public:
	T &operator[](const size_t x)
	{
		return this->at(x);
	}
};

template<typename T>
ostream &operator<<(ostream &out, const vec<T> &v)
{
	if(v.empty())
		return out;
	out << v.front();
	for(auto it = ++v.begin(); it != v.end(); ++it)
		out << ' ' << *it;
	return out;
}

template<typename T>
istream &operator>>(istream &in, vec<T> &v)
{
	for(auto &i : v)
		in >> i;
	return in;
}

class Reader
{
private:
	void setup()
	{ cin.tie(nullptr), ios_base::sync_with_stdio(false); }

public:
	Reader()
	{ setup(); }

	Reader(const char *s)
	{ setup(), freopen(s, "r", stdin); }

	~Reader()
	{ fclose(stdin); }

	template<typename T>
	inline void operator()(T &t)
	{ cin >> t; }

	template<typename T, typename... Args>
	inline void operator()(T &t, Args &... args)
	{ operator()(t), operator()(args...); }
};

class Writer
{
private:
	void setup()
	{ /*cout.precision(20);*/ }

public:
	Writer()
	{ setup(); }

	Writer(const char *s)
	{ setup(), freopen(s, "w", stdout); }

	~Writer()
	{ fflush(stdout), fclose(stdin); }

	template<typename T>
	inline void raw(T x)
	{ cout << x; }

	template<typename T, typename... Args>
	inline void raw(T x, Args... args)
	{ raw(x), raw(args...); }

	inline void operator()()
	{ raw('\n'); }

	template<typename T>
	inline void operator()(T t)
	{ raw(t), raw('\n'); }

	template<typename T, typename... Args>
	inline void operator()(T x, Args... args)
	{ raw(x), raw(' '), operator()(args...); };
};

class Debug
{
public:
	Debug()
	{ }

	~Debug()
	{ operator()("Time:", clock() / (ld) CLOCKS_PER_SEC); }

	template<typename T>
	inline void raw(T x)
	{
#ifdef ANDREIKKAA
		cout << x;
#endif
	}

	template<typename T>
	inline void fmt(T t)
	{ raw(t); }

	template<typename T, typename... Args>
	inline void fmt(T x, Args... args)
	{ raw(x), raw(' '), fmt(args...); };

	template<typename... Args>
	inline void operator()(Args... args)
	{ raw("<<"), fmt(args...), raw(">>"), raw('\n'); };
};

/* ________ CODE ________ */

class Solution
{
public:
	Reader in;
	Writer out;
	Debug deb;

	inline void solve()
	{
		int n, b;
		in(n, b);

		vec<pair<ll, ll>> v(n);
		for(int i = 0; i < n; ++i)
		{
			cin >> v[i].first >> v[i].second;
		}

		deque<ll> q;
		for(int i = 0; i < n; ++i)
		{
			while(not q.empty() and q.front() <= v[i].first)
			{
				q.pop_front();
			}

			if(q.size() < b + 1)
			{
				if(q.empty())
				{
					q.push_back(v[i].first + v[i].second);
				}
				else
				{
					q.push_back(q.back() + v[i].second);
				}
				out.raw(q.back(), ' ');
			}
			else
			{
				out.raw("-1 ");
			}
		}
		out();
	}

	Solution() :

#ifdef ANDREIKKAA
			in("input.txt"), out(), deb()
#else
	in(), out(), deb()
#endif
	{ }
};

int main()
{
	static Solution s;
	s.solve();
}