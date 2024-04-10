#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e7 + 20;

ll l , r;

ll a[maxn] , st[maxn];

inline ll get(unsigned int b)
{
	return ((ll)b % (r - l + 1)) + l;
}

void solve()
{
	int n;
	unsigned int X , y , z , b0 , b1;
	cin >> n >> l >> r >> X >> y >> z >> b0 >> b1;

	a[0] = get(b0) , a[1] = get(b1);

	bool f = 0;
	ll mn = min(a[0] , a[1]) , res = 7e18;
	if(a[0] < a[1])
		res = 1LL * a[0] * a[1] , f = 1;

	for(int i = 2; i < n; i++)
	{
		unsigned int nb = (b0 * X + b1 * y + z);
		a[i] = get(nb);

		b0 = b1;
		b1 = nb;

		if(mn < a[i])
			res = min(res , a[i] * mn) , f = 1;
		else
			mn = a[i];
	}

	if(!f)
	{
		cout << "IMPOSSIBLE" << endl;
		return;
	}

/*	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] < a[j])
				res = min(res , 1LL * a[i] * a[j]);*/

	int pt = 0;
	for(int i = 0; i < n; i++)
		if(a[i] <= 0)
			a[pt++] = a[i];

	n = pt;
	pt = 0;
	for(int i = 0; i < n; i++)
	{
		while(pt && a[st[pt - 1]] <= a[i])
			pt--;
		st[pt++] = i;
	}

	int last = -1;
	for(int i = 0; i < pt; i++)
		for(last++; last < st[i]; last++)
			if(a[last] < a[st[i]])
				res = min(res , a[st[i]] * a[last]);

	cout << res << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while(t--)
		solve();
}