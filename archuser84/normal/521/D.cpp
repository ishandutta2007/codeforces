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
using namespace std;

const int N = 100010;

int k, m, n;
int a[N];
struct item
{
	int n;
	int t, i, b;
	double imp = -1;
	bool ans = 0;
}it[N];

// daste //
vector<int> t1[N];
vector<int> t2[N];
vector<int> t3[N];

// sortin' //
bool comp(int a, int b)
{
	return it[a].b > it[b].b;
}
bool compf(item a, item b)
{
	return a.ans > b.ans || (a.ans == b.ans && a.t < b.t);
}

int main()
{
	FAST;
	//srand(time(NULL));
	cin >> k >> n >> m;
	Loop(i, 0, k)
		cin >> a[i];
		//a[i] = rand() % 999999 + 1;
	Loop(i, 0, n)
	{
		it[i].n = i + 1;
		cin >> it[i].t >> it[i].i >> it[i].b; it[i].i--;
		//it[i].t = rand() % 3 + 1; it[i].i = rand() % k; it[i].b = rand() % 999999 + 1;
		switch (it[i].t)
		{
		case 1: t1[it[i].i].push_back(i); break;
		case 2: t2[it[i].i].push_back(i); break;
		case 3: t3[it[i].i].push_back(i); it[i].imp = it[i].b; break;
		}
	}

	/// 1 to 2 ///
	Loop(i, 0, k)
	{
		if (t1[i].empty())
			continue;
		int maax = 0;
		Loop(j, 0, t1[i].size())
		{
			if (it[t1[i][j]].b > it[t1[i][maax]].b)
				maax = j;
		}
		maax = t1[i][maax];
		if (it[maax].b <= a[it[maax].i])
			continue;
		it[maax].b = it[maax].b - a[it[maax].i];
		t2[i].push_back(maax);
	}

	/// 2 to 3 ///
	Loop(i, 0, k)
	{
		if (t2[i].empty())
			continue;
		sort(all(t2[i]), comp);
		ll x = a[i];
		Loop(j, 0, t2[i].size())
		{
			it[t2[i][j]].imp = (double)(x + it[t2[i][j]].b) / x;
			x += it[t2[i][j]].b;
		}
	}

	/// finding the ones ///
	sort(it, it + n, [](item a, item b)
		{
			return a.imp > b.imp;
		});
	int ans = 0;
	for (int i = 0; i < n && ans < m; i++)
	{
		if (it[i].imp < 1)
			break;
		it[i].ans = 1;
		ans++;
	}

	/// print the answer ///
	sort(it, it + n, compf);
	cout << ans << '\n';
	Loop(i, 0, ans)
	{
		cout << it[i].n << ' ';
	}
}