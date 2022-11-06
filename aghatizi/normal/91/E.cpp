#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int maxb = 18;

int n , a[maxn] , b[maxn];

vector<int> seg[maxn * 4];

bool cmpb(int x , int y)
{
	return make_pair(b[x] , a[x]) > make_pair(b[y] , a[y]);
}

double IS(int x , int y)
{
	return (b[y] - b[x]) / (double)(a[x] - a[y]);
}

void build(int s = 0, int e = n , int v = 1)
{
	seg[v].reserve(e - s);
	for(int i = s; i < e; i++)
		seg[v].pb(i);
	sort(seg[v].begin() , seg[v].end() , cmpb);

	vector<int> st;
	st.pb(seg[v][0]);
	int mx = a[st.back()] , sz = 1;
	for(auto ind : seg[v])
	{
		if(a[ind] <= mx)
			continue;
		mx = a[ind];

		while(sz > 1 && IS(st[sz - 2] , st[sz - 1]) >= IS(st[sz - 1] , ind))
			st.pop_back() , sz--;
		st.pb(ind);
		sz++;
	}
	seg[v] = st;

	if(e - s < 2)
		return;

	int m = (s + e) / 2;
	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);
}

ll f(int ind , int t)
{
	return 1LL * a[ind] * t + b[ind];
}

pair<ll , int> get(int l , int r , int t , int s = 0 , int e = n , int v = 1)
{
	if(l <= s && e <= r)
	{
		int L = -1 , R = (int)seg[v].size() - 1;
		while(R - L > 1)
		{
			int M = (L + R) / 2;
			if(IS(seg[v][M] , seg[v][M + 1]) <= t)
				L = M;
			else
				R = M;
		}

		return make_pair(f(seg[v][R] , t) , seg[v][R]);
	}
	if(r <= s || e <= l)
		return make_pair(-1 , 0);

	int m = (s + e) / 2;
	return max(get(l , r , t , s , m , 2 * v) , get(l , r , t , m , e , 2 * v + 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> n >> q;

	for(int i = 0; i < n; i++)
		cin >> b[i] >> a[i];

	build();

	for(int i = 0; i < q; i++)
	{
		int l , r , t;
		cin >> l >> r >> t;
		l--;
		
		cout << get(l , r , t).second + 1 << endl;
	}
}