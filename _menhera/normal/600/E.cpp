#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int N;
vector<int> conn[MAXN];
int c[MAXN];
long long ans[MAXN];

struct AM
{
	map<int, int>* M;
	int maxv; long long sumv;
	AM(int color): M(nullptr), maxv(1), sumv(color)
	{
		M = new map<int, int>();
		(*M)[color] = 1;
	}

	void dest(){ delete M; }

	// b is invalidated
	void merge(AM b)
	{
		if(M->size() < b.M->size())
			swap(*this, b);

		for(auto [k, v]: *b.M)
		{
			int val = ((*M)[k] += v);
			if(maxv < val) maxv = val, sumv = 0;
			if(maxv == val) sumv += k;
		}
		b.dest();
	}
};

AM solve(int a, int p = -1)
{
	AM X(c[a]);
	for(auto x: conn[a])
		if( x != p )
			X.merge(solve(x, a));
	ans[a] = X.sumv;
	return X;
}

int main()
{
	cin >> N;
	for(int i=0; i<N; ++i) cin >> c[i];
	for(int i=0; i<N-1; ++i)
	{
		int u, v; cin >> u >> v;
		--u; --v;
		conn[u].push_back(v);
		conn[v].push_back(u);
	}
	solve(0).dest();
	for(int i=0; i<N; ++i) cout << ans[i] << " ";
	cout << endl;
	return 0;
}