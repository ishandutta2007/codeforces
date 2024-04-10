#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define int ll

const int maxn = 1e6 + 20;

int mx[maxn * 4] , Add[maxn * 4];

int t[maxn] , d[maxn];

void shift(int s , int e , int v)
{
	if(e - s >= 2)
	{
		mx[2 * v] += Add[v];
		mx[2 * v + 1] += Add[v];

		Add[2 * v] += Add[v];
		Add[2 * v + 1] += Add[v];
	}

	Add[v] = 0;
}

void add(int l , int r , int val , int s = 0 , int e = maxn , int v = 1)
{
	if(l <= s && e <= r)
	{
		Add[v] += val;
		mx[v] += val;
		return;
	}
	if(r <= s || e <= l)
		return;

	shift(s , e , v);

	int m = (s + e) / 2;
	add(l , r , val , s , m , 2 * v);
	add(l , r , val , m , e , 2 * v + 1);

	mx[v] = max(mx[2 * v] , mx[2 * v + 1]);
}

int get(int l , int r , int s = 0 , int e = maxn , int v = 1)
{
	if(l <= s && e <= r)
		return mx[v];
	if(r <= s || e <= l)
		return -1e15;

	shift(s , e , v);

	int m = (s + e) / 2;
	return max(get(l , r , s , m , 2 * v) , get(l , r , m , e , 2 * v + 1));
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int i = 0; i < maxn; i++)
		add(i , i + 1 , i);

	int q;
	cin >> q;

	for(int ind = 0; ind < q; ind++)
	{
		char type;
		cin >> type;

		if(type == '+')
		{
			cin >> t[ind] >> d[ind];

			add(t[ind] , maxn , -d[ind]);
		}
		if(type == '-')
		{
			int i;
			cin >> i;
			i--;
			add(t[i] , maxn , d[i]);
		}
		if(type == '?')
		{
			int t;
			cin >> t;

			int tmp = get(0 , t);
			int st = get(t , t + 1);

			if(tmp < st)
			{
				cout << 0 << endl;
				continue;
			}

			cout << tmp - st + 1 << endl;
		}
	}
}