#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define int ll

const int maxn = 1e5 + 20;
const int N = maxn - 10;
const int sq = 320;

vector<int> obj[maxn];

ll a[maxn] , b[maxn];

pair<ll , int> ans[maxn];

int ind[maxn] , Sz[maxn] , t[maxn] , pt[maxn];

double IS(int x , int y)
{
	assert(x != y);
	return (b[y] - b[x]) / (double)(a[y] - a[x]);
}

void build(int l)
{
	int r = min(l + sq , N);

	ind[l] = r - 1;
	int sz = l + 1;
	for(int i = r - 2; i >= l; i--)
	{
		while(sz > l + 1 && IS(ind[sz - 2] , ind[sz - 1]) >= IS(ind[sz - 1] , i))
			sz--;
		ind[sz++] = i;
	}
	Sz[l / sq] = sz;
	reverse(ind + l , ind + Sz[l / sq]);
	pt[l / sq] = l;
}

ll f(int k , ll x)
{
	return a[k] * x + b[k];
}

pair<ll , int> get(int l)
{
	int k = l / sq;
//	pt[k] = l;

	while(pt[k] + 1 < Sz[k] && f(ind[pt[k]] , t[k]) <= f(ind[pt[k] + 1] , t[k])) 
		pt[k]++;

	return make_pair(a[ind[pt[k]]] * t[k] + b[ind[pt[k]]] , ind[pt[k]]);
}

void add(int val)
{
	int l = val / sq * sq;
	for(int i = l; i <= val; i++)
		b[i] += i;
	build(l);

	for(int i = 0; i < l; i += sq)
		t[i / sq]++;
}

pair<ll , int> get_res()
{
	pair<ll , int> res = {0 , 0};
	for(int i = 0; i < N; i += sq)
		res = max(res , get(i));
	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int i = 0; i < N; i++)
		a[i] = i;

	for(int i = 0; i < N; i += sq)
		build(i);

	int n , w;
	cin >> n >> w;

	vector<int> ind;

	int mx = 0;
	for(int i = 0; i < n; i++)
	{
		int a , b;
		cin >> a >> b;
		obj[b].pb(a);
		mx = max(mx , b);
	}

	int t = n;
	for(int i = 0; i <= mx + 1; i++)
	{
		ans[i] = get_res();
		cout << ans[i].first + 1LL * t * w * i << " " << ans[i].second << endl;
		for(auto x : obj[i])
			add(x) , t--;
	}
}