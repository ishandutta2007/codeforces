#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <cassert>
#include <iomanip>

using namespace std;

typedef long double ftype;

const ftype pi = acosl(-1);

void addArc(ftype a, ftype b);

void processLineCircle(ftype a, ftype b, ftype c, ftype r)
{
	ftype x0 = -a*c/(a*a+b*b),  y0 = -b*c/(a*a+b*b);
	
	ftype d = r*r - c*c/(a*a+b*b);
	if (d < 0) d = 0;
	
	ftype mult = sqrt (d / (a*a+b*b));
	ftype ax,ay,bx,by;
	ax = x0 + b * mult;
	bx = x0 - b * mult;
	ay = y0 - a * mult;
	by = y0 + a * mult;
	//puts ("2 points");
	//cout << ax << ' ' << ay << '\n' << bx << ' ' << by << '\n';
	
	ftype one = atan2l(by, bx);
	ftype two = atan2l(ay, ax);
	
	one += pi;
	two += pi;
	
	#ifdef LOCAL
	cout << "got arc " << one << " " << two << endl; 
	#endif
	
	addArc(one, two);
}

void processCircles(ftype x, ftype y, ftype r, ftype R)
{
	processLineCircle(-2 * x, -2 * y, x * x + y * y + R * R - r * r, R);
}

struct event
{
	ftype x;
	bool open;
	
	bool operator<(const event& e) const
	{
		if (x != e.x)
			return x < e.x;
		else
			return !open < !e.open;
	}
};

vector<event> events;

void addPure(ftype a, ftype b)
{
	assert(a <= b);
	
	events.push_back(event { a, true });
	events.push_back(event { b, false });
	
	#ifdef LOCAL
	cout << "got event pair " << a << " " << b << endl;
	#endif
}

void addArc(ftype a, ftype b)
{
	// both a, b belong to [0, 2 * PI)
	// and arc length is less than PI
	
	if (abs(a - b) <= pi)
	{
		if (a > b) swap(a, b);
		addPure(a, b);
	}
	else
	{
		// two arcs: [0, min(a, b)
		// and [max(a, b), 2 * PI]
		
		addPure(0, min(a, b));
		addPure(max(a, b), 2 * pi);
	}
}

void solve()
{
	events.clear();
	cout << fixed << setprecision(12);
	
	int n, d;
	scanf("%d %d", &n, &d);
	
	for (int i = 0; i < n; i++)
	{
		int x, y, r;
		scanf("%d %d %d", &x, &y, &r);
		
		ftype l = hypotl(x, y);
		
		int pMin = ceil((l - r) / d - 1e-9);
		int pMax = floor((l + r) / d + 1e-9);
		
		#ifdef LOCAL
		printf("got range %d..%d\n", pMin, pMax);
		#endif
		
		for (int j = pMin; j <= pMax; j++)
		{
			processCircles(x, y, r, d * j);
		}
	}
	
	sort(events.begin(), events.end());
	
	int answer = 0, balance = 0;
	for (auto it: events)
	{
		if (it.open)
			balance++;
		else
			balance--;
		answer = max(answer, balance);
	}
	
	printf("%d\n", answer);
}

int main()
{
	#ifdef LOCAL
	freopen("e.in", "r", stdin);
	int nTests;
	scanf("%d", &nTests);
	for (int i = 0; i < nTests; i++)
	{
		solve();
		printf("\n");
	}
	#else
	solve();
	#endif
	
	return 0;
}