#include <bits/stdc++.h>

using namespace std;

typedef long double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 5e5 + 7;
const int T = 1 << 19;

const int M = 1e7 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
int in[N];
int root[N];
int length[N];

int cnt;
int val[M];
int Left[M], Right[M];

int ask(int cur, int v, int s, int e){
	if(s == e)
		return val[cur];
	
	int mid = (s + e) >> 1;
	if(v <= mid){
		if(Left[cur] > 0)	return ask(Left[cur], v, s, mid);
		return 0;
	}
	else{
		if(Right[cur] > 0)	return ask(Right[cur], v, mid + 1, e);
		return 0;
	}
}

int copy(int cur){
	++cnt;
	val[cnt] = val[cur];
	Left[cnt] = Left[cur];
	Right[cnt] = Right[cur];
	return cnt;
}

int add(int cur, int p, int v, int s, int e){
	int n_id = copy(cur);
	if(s == e){
		val[n_id] = v;
		return n_id;
	}
	
	int mid = (s + e) >> 1;
	if(p <= mid)
		Left[n_id] = add(Left[cur], p, v, s, mid);
	else
		Right[n_id] = add(Right[cur], p, v, mid + 1, e);
	return n_id;
}

void update(int v, int p){
	length[v] = length[p + 1] + 1;
	int t = length[p + 1] == 0 ? root[n] : root[p + 1];
	
	if(p + 1 <= n)
		root[v] = add(t, in[p + 1], p + 1, 1, T);
	else
		root[v] = root[n];
}

void solve(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i]);
		root[i] = length[i] = 0;
	}
	
	length[n + 1] = 0;
	for(int i = 0; i <= cnt; ++i)
		val[i] = Left[i] = Right[i] = 0;
	cnt = 1;
	
	root[n] = 1;
	for(int i = n - 1; i >= 1; --i){
		if(in[i + 1] == in[i]){
			update(i, i + 1);
			continue;
		}
		
		if(length[i + 1] == 0)
			continue;
		
		int p = ask(root[i + 1], in[i], 1, T);
		if(p == 0)	continue;
		update(i, p);
	}
	
	LL ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += length[i];
	printf("%lld\n", ans);
}

int main(){
	int quest;
	scanf("%d", &quest);
	
	while(quest--)
		solve();
	return 0;
}