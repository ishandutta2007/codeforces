#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5, lgMAXN = 18;

int N, M;
int u[MAXN], v[MAXN], w[MAXN];
bool mst[MAXN];

void MST()
{
	vector<int> V(M); iota(V.begin(), V.end(), 0);
	sort(V.begin(), V.end(), [&](int a, int b){
		return w[a] < w[b];
	});
	vector<int> ufd(N); iota(ufd.begin(), ufd.end(), 0);
	function<int(int)> Find = [&](int a)
	{
		if(a == ufd[a]) return a;
		return ufd[a] = Find(ufd[a]);
	};
	auto Union = [&](int a, int b){
		ufd[Find(a)] = Find(b);
	};

	for(auto e: V)
		if(Find(u[e]) != Find(v[e]))
		{
			mst[e] = true;
			Union(u[e], v[e]);
		}
}

vector<pair<int, int> > conn[MAXN];
int H[MAXN];
int anc[lgMAXN][MAXN];
int maxv[lgMAXN][MAXN];


int getv(int a, int b)
{
	if(H[a] < H[b]) swap(a, b);

	int diff = H[a]-H[b];
	int ans = 0;
	for(int i=lgMAXN-1; i>=0; --i)
		if(diff & (1<<i))
		{
			ans = max(maxv[i][a], ans);
			a = anc[i][a];
		}

	if(a == b) return ans;
	for(int i=lgMAXN-1; i>=0; --i)
	{
		if(anc[i][a] != anc[i][b])
		{
			ans = max({maxv[i][a], maxv[i][b], ans});
			a = anc[i][a], b = anc[i][b];
		}
	}

	return max({ans, maxv[0][a], maxv[0][b]});
}


void dfs(int a, int h = 0, int p = -1)
{
	for(auto [x, w]: conn[a]) if(x != p)
	{
		anc[0][x] = a, maxv[0][x] = w, H[x] = h+1;
		dfs(x, h+1, a);
	}
}



long long LCA()
{
	long long a = 0;
	for(int i=0; i<M; ++i) if(mst[i])
	{
		conn[u[i]].emplace_back(v[i], w[i]);
		conn[v[i]].emplace_back(u[i], w[i]);
		a += w[i];
	}
	dfs(0);
	for(int i=1; i<lgMAXN; ++i)
		for(int j=0; j<MAXN; ++j)
		{
			anc[i][j] = anc[i-1][anc[i-1][j]];
			maxv[i][j] = max(maxv[i-1][j], maxv[i-1][anc[i-1][j]]);
		}
	return a;
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i<M; ++i)
	{
		scanf("%d%d%d", u+i, v+i, w+i);
		--u[i]; --v[i];
	}

	MST();
	long long ans = LCA();
	for(int i=0; i<M; ++i)
		printf("%lld\n", ans + w[i] - getv(u[i], v[i]));

}