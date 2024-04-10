#include <bits/stdc++.h>

using namespace std;

const int VMAX = 300, EMAX = 600, MOD = 1000000007;

struct Edge
{
	int y;
	int next;
};

int N, M;
int cnt, ans;
map<int, int> idx;

int V[VMAX], weight[VMAX], eid;
bool visit[VMAX];
Edge E[EMAX];

void insert(int x, int y){
	E[++eid] = (Edge){y, V[x]};
	V[x] = eid;
}

void add(int x){
	if(!x)
		return;
	if(idx.find(x) == idx.end())
	{
		idx[x] = ++cnt;
		add(x>>1);
	}
}

long long calc(int x){
	long long l, r, res = 0;
	l = r = x;
	while(l <= N)
	{
		res += min((long long)N, r) - l + 1;
		l <<= 1;
		r = (r<<1) + 1;
	}
	return res;
}

long long sqr(int x){
	return (long long)x * x % MOD;
}

void DFS(int s, int x){
	int e;
	visit[x] = true;
	ans = (ans + (long long)weight[s] * weight[x]) % MOD;
	for(e = V[x];e;e = E[e].next)
	{
		if(!visit[E[e].y])
			DFS(s, E[e].y);
	}
	visit[x] = false;
}

int main(){
	int i, x, y, id;
	map<int, int>::iterator it;
	cin>>N>>M;
	add(1);
	for(i = 0;i < M;i += 1){
		cin>>x>>y;
		add(x);
		add(y);
		insert(idx[x], idx[y]);
		insert(idx[y], idx[x]);
	}
	for(it = idx.begin();it != idx.end();it++){
		x = it->first;
		id = it->second;
		if(x > 1){
			insert(id, idx[x>>1]);
			insert(idx[x>>1], id);
		}
		weight[id] = 1;
		if(idx.find(x<<1) == idx.end())
			weight[id] += calc(x<<1);
		if(idx.find((x<<1) + 1) == idx.end())
			weight[id] += calc((x<<1) + 1);
	}
	for(i = 1;i <= cnt;i += 1)
		DFS(i, i);
	cout<<ans<<endl;
	exit(0);
}