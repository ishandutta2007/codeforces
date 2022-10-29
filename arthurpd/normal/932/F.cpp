#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool Q;
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const {
        return Q ? p < o.p : k < o.k;
    }
};
struct LineContainer : multiset<Line> {
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b){
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        Q = 1; auto l = *lower_bound({0,0,x}); Q = 0;
        return l.k * x + l.m;
    }
};


int n;
ll a[112345];
ll b[112345];
vector<int> graph[112345];
ll tab[112345];


// dp[x] = max_{l(k) <= k < x}(dp[k] + a[x] * b[k])

void dfs(int u, int p, LineContainer **parent_hull)
{
	LineContainer *hull = new LineContainer;
	if (u != 1 && graph[u].size() == 1)
	{
		tab[u] = 0;
	}
	else
	{
		for (int v : graph[u])
			if (v != p)
				dfs(v, u, &hull);
		
		tab[u] = hull->query(a[u]);
	}

	hull->add(b[u], tab[u]);

	if (parent_hull != NULL)
	{
		if (*parent_hull == NULL)
			*parent_hull = hull;
		else 
		{
			if (hull->size() > (*parent_hull)->size())
				swap(hull, *parent_hull);
			
			for (Line l : *hull)
				(*parent_hull)->add(l.k, l.m);				
		}
	}
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];

	for (int i = 1; i <= n; i++)
	{
		a[i] *= -1;
	}
		
	int u, v;
	for (int i = 0; i < n-1; i++)
	{
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	dfs(1, 1, NULL);
	
	cout << -1 * tab[1];
	for (int i = 2; i <= n; i++)
		cout << " " << -1 * tab[i];
	printf("\n");
}