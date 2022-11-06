#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
 
const int maxn = 2e5 + 20;
const int mod = 1e9 + 7;
 
struct node
{
	int mn , sum;
 
	node()
	{
		mn = 2e9;
		sum = 0;
	}
};
 
int l[maxn] , r[maxn] , n;
 
int dp[maxn] , pd[maxn];
 
vector<int> t[maxn];
 
node seg[maxn * 4];
 
void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}
 
node merge(node a , node b)
{
	node c;
	c.mn = min(a.mn , b.mn);
	if(a.mn == c.mn)
		mkay(c.sum += a.sum);
	if(b.mn == c.mn)
		mkay(c.sum += b.sum);
	return c;
}
 
void upd(int p , int s = 1 , int e = n + 1 , int v = 1)
{
	if(e - s < 2)
	{
		seg[v].mn = dp[s] - r[s];
		seg[v].sum = pd[s];
		return;
	}
 
	int m = (s + e) / 2;
	if(p < m)
		upd(p , s , m , 2 * v);
	else
		upd(p , m , e , 2 * v + 1);
 
	seg[v] = merge(seg[2 * v] , seg[2 * v + 1]);
}
 
node get(int l , int r , int s = 1 , int e = n + 1 , int v = 1)
{
	if(l <= s && e <= r)
		return seg[v];
	if(r <= s || e <= l)
		return seg[maxn * 4 - 10];
 
	int m = (s + e) / 2;
	return merge(get(l , r , s , m , 2 * v) , get(l , r , m , e , 2 * v + 1));
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	cin >> n;
	vector<pair<int , int> > tmp;
	for(int i = 0; i < n; i++)
	{
		cin >> r[i] >> l[i];
		tmp.pb({r[i] , l[i]});
	}
 
	sort(tmp.begin() , tmp.end());
	for(int i = 1; i <= n; i++)
		l[i] = tmp[i - 1].second , r[i] = tmp[i - 1].first;
 
	for(int i = 1; i <= n; i++)
	{
		int k = upper_bound(r + 1 , r + n + 1 , l[i]) - r - 1;
		if(!k)
		{
			dp[i] = l[i];
			pd[i] = 1;
		}
		else
			t[k].pb(i);
	}
 
	int pt = 1 , mnx = 2e9;
	for(int i = 1; i <= n; i++)
	{
		while(pt < i && r[pt] <= l[i])
			pt++;
		upd(i);
 
		for(auto ind : t[i])
		{
			auto tmp = get(pt , i + 1);
			dp[ind] = tmp.mn + l[ind];
			pd[ind] = tmp.sum;
		}
 
		mnx = min(mnx , dp[i]);
	}
 
	int mx = -1e9;
 
	node tmpx;
	for(int i = n; i >= 1; i--)
	{
		if(r[i] > mx)
		{
			node shit;
			shit.mn = dp[i] , shit.sum = pd[i];
			tmpx = merge(tmpx , shit);
		}
		mx = max(mx , l[i]);
	}
 
	cout << tmpx.sum << endl;
}