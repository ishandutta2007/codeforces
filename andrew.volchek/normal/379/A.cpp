#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cctype>
#include <cstring>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define y0 _y0
#define y1 _y1


int main()
{
	//freopen("a.in", "r", stdin);
	ll a, b;
	ll left = 0;
	cin >> a >> b;
	ll ans = 0;
	while (a)
	{
		ans += a;
		ll t = (a + left) % b;
		a = (a + left) / b;
		left = t;
	}
	cout << ans;

	return 0;
}