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

class FenwickTree
{
public:
	vec<ll> t;

	ll get(int x)
	{
		ll ans = 0;
		for(; x >= 0; x = (x & (x + 1)) - 1)
		{
			ans += t[x];
		}
		return ans;
	}

	void upd(int x, ll val)
	{
		for(; x < t.size(); x |= (x + 1))
		{
			t[x] += val;
		}
	}

	void init(int n)
	{
		t.resize((unsigned long) (2 * n));
	}
};

class Solution
{
public:
	Reader in;
	Writer out;
	Debug deb;

	FenwickTree ta, tb;

	inline void solve()
	{
		int n, k, a, b, q;
		in(n, k, a, b, q);
		swap(a, b);

		vec<int> aa(n + 1), bb(n + 1);
		ta.init(n + 1);
		tb.init(n + 1);

		for(int i = 0; i < q; ++i)
		{
			int t;
			in(t);

			if(t == 1)
			{
				int di, ai;
				in(di, ai);

				ll ao = aa[di];
				aa[di] = min(a, aa[di] + ai);
				ll ad = aa[di] - ao;
				ta.upd(di, ad);

				ll bo = bb[di];
				bb[di] = min(b, bb[di] + ai);
				ll bd = bb[di] - bo;
				tb.upd(di, bd);
			}
			else
			{
				int p;
				in(p);
				/*deb(ta.get(p - 1) );
				deb(tb.get(n) - tb.get(p + k - 1));*/
				out(ta.get(p - 1) + tb.get(n) - tb.get(p + k - 1));
			}
		}
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