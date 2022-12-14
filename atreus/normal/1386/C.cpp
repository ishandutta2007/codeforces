#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int e1[maxn], e2[maxn], opt[maxn];
int par[maxn], h[maxn];
stack<bool> oddcycle;
stack<pair<int,int>> event;

int get_par(int v){
	return par[v] < 0 ? v : get_par(par[v]);
}

int get_h(int v){
	return par[v] < 0 ? 0 : h[v]^get_h(par[v]);
}

void undo(){
	if (event.empty())
		return;
	oddcycle.pop();
	int v = event.top().first, p = event.top().second;
	event.pop();
	if (v == -1)
		return;
	par[par[v]] -= p;
	par[v] = p;
	h[v] = 0;
}

void add(int v, int u){
	int vp = get_par(v), up = get_par(u);
	int vh = get_h(v), uh = get_h(u);
	if (vp == up){
		if (vh == uh)
			oddcycle.push(1);
		else
			oddcycle.push(oddcycle.top());
		event.push({-1,-1});
		return;
	}
	if (par[vp] < par[up]){
		swap(v, u);
		swap(vp, up);
		swap(vh, uh);
	}
	oddcycle.push(oddcycle.top());
	event.push({vp, par[vp]});
	par[up] += par[vp];
	par[vp] = up;
	h[vp] = (vh^uh^1);
}

void calc(int l, int r, int lo, int hi){
	if (l >= r)
		return;
	int m = (l + r) >> 1;
	for (int i = l; i < m; i++)
		add(e1[i], e2[i]);
	for (int i = hi; i >= max(m,lo)-1; i--){
		if (oddcycle.top() == true){
			opt[m] = i;
			for (int j = i+1; j <= hi; j++)
				undo();
			break;
		}
		if (i == max(m,lo)-1)
			break;
		add(e1[i], e2[i]);
	}
	if (opt[m] == 0){
		for (int i = max(m,lo); i <= hi; i++)
			undo();
		for (int i = m-1; i >= l; i--)
			undo();
		return;
	}
	add(e1[m], e2[m]);
	calc(m+1, r, opt[m], hi);
	for (int i = m; i >= l; i--)
		undo();
	for (int i = hi; i > opt[m]; i--)
		add(e1[i], e2[i]);
	calc(l, m, lo, opt[m]);
	for (int i = opt[m]+1; i <= hi; i++)
		undo();
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++)
		scanf("%d%d", &e1[i], &e2[i]);
	oddcycle.push(0);
	memset(par, -1, sizeof par);
	calc(1, m+1, 1, m);
	while (q --){
		int l, r;
		scanf("%d%d", &l, &r);
		if (r <= opt[l])
			printf("YES\n");
		else
			printf("NO\n");
	}
}