#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES": "NO")
#define all(x) x.begin(),x.end()
#define ll long long
#define pii pair<int,int>
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
#define Kill(x) {cout << x << '\n'; return 0;}
using namespace std;

const int N = 200010;
const double e = 1e-11;
double a[N];
int n;

double miin, maax;
double Min, Max;
void Do(double t)
{
	Min = 1e9;
	Max = -1e9;
	double sum = 0;
	double in = 0, ax = 0;
	Loop(i, 0, n)
	{
		sum += a[i] + t;
		in = min(in, sum);
		ax = max(ax, sum);
		Min = min(Min, sum - ax);
		Max = max(Max, sum - in);
	}
	if (!Min) Min = miin + t;
	if (!Max) Max = maax + t;
}

void binup()
{
	double l = 0, r = 10000;
	while (r - l > e)
	{
		double m = (l + r) / 2;
		Do(m);
		if (-Min < Max)
			r = m;
		else
			l = m;
	}
	Do(l);
}
void bindown()
{
	double l = -10000, r = 0;
	while (r - l > e)
	{
		double m = (l + r) / 2;
		Do(m);
		if (-Min > Max)
			l = m;
		else
			r = m;
	}
	Do(l);
}

int main()
{
	scanf("%I64d", &n);
	miin = 1e9;
	maax = -1e9;
	Loop(i, 0, n)
	{
		float x;
		scanf("%f", &x);
		a[i] = x;
		miin = min(miin, a[i]);
		maax = max(maax, a[i]);
	}
	Do(0);
	if (-Min < Max)
		bindown();
	else
		binup();
	printf("%0.12f",(Max - Min) / 2);
}