#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

struct PI
{
	ll x, y;
	PI(){}
	PI(ll _, ll __)
	{
		x = _, y = __;
	}
	friend bool operator < (PI x, PI y)
	{
		return x.x < y.x;
	}
};

PI X[200010];

int Q[200010], T = 0, W = 1;

map <ll, ll> hsh;

int main()
{
	ll n, d, m;
	scanf("%lld%lld%lld", &n, &d, &m);
	X[1] = PI(0, 0);
	for(int i = 2; i <= m + 1; i++)
	{
		scanf("%lld%lld", &X[i].x, &X[i].y);
	}
	X[m + 2] = PI(n, 0);
	m += 2, sort(X + 1, X + m + 1);
	int t = 1;
	ll ans = 0, res = d;
	hsh.clear();
	for(int i = 1; i < m;)
	{
		bool getans = 0;
		while(t < m && X[t + 1].x - X[i].x <= d)
		{
			if(X[t + 1].y < X[i].y)
			{
				t++;
				ans += (X[t].x - X[i].x - res) * X[i].y;
				res = 0;
				getans = 1;
				i = t;
				hsh.clear();
				break;
			}
			t++;
			hsh[X[t].y]++;
		}
		if(getans == 0)
		{
			if(t <= i)
			{
				puts("-1");
				return 0;
			}
			ll Min = (hsh.begin())->first, j;
			for(j = i + 1; j <= t; j++)
			{
				hsh[X[j].y]--;
				if(!hsh[X[j].y]) hsh.erase(X[j].y);
				if(X[j].y == Min) break;
			}
			ans += (d - res) * X[i].y, res = d - (X[j].x - X[i].x);
			i = j;
		}
	}
	printf("%lld\n", ans);
	return 0;
}