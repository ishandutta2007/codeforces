#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int maxk = 3e5 + 20;

vector<int> seg[maxn * 4] , mn[maxn * 4] , obj[maxn];

int l[maxk] , r[maxk] , type[maxk];

inline bool cmp(int a , int b)
{
	return r[a] < r[b];
}

void build(int s , int e , int v)
{
	if(e - s < 2)
	{
		sort(obj[s].begin() , obj[s].end() , cmp);

		int last = 0 , tmp = -1;
		for(auto ind : obj[s])
		{
			if(r[ind] != last)
			{
				seg[v].pb(last);
				mn[v].pb(tmp);
				last = r[ind];
			}

			tmp = max(tmp , l[ind]);
		}

		seg[v].pb(last);
		mn[v].pb(tmp);

		return;
	}

	int m = (s + e) / 2 , L = 2 * v , R = 2 * v + 1;

	build(s , m , L);
	build(m , e , R);

	seg[v].resize(seg[L].size() + seg[R].size());
	merge(seg[L].begin() , seg[L].end() , seg[R].begin() , seg[R].end() , seg[v].begin());
	seg[v].resize(unique(seg[v].begin() , seg[v].end()) - seg[v].begin());

	int pt1 = 0 , pt2 = 0;
	for(auto x : seg[v])
	{
		while(pt1 < (int)seg[L].size() && seg[L][pt1] <= x)
			pt1++;
		while(pt2 < (int)seg[R].size() && seg[R][pt2] <= x)
			pt2++;

		mn[v].pb(min(mn[L][pt1 - 1] , mn[R][pt2 - 1]));
	}
}

int get(int l , int r , int val , int s , int e , int v)
{
	if(l <= s && e <= r)
	{
		int ind = upper_bound(seg[v].begin() , seg[v].end() , val) - seg[v].begin() - 1;
		return mn[v][ind];
	}

	if(r <= s || e <= l)
		return 2e9;

	int m = (s + e) / 2;

	return min(get(l , r , val , s , m , 2 * v) , get(l , r , val , m , e , 2 * v + 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m , k;
	cin >> n >> m >> k;

	for(int i = 0; i < k; i++)
	{
		cin >> l[i] >> r[i] >> type[i];
		l[i]--;
		type[i]--;

		obj[type[i]].pb(i);
	}

	build(0 , n , 1);

	while(m--)
	{
		int a , b , x , y;
		cin >> a >> b >> x >> y;
		a--;
		x--;

		int res = get(a , b , y , 0 , n , 1);

		if(res >= x)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}