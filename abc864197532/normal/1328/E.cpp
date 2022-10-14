#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second
#define endl '\n'
const int MAXN = 200087, LogN = 17;

vector <int> nums[MAXN];
int vertex[MAXN][LogN]; // vertex[i][j]= 2^j 
int in[MAXN], out[MAXN], t = 0, depth[MAXN];

void dfs(int n, int p) {
	in[n] = t++;
	vertex[n][0] = p;
	depth[n] = ~p ? depth[p] + 1 : 0;
	for (int i = 1; i < LogN; ++i) {
		int k = vertex[n][i-1];
		if (k == -1) break;
		vertex[n][i] = vertex[k][i-1];
	}
	for (int i : nums[n]) {
		if (i == p) continue;
		dfs(i, n);
	}
	out[n] = t++;
}

int lca(int a, int b) {
	if (in[a] <= in[b] and out[a] >= out[b]) return a;
	if (in[b] <= in[a] and out[b] >= out[a]) return b;
	for (int i = LogN - 1; i >= 0; --i) {
		int k = vertex[a][i];
		if (k == -1) continue;
		if (!(in[k] <= in[b] and out[k] >= out[b])) a = k;
	}
	return vertex[a][0];
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, u, v, q;
    cin >> n >> q;
    fop (i,0,n-1) {
        cin >> u >> v;
        u--; v--;
        nums[u].pb(v);
        nums[v].pb(u);
    }
    dfs(0, -1);
    while (q--) {
        int tmp;
        cin >> tmp;
        vector <int> input(tmp);
        fop (i,0,tmp) cin >> input[i], input[i]--;
        fop (i,0,tmp) {
            if (vertex[input[i]][0] != -1) input[i] = vertex[input[i]][0];
        }
        sort(input.begin(), input.end(), [](int i, int j) {return depth[i] > depth[j];});
        bool is = true;
        fop (i,1,tmp) {
            int k = lca(input[i], input[0]);
            if (k != input[i] and k != input[0]) is = false;
        }
        cout << (is ? "YES" : "NO") << endl;
    }
}