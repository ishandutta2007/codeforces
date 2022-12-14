// Ahuuuuuuuuuuuuuu Ahuuuuuuuuuuuuu
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 200 + 10;
const ll inf = 1e18;
int newint = 1;

struct matrix{
	ll dis[maxn][maxn];
	matrix(){
		for (int i = 0; i < maxn; i++)
			for (int j = 0; j < maxn; j++)
				dis[i][j] = -inf;
	}
	matrix mul(const matrix &other){
		matrix ret;
		for (int i = 0; i < maxn; i++)
			for (int j = 0; j < maxn; j++)
				for (int k = 0; k < maxn; k++)
					ret.dis[j][k] = max(ret.dis[j][k], dis[j][i] + other.dis[i][k]);
		return ret;
	}
};

matrix base;

matrix power(const matrix &a, ll b){
	if (b == 1)
		return a;
	matrix ret = power(a, b / 2);
	ret = ret.mul(ret);
	if (b & 1)
		ret = ret.mul(a);
	return ret;
}

int sum[maxn], f[maxn], nex[maxn][27], child[maxn][27];

int q[maxn];
void bfs(){
	int h = 0, t = 0;
	q[h++] = 0, f[0] = 0;
	while (h > t){
		int v = q[t++];
		sum[v] += sum[f[v]];
//		cout << v << " my f is : " << f[v] << endl;
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

void add(string &s, int &cost){
	int now = 0, idx = 0;
	while (idx < s.size()){
		if (child[now][s[idx] - 'a'] == -1){
//			cerr << "Tri edge : " << now << " ---" << s[idx] << "--> " << newint << endl;
			child[now][s[idx] - 'a'] = newint ++;
		}
		now = child[now][s[idx] - 'a'];
		idx ++;
	}
	sum[now] += cost;
}

int co[maxn];
int main(){
	ios_base::sync_with_stdio(false);
	ll n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		cin >> co[i];
	memset(child, -1, sizeof child);
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		add(s, co[i]);
	}
	bfs();
	for (int v = 0; v < newint; v++){
		for (int i = 0; i < 26; i++){
			base.dis[v][nex[v][i]] = sum[nex[v][i]];
		}
	}
	matrix q = power(base, l);
	ll answer = 0;
	for (int i = 0; i < newint; i++)
		answer = max(answer, q.dis[0][i]);
	cout << answer << endl; 
}