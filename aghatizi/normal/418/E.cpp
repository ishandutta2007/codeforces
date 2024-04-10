#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define lb(a) ((a)&(-(a)))

const int maxn = 1e5 + 20;
const int sq = 1e4 + 20;
const int qs = maxn / sq + 20;

int x[maxn] , y[maxn] , v[maxn] , p[maxn] , a[maxn] , type[maxn];

int t[qs][maxn * 2] , fen[qs][maxn] , n;

void add(int id , int p , int val)
{
	for(p = maxn - 10 - p; p < maxn; p += lb(p))
		fen[id][p] += val;
}

int get(int id , int p)
{
	int res = 0;
	for(p = maxn - 10 - p; p > 0; p ^= lb(p))
		res += fen[id][p];

	return res;
}

void build(int l)
{
	int id = l / sq;

	if(id > 0)
	{
		for(int i = 0; i < maxn * 2; i++)
			t[id][i] = t[id - 1][i];

		for(int i = l - sq; i < l; i++)
			t[id][a[i]]++;
	}

	for(int i = 0; i < maxn * 2; i++)
		add(id , t[id][i] , 1);
}

void handle(int &k , int lim , int &res , int val)
{
	if(val == 1)
	{
		if(k == lim - 1)
			res++;
	}
	else
	{
		if(k == lim)
			res--;
	}

	k += val;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	vector<int> cmp;
	for(int i = 0; i < n; i++)
		cin >> a[i] , cmp.pb(a[i]);

	int q;
	cin >> q;

	for(int i = 0; i < q; i++)
	{
		cin >> type[i];

		if(type[i] == 1)
			cin >> v[i] >> p[i] , cmp.pb(v[i]) , p[i]--;
		else
			cin >> x[i] >> y[i] , y[i]--;
	}

	sort(cmp.begin() , cmp.end());
	cmp.resize(unique(cmp.begin() , cmp.end()) - cmp.begin());

	for(int i = 0; i < n; i++)
		a[i] = lower_bound(cmp.begin() , cmp.end() , a[i]) - cmp.begin();

	for(int i = 0; i < q; i++)
		if(type[i] == 1)
			v[i] = lower_bound(cmp.begin() , cmp.end() , v[i]) - cmp.begin();

	for(int i = 0; i < n; i += sq)
		build(i);

	for(int i = 0; i < q; i++)
	{
		if(type[i] == 1)
		{
			int pst = a[p[i]] , nw = v[i];

			for(int j = (p[i] / sq + 1) * sq , id = p[i] / sq + 1; j < n; j += sq , id++)
			{
				add(id , t[id][pst] , -1);
				t[id][pst]--;
				add(id , t[id][pst] , 1);

				add(id , t[id][nw] , -1);
				t[id][nw]++;
				add(id , t[id][nw] , 1);
			}

			a[p[i]] = nw;
		}
		else
		{
			if(x[i] == 1)
			{
				cout << cmp[a[y[i]]] << endl;
				continue;
			}

			x[i] %= 2;

			int id = y[i] / sq , T = t[id][a[y[i]]];

			for(int j = id * sq; j <= y[i]; j++)
				T += (a[j] == a[y[i]]);	

			if(x[i] == 0)
			{
				cout << T << endl;
				continue;
			}

			int res = get(id , T);

			for(int j = id * sq; j <= y[i]; j++)
				handle(t[id][a[j]] , T , res , 1);

			cout << res << endl;

			for(int j = id * sq; j <= y[i]; j++)
				handle(t[id][a[j]] , T , res , -1);
		}
	}
}