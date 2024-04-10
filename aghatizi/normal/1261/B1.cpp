#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int a[maxn] , p[maxn] , ans[maxn] , b[maxn];

vector<int> pos[maxn] , query[maxn] , shit[maxn];

int seg[maxn * 4] , n , cnt[maxn];

void add(int p , int val , int s = 0 , int e = n , int v = 1)
{
	if(e - s < 2)
	{
		seg[v] += val;
		return;
	}
	int m = (s + e) / 2;

	if(p < m)
		add(p , val , s , m , 2 * v);
	else
		add(p , val , m , e , 2 * v + 1);
	
	seg[v] = seg[2 * v] + seg[2 * v + 1];
}

int get(int p , int s = 0 , int e = n , int v = 1)
{
	if(e - s < 2)
		return s;

	int m = (s + e) / 2;
	if(seg[2 * v] <= p)
		return get(p - seg[2 * v] , m , e , 2 * v + 1);
	else
		return get(p , s , m , 2 * v);
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

	sort(cmp.begin() , cmp.end());
	cmp.resize(unique(cmp.begin() , cmp.end()) - cmp.begin());

	for(int i = 0; i < n; i++)
		a[i] = lower_bound(cmp.begin() , cmp.end() , a[i]) - cmp.begin() , pos[a[i]].pb(i) , b[i] = a[i];

	sort(b , b + n);

	int q;
	cin >> q;

	for(int i = 0; i < q; i++)
	{
		int k;
		cin >> k >> p[i];
		p[i]--;
		if(k == n)
			ans[i] = p[i];
		else
		{
			int r = b[n - k];
			int x = upper_bound(b , b + n , r) - b;
			cnt[i] = k - (n - x);
			query[r].pb(i);
		}
	}

	for(int i = cmp.size() - 1; i >= 0; i--)
	{
		for(auto ind : query[i])
			shit[cnt[ind] - 1].pb(ind);

		for(int j = 0; j < (int)pos[i].size(); j++)
		{
			add(pos[i][j] , 1);
			for(auto ind : shit[j])
				ans[ind] = get(p[ind]);
			shit[j].clear();
		}
	}

	for(int i = 0; i < q; i++)
		cout << cmp[a[ans[i]]] << endl;
}