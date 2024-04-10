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
	cerr << "Execution time: " << clock() / (ld)CLOCKS_PER_SEC << endl;
#endif
}

/* ________ CODE ________ */

struct point
{
	ll x, y;
};

ld sqr(ld x)
{
	return x * x;
}

ld dist_p_p(ld ax, ld ay, ld az, ld bx, ld by, ld bz){
	return sqr(ax-bx)+sqr(ay-by)+sqr(az-bz);
}

ld dist_p_s(ld ox, ld oy, ld oz, ld ax, ld ay, ld az, ld bx, ld by, ld bz){
	ld p, s, a, b, c;

	a=dist_p_p(ox,oy,oz,ax,ay,az);
	b=dist_p_p(ox,oy,oz,bx,by,bz);
	c=dist_p_p(ax,ay,az,bx,by,bz);

	if(a>=b+c) return sqrt(b);
	if(b>=a+c) return sqrt(a);

	a=sqrt(a); b=sqrt(b); c=sqrt(c);
	p=(a+b+c)/2;
	s=sqrt((p-a)*(p-b)*(p-c)*p);

	return s*2/c;
}


inline void _solve()
{
	const ld PI = 3.14159265358979323846;
	const ld INF = 1e15;

	int n;
	ll x, y;
	cin >> n >> x >> y;

	ld mi = INF;
	ld ma = -1;
	vector<point> p;

	for(int i = 0; i < n; ++i)
	{
		ll a, b;
		cin >> a >> b;
		p.push_back(point{a, b});

		ld d = hypot(a - x, b - y);

		mi = min(mi, d);
		ma = max(ma, d);
	}

	for(int i = 0; i < n; ++i)
	{
		int j = (i + 1) % n;
		mi = min(mi, dist_p_s(x, y, 0, p[i].x, p[i].y, 0, p[j].x, p[j].y, 0));
	}

	cout.precision(228);
	cout << PI * ma * ma - PI * mi * mi << endl;
}

int main()
{
	_pre();

	_solve();

	_post();

	return 0;
}