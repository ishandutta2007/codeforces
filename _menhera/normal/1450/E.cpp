#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200;
const int MAXM = 2000;
const int INF = 0x3f3f3f3f;
int N, M;
int u[MAXM], v[MAXM], b[MAXM];

int d[MAXN][MAXN];

int ci(const vector<int>& ans)
{
	for(int i=0; i<M; ++i)
	{
		int delta = ans[u[i]] - ans[v[i]];
		if(b[i] && delta != -1) return -1;
		if(delta != -1 && delta != 1) return -1;
	}
	return *max_element(ans.begin(), ans.end()) - *min_element(ans.begin(), ans.end());
}
vector<int> calc(int idx)
{
	auto ans = vector<int>(d[idx]+0, d[idx]+N);
	int me = *min_element(ans.begin(), ans.end());
	for(auto& x: ans) x -= me;
	return ans;
}
void init()
{
	for(int i=0; i<N; ++i)
		d[i][i] = 0;

	for(int k=0; k<N; ++k)
		for(int i=0; i<N; ++i)
			for(int j=0; j<N; ++j)
				d[i][j] = min(d[i][k]+d[k][j], d[i][j]);

	for(int i=0; i<N; ++i) if(d[i][i] != 0)
	{
		puts("NO");
		exit(0);
	}
}
int main()
{
	scanf("%d%d", &N, &M);
	memset(d, 0x3f, sizeof d);
	for(int i=0; i<M; ++i)
	{
		scanf("%d%d%d", u+i, v+i, b+i);
		--u[i]; --v[i];
		d[u[i]][v[i]] = 1;
		d[v[i]][u[i]] = b[i]?-1:1;
	}

	init();
	int ineq = -1;
	vector<int> ans;
	for(int i=0; i<N; ++i)
	{
		vector<int> eval = calc(i);
		int x = ci(eval);
		if(ineq < x)
		{
			ineq = x;
			ans = eval;
		}
	}
	if(ineq == -1) puts("NO");
	else
	{
		puts("YES");
		printf("%d\n", ineq);
		for(auto x: ans)
			printf("%d ", x);
		puts("");
	}
}