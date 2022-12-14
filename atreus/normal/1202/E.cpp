#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 3e5 + 10;

int sum[maxn], f[maxn], nex[maxn][27], child[maxn][27];
int dp[maxn], pnt[maxn], newint = 1, mark[maxn], leng[maxn];

int q[maxn];
void bfs(int src){
	int h = 0, t = 0;
	q[h++] = src, f[src] = src;
	for (int i = 0; i < 26; i++)
		nex[src][i] = src;
	while (h > t){
		int v = q[t++];
		sum[v] += sum[f[v]];
		for (int i = 0; i < 26; i++){
			if (child[v][i] != -1){
				f[child[v][i]] = nex[f[v]][i];
				nex[v][i] = child[v][i];
				q[h++] = child[v][i];
			}
			else{
				nex[v][i] = nex[f[v]][i];
			}
		}
	}	
}

void add(string &s, int now){
	int idx = 0;
	while (idx < s.size()){
		if (child[now][s[idx] - 'a'] == -1)
			child[now][s[idx] - 'a'] = newint ++;
		now = child[now][s[idx] - 'a'];
		idx ++;
	}
	sum[now] ++;
}

int root[maxn];

int main(){
	ios_base::sync_with_stdio (false);
	memset(child, -1, sizeof child);
	string t;
	cin >> t;
	int n;
	cin >> n;
	vector<int> roots;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		int len = s.size();
		if (!root[len]){
			leng[newint] = len;
			root[len] = newint;
			roots.push_back(newint ++);
		}
		add(s, root[len]);
	}
	for (auto it : roots)
		bfs(it);
	
	n = t.size();
	for (auto it : roots)
		pnt[it] = it;
	ll answer = 0;
	for (int i = 0; i < n; i++){
		for (auto it : roots){
			pnt[it] = nex[pnt[it]][(int)(t[i] - 'a')];
			dp[i] += sum[pnt[it]];
			if (i >= leng[it])
				answer += 1ll * sum[pnt[it]] * dp[i - leng[it]];
		}
	}
	cout << answer << endl;
}