/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 3e5 + 10;

int answer, num;
int a[maxn], c[maxn], ch[maxn];
int childs[3 * maxn][27], sz[3 * maxn], mark[3 * maxn], cnt[3 * maxn];
vector<int> t[maxn];

vector<int> freelist;
void get_freedom(int x){
	freelist.push_back(x);
}

int nonnecessary;
int newint(){
	if (freelist.empty()){
		freelist.push_back(nonnecessary++);
		cout << "Never " << endl;
		exit(0);
	}
	int x = freelist.back();
	freelist.pop_back();
	sz[x] = 0, mark[x] = 0, cnt[x] = 0;
	for (int i = 0; i < 26; i++)
		childs[x][i] = -1;
	return x;
}

void DFS(int fi, int se){
	sz[se] = 1;
	mark[se] |= mark[fi];
	cnt[se] = mark[se];

	for (int i = 0; i < 26; i++){
		if (childs[fi][i] != -1){
			if (childs[se][i] == -1)
				childs[se][i] = childs[fi][i];
			else
				DFS(childs[fi][i], childs[se][i]);
		}
		if (childs[se][i] != -1){
			sz[se] += sz[childs[se][i]];
			cnt[se] += cnt[childs[se][i]];
		}
	}
	get_freedom(fi);
}

int merge(int fi, int se){
	if (sz[fi] > sz[se])
		swap(fi, se);
	DFS(fi, se);
	return se;
}

int dfs(int v, int par = -1){
	int root = newint();
	int mychild = newint();

	sz[mychild] = 1;
	mark[mychild] = 1;
	cnt[mychild] = 1;
	for (auto u : t[v]){
		if (u == par)
			continue;
		int now = dfs(u, v);
		mychild = merge(mychild, now);
	}
	childs[root][ch[v]] = mychild;	
	sz[root] = sz[mychild] + 1;
	mark[root] = 0;
	cnt[root] = cnt[mychild];

	if (answer < a[v] + cnt[root]){
		answer = a[v] + cnt[root];
		num = 1;
	}
	else if (answer == a[v] + cnt[root])
		num ++;
	
	return root;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int v = 1; v <= n; v++)
		cin >> a[v];
	string tmp;
	cin >> tmp;
	for (int v = 1; v <= n; v++)
		ch[v] = int(tmp[v - 1] - 'a');
	for (int e = 1; e <= n - 1; e++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	nonnecessary = 3 * n + 1;
	for (int i = 1; i <= 3 * n; i++)
		freelist.push_back(i);
	dfs(1);
	cout << answer << '\n' << num << '\n';
}