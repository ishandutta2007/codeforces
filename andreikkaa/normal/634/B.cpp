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

	vec<ll> get_bits(ll x)
	{
		vec<ll> ans = {0};
		while(x > 0)
		{
			ans.push_back(x % 2);
			x /= 2;
		}
		//reverse(s.begin(), s.end());
		return ans;
	}

	inline void solve()
	{
		ll s, x;
		in(s, x);

		static ll cnt[60][2][2];
		cnt[0][0][1] = 1;

		auto sm = get_bits(s);
		auto xr = get_bits(x);
		auto mx = max(sm.size(), xr.size());

		sm.resize(mx, 0);
		xr.resize(mx, 0);
		deb(sm);
		deb(xr);

		for(int i = 1; i < mx; ++i)
		{
			if(sm[i] == 0 and xr[i] == 0)
			{
				cnt[i][0][1] += cnt[i - 1][0][1];
				cnt[i][1][1] += cnt[i - 1][0][1];
				cnt[i][0][0] += cnt[i - 1][0][0];
				cnt[i][1][0] += cnt[i - 1][0][0];
			}
			else if(sm[i] == 0 and xr[i] == 1)
			{
				cnt[i][1][0] += 2 * cnt[i - 1][1][0];
				cnt[i][1][0] += 2 * cnt[i - 1][1][1];
			}
			else if(sm[i] == 1 and xr[i] == 0)
			{
				cnt[i][0][1] += cnt[i - 1][1][1];
				cnt[i][1][1] += cnt[i - 1][1][1];
				cnt[i][0][0] += cnt[i - 1][1][0];
				cnt[i][1][0] += cnt[i - 1][1][0];
			}
			else
			{
				cnt[i][0][0] += 2 * cnt[i - 1][0][0];
				cnt[i][0][1] += 2 * cnt[i - 1][0][1];
			}
			//out(cnt[i][0][0], cnt[i][0][1], cnt[i][1][0], cnt[i][1][1]);
		}
		ll res = cnt[mx - 1][0][0] + cnt[mx - 1][0][1];
		if(s == x)
		{
			res -= 2;
		}
		out(res);
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