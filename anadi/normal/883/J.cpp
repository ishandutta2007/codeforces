#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
int a[N];
pair<int, int> tab[N];
const int offset = 1 << 17;
typedef long long ll;
ll sum[offset << 1];
ll mn[offset << 1];
const ll inf = 1e17;

void insert(int p, ll x)
{
	p += offset;
	sum[p] += x;
	mn[p] += x;
	while(p > 1)
	{
		p >>= 1;
		sum[p] = sum[p*2] + sum[p*2+1];
		mn[p] = min(mn[p*2], mn[p*2+1] + sum[p*2]);
	}
}

ll sump(int p)
{
	int a = offset, b = p + offset;
	ll ans = 0;
	while(a < b)
	{
		if(a & 1) ans += sum[a++];
		if((b & 1) == 0) ans += sum[b--];
		a >>= 1;
		b >>= 1;
	}
	if(a == b) ans += sum[a];
	return ans;
}

ll min(int p)
{
	int a = p + offset, b = offset * 2 - 1;
	vector<int> va, vb;
	while(a < b)
	{
		if(a & 1) va.push_back(a++);
		if((b & 1) == 0) vb.push_back(b--);
		a >>= 1;
		b >>= 1;
	}
	if(a == b) va.push_back(a);
	reverse(vb.begin(), vb.end());
	va.insert(va.end(), vb.begin(), vb.end());
	ll ans = inf, sm = 0;
	for(int v: va)
	{
		ans = min(ans, mn[v] + sm);
		sm += sum[v];
	}
	return ans + sump(p-1);
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<pair<int, int>> vec;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		insert(i, a[i]);
		while(!vec.empty() && vec.back().first <= a[i])
			vec.pop_back();
		vec.emplace_back(a[i], i);
	}
	reverse(vec.begin(), vec.end());
	vec.emplace_back(1e9+5, n);
	for(int i = 0; i < m; i++)
		scanf("%d", &tab[i].second);
	for(int i = 0; i < m; i++)
		scanf("%d", &tab[i].first);
	sort(tab, tab + m);
	int ans = 0;
	for(int i = 0; i < m; i++)
	{
		int p = tab[i].first;
		int b = tab[i].second;
		int pos = lower_bound(vec.begin(), vec.end(), make_pair(b, 0))->second;
		if(pos < n && min(pos) >= p)
		{
			insert(pos, -p);
			ans++;
		}
	}
	printf("%d\n", ans);
}