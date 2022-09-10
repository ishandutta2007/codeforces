#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PII pair <int, int>

const int N = 2e5 + 7;
const int T = 3 * N + 7;
const LL inf = 1e15 + 9LL;

struct node{
	LL in = 0LL;
	LL out = 0LL;
	node *left = nullptr, *right = nullptr;
	inline void act(){
		out = min(left -> out, right -> out) + in;
	}
};

int n, q;
int cnt = 0;

int odl[N];
int cur[N];
int pre[N];
int post[N];
int back[N];
int edge[2 * N];

node *root;
vector <PII> G[N];

node* newTree(int h){
	if(h == 0)
		return new node();
	
	node *ret = new node();
	ret -> left = newTree(h - 1);
	ret -> right = newTree(h - 1);
	return ret;
}

void add(node *cur, int from, int to, int val, int curS = 1, int curE = (1 << 18)){
	if(to < curS || curE < from)
		return;
	
	if(from <= curS && curE <= to){
		cur -> in = cur -> in + val;
		cur -> out = cur -> out + val;
		return;
	}
	
	int mid = (curS + curE) >> 1;
	add(cur -> left, from, to, val, curS, mid);
	add(cur -> right, from, to, val, mid + 1, curE);
	cur -> act();
}

void addV(node *cur, int place, int val, int curS = 1, int curE = (1 << 18)){
	if(place < curS || curE < place)
		return;
	
	if(curS == curE){
		cur -> out = cur -> out + val;
		return;
	}
	
	int mid = (curS + curE) >> 1;
	addV(cur -> left, place, val, curS, mid);
	addV(cur -> right, place, val, mid + 1, curE);
	cur -> act();
}

LL ask(node *cur, int place, int curS = 1, int curE = (1 << 18)){
	if(place < curS || curE < place)
		return 0LL;

	if(curS == curE)
		return cur -> in;

	int mid = (curS + curE) >> 1;
	return ask(cur -> left, place, curS, mid) + ask(cur -> right, place, mid + 1, curE) + cur -> in;
}

LL askM(node *cur, int from, int to, int curS = 1, int curE = (1 << 18)){
	if(to < curS || curE < from)
		return inf;
	
	if(from <= curS && curE <= to)
		return cur -> out;
	
	int mid = (curS + curE) >> 1;
	return min(askM(cur -> left, from, to, curS, mid), askM(cur -> right, from, to, mid + 1, curE)) + cur -> in;
}

void dfs(int u){
	pre[u] = ++cnt;
	for(PII v: G[u]){
		odl[v.st] = odl[u] + v.nd;
		dfs(v.st);
	}
	
	post[u] = cnt;
}

int main(){
	scanf("%d %d", &n, &q);
	for(int i = 1; i < n; ++i){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge[i] = b;
		G[a].pb({b, c});
		cur[b] = c;
	}
	
	for(int i = 1; i < n; ++i){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge[n + i - 1] = a;
		back[a] = c;
	}
	
	dfs(1);
	root = newTree(18);
	for(int i = 1; i < n; ++i)
		add(root, pre[edge[i]], post[edge[i]], cur[edge[i]]);
	for(int i = 1; i < n; ++i)
		addV(root, pre[edge[n + i - 1]], back[edge[n + i - 1]]);

	while(q--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a == 1){
			if(b < n){
				add(root, pre[edge[b]], post[edge[b]], c - cur[edge[b]]);
				cur[edge[b]] = c;
			}
			else{
				addV(root, pre[edge[b]], c - back[edge[b]]);
				back[edge[b]] = c;
			}
		}
		else{
			swap(b, c);
			if(pre[c] <= pre[b] && post[b] <= post[c])
				printf("%lld\n", ask(root, pre[b]) - ask(root, pre[c]));
			else
				printf("%lld\n", ask(root, pre[b]) + askM(root, pre[c], post[c]) - ask(root, pre[c]));
		}
	}

	return 0;
}