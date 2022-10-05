#include <bits/stdc++.h>
 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
#define en "\n"
#define forn(i, j, n) for(int j = i; j <= n; ++j)
#define sortv(vv) sort(vv.begin(), vv.end())
#define sortm(vv, n) sort(vv + 1, vv + 1 + n);
#define int ll

using namespace std;                    
const ll maxn=8e5+12,inf=1e9,LOG=18,mod=998244353;

struct query
{
	int num;
	int ch;
	int type;
	int times;
};

query q[maxn];
int n, tree[maxn], ans[maxn], ti, ty, x;
map <int, int> ma;
vector <int> tim;

bool comp(query i, query j)
{
	return i.ch < j.ch || (i.ch == j.ch && i.num < j.num);
}

void upd(int v, int tl, int tr, int pos, int val)
{
	if(pos > tr || pos < tl)
	{
		return;
	}
	if(pos == tl && tr == tl)
	{
		tree[v] += val;
		return;
	}
	upd(v * 2, tl, (tl + tr) / 2, pos, val);
	upd(v * 2 + 1, (tl + tr) / 2  + 1, tr, pos, val);
	tree[v] = tree[v * 2] + tree[v * 2 + 1];
}
ll get_sum(int v, int tl, int tr, int l,int r)
{
	if(l <= tl && tr <= r)
	{
		return tree[v];
	}
	if(l > tr || r < tl)
	{
		return 0;
	}
	return get_sum(v * 2, tl, (tl + tr) / 2, l, r) + get_sum(v * 2 + 1, (tl + tr) / 2 + 1, tr, l, r);
}
main()
{
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		cin >> ty >> ti >> x;
		q[i].num = i;
		q[i].times = ti;
		q[i].type = ty;
		q[i].ch = x;
		tim.push_back(ti);
	}
	sort(q + 1, q + 1 + n, comp);
	sortv(tim);
	forn(0, i, tim.size() - 1)
	{
		ma[tim[i]] = i + 1;
	}
	vector <pair <int, int> >  kol;
	for(int i = 1; i <= n; )
	{
		int j;
		for(j = i; j <= n && q[j].ch == q[i].ch; ++j)
		{
			if(q[j].type == 1)
			{
				upd(1, 1, tim.size(), ma[q[j].times], 1);
			}
			else
			if(q[j].type == 2)
			{
				upd(1, 1, tim.size(), ma[q[j].times], -1);
			}
			else
			{
				kol.pb(mp(q[j].num, get_sum(1, 1, tim.size(), 1, ma[q[j].times])));
			}
		}
		int uk = j;
		j--;
		for(; j >= i; --j)
		{
			if(q[j].type == 1)
			{
				upd(1, 1, tim.size(), ma[q[j].times], -1);
			}
			else
			if(q[j].type == 2)
			{
				upd(1, 1, tim.size(), ma[q[j].times], 1);
			}
		}
		i = uk;
	}
	sortv(kol);
	forn(0, i, kol.size() - 1)
	{
		cout << kol[i].s << " ";
	}
}