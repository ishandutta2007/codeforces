#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
const int N = 1e5 + 10;
const int inf = 1e9;
int n, k;
string s[N];
int cnt = 2;
int child[26], nex[maxn][26], f[maxn], a[maxn];
vector<int> t[maxn];
bool light[N];
int Time = 1, st[maxn], ft[maxn];
int fen[maxn];

int get(int idx){
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret += fen[idx];
	return ret;
}

void add(int idx, int val){
	for (; idx < maxn; idx += idx & -idx)
		fen[idx] += val;
}

void add(int l, int r, int val){
	add(r, -val);
	add(l, val);
}

void dfs(int v){
	st[v] = Time ++;
	for (auto u : t[v])
		dfs(u);
	ft[v] = Time;
}

void build_ahu(){
	for (int i = 0; i < k; i++){
		int now = 1;
		for (int j = 0; j < s[i].size(); j++){
			int k = (int)(s[i][j] - 'a');
			if (nex[now][k] == 0)
				nex[now][k] = cnt ++;
			now = nex[now][k];
		}
		a[i] = now;
	}
	f[1] = 1;
	queue<int> Q;
	Q.push(1);
	while (!Q.empty()){
		int v = Q.front();
		Q.pop();
		for (int i = 0; i < 26; i++)
			child[i] = nex[v][i];
		if (v == 1)
			for (int i = 0; i < 26; i++)
				nex[1][i] = 1;
		for (int i = 0; i < 26; i++){
			if (child[i] == 0){
				nex[v][i] = nex[f[v]][i];
				continue;
			}
			f[child[i]] = nex[f[v]][i];
			nex[v][i] = child[i];
			Q.push(child[i]);
		}
	}
	// build ahu's tree
	for (int v = 2; v < cnt; v++)
		t[f[v]].push_back(v);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < k; i++)
		cin >> s[i];
	build_ahu();
	dfs(1);
	// add all
	for (int i = 0; i < k; i++){
		add(st[a[i]], ft[a[i]], +1);
		light[i] = 1; // On
	}
	for (int i = 0; i < n; i++){
		string t;
		cin >> t;
		if (t[0] == '?'){
			t = t.substr(1);
			ll answer = 0;
			int now = 1;
			for (int j = 0; j < t.size(); j++){
				int k = (int)(t[j] - 'a');
				now = nex[now][k];
				answer += get(st[now]);
			}
			cout << answer << '\n';
		}
		else{
			int k = stoi(t.substr(1));
			k --;
			if (t[0] == '-' and light[k] == 1){
				add(st[a[k]], ft[a[k]], -1);
				light[k] = 0;
			}
			if (t[0] == '+' and light[k] == 0){
				add(st[a[k]], ft[a[k]], +1);
				light[k] = 1;
			}
		}
	}
}