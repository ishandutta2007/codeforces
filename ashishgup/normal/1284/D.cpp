#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;


map<int, int> active;

void init()
{
	active.clear();
	active[-1] = -1;
	active[2e9] = 2e9;
}

void add(int L, int R) //Always remove [L, R] before adding
{
	active[L] = R;
}

int remove(int L, int R)
{
	int removed=0;
	auto it = active.lower_bound(L);
	it--;
	if(it->second>=L)
	{
		active[L] = it->second;
		it->second = L-1;
	}
	it++;
	while(it->first <= R)
	{
		if(it->second > R)
		{
			removed+=R + 1 - it->first;
			active[R+1] = it->second;
		}
		else
			removed+= it->second - it->first + 1;
		auto it2=it;
		it++;
		active.erase(it2);
	}
	return removed;
}


struct data
{
	int l1, r1, l2, r2;
};

bool comp(data &d1, data &d2)
{
	return make_pair(d1.l1, d1.r1) < make_pair(d2.l1, d2.r1);
}

int n;
data a[N];

void work()
{
	sort(a + 1, a + n + 1, comp);
	map<int, vector<pair<int, pair<int, int> > > > event;
	for(int i = 1; i <= n; i++)
	{
		pair<int, pair<int, int> > p = {-1, {a[i].l2, a[i].r2}};
		event[a[i].r1 + 1].push_back(p);
		p.first = 1;
		event[a[i].l1].push_back(p);
	}
	init();
	for(auto &it:event)
	{
		for(auto &i:it.second)
		{
			if(i.first == -1)
			{
				int l = i.second.first;
				int r = i.second.second;
				remove(l, r);
				add(l, r);
			}
		}
		for(auto &i:it.second)
		{
			if(i.first == +1)
			{
				int l = i.second.first;
				int r = i.second.second;
				int x = remove(l, r);
				if(x > 0)
				{
					cout << "NO";
					exit(0);	
				}
			}
		}
	}
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].l1 >> a[i].r1 >> a[i].l2 >> a[i].r2;
	work();
	for(int i = 1; i <= n; i++)
	{
		swap(a[i].l1, a[i].l2);
		swap(a[i].r1, a[i].r2);
	}
	work();
	cout << "YES";
	return 0;
}