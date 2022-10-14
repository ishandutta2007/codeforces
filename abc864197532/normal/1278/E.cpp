#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,int>
#define X first
#define Y second
#define MAXN 500000

vector <int> nums[MAXN];
int l[MAXN], r[MAXN], t = 0;

int dfs(int n, int pa) {
	for (int i : nums[n]) {
		if (i == pa) continue;
		l[i] = ++t;
	}
	r[n] = ++t;
	FOP (i,nums[n].size(),0) {
		if (nums[n][i] == pa) continue;
		dfs(nums[n][i], n);
	}
} 

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n, a, b;
	cin >> n;
	fop (i,0,n-1) {
		cin >> a >> b;
		a--, b--;
		nums[a].pb(b);
		nums[b].pb(a);
	}
	l[0] = ++t;
	dfs(0, -1);
	fop (i,0,n) cout << l[i] << ' ' << r[i] << endl;
}