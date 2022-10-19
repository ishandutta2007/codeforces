#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
ll n, m, k, d;
ll presize, ans;
set<pair<ll, ll> > inserted;
priority_queue<pair<ll, pair<ll, ll > > > pq;
void amin(ll i, ll j)
{
	if (i < 0 || j < 0 || i >= n || j >= m) return;
	if (inserted.find(make_pair(i, j)) != inserted.end()) return;
	inserted.insert(make_pair(i, j));
	ll x = n-i;
	ll y = m-j;
	x = min(x, d);
	y = min(y, d);
	x -= max((ll)0, (d-i-1));
	y -= max((ll)0, (d-j-1));
	if (x < 0 || y < 0) return;
	ll am = x*y;
	pq.emplace(am, make_pair(i, j));

}
int main()
{
	scanf("%I64d%I64d%I64d%I64d", &n, &m, &d, &k);
	amin(n/2, m/2);
	for (int i = 0; i < k; i++)
	{
		ll x = pq.top().second.first;
		ll y = pq.top().second.second;
		ans += pq.top().first;
	//	printf("%d %d %d\n", x, y, pq.top().first);
		pq.pop();
		amin(x-1, y);
		amin(x+1, y);
		amin(x-1, y-1);
		amin(x, y-1);
		amin(x+1, y-1);
		amin(x-1, y+1);
		amin(x, y+1);
		amin(x+1, y+1);
	}
	ll total = (n-d+1) * (m-d+1);
	ld answer = (ld)ans/total;
	printf("%.12f\n", answer);
	
}