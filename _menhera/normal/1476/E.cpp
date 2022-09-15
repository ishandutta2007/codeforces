#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
string pat[1+MAXN];
vector<int> conn[1+MAXN];
int indeg[1+MAXN];
map<string, int> patM;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int N, M, K; cin >> N >> M >> K;
	for(int i=1; i<=N; ++i) cin >> pat[i], patM[pat[i]] = i;
	for(int i=0; i<M; ++i)
	{
		string s; int mt; cin >> s >> mt;
		vector<int> idx;
		for(int j=0; j<(1<<K); ++j)
		{
			string mat = s;
			for(int k=0; k<K; ++k)
				if(j&(1<<k))
					mat[k] = '_';
			if(patM.count(mat)) idx.push_back(patM[mat]);
		}
		bool check = false;
		for(auto v: idx)
		{
			if(mt == v) check = true;
			else
			{
				conn[mt].push_back(v);
				// printf("%d %d\n", mt, v);
				indeg[v]++;
			}
		}
		if(!check)
		{
			puts("NO"); return 0;
		}
	}
	vector<int> ans;
	queue<int> Q;
	for(int i=1; i<=N; ++i) if(indeg[i] == 0) Q.push(i);
	while(!Q.empty())
	{
		int x = Q.front(); Q.pop(); ans.push_back(x);
		for(auto u: conn[x])
			if(--indeg[u] == 0)
				Q.push(u);
	}
	if((int)ans.size() == N)
	{
		puts("YES");
		for(auto x: ans) printf("%d ", x);
		puts("");
	}
	else puts("NO");
}