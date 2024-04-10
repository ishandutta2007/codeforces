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
#define MAXN 200000
#define endl '\n'
 
vector <int> nums[MAXN], rnums[MAXN], out;
set <int> newnums[MAXN];
bool vis[MAXN];
int nscc = 0, scc[MAXN];
 
void rdfs(int n) {
	vis[n] = true;
	for (int i : rnums[n]) {
		if (!vis[i]) rdfs(i);
	}
	out.push_back(n);
}
 
void dfs(int n) {
	scc[n] = nscc;
	for (int i : nums[n]) {
		if (scc[i] == -1) dfs(i);
		else if (scc[i] != nscc) newnums[scc[i]].insert(nscc);
	}
}
 
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k,p,tmp;
	cin >> n >> k;
	int ans[n];
	fop (i,0,n) ans[i] = k - 1;
	cin >> p;
	p--;
	fop (i,1,n) {
		cin >> tmp;
		tmp--;
		nums[tmp].pb(p);
		rnums[p].pb(tmp);
		p = tmp;
	}
	cin >> p;
	p--;
	fop (i,1,n) {
		cin >> tmp;
		tmp--;
		nums[tmp].pb(p);
		rnums[p].pb(tmp);
		p = tmp;
	}
	fop (i,0,n) vis[i] = false, scc[i] = -1;
	fop (i,0,n) {
		if (!vis[i]) rdfs(i);
	}
	while (out.size()) {
		int kk = out.back(); out.pop_back();
		if (scc[kk] == -1) {
			dfs(kk);
			nscc++;
		}
	}
	if (nscc < k) {
	    cout << "NO" << endl;
	    return 0;
	}
	cout << "YES" << endl;
	fop (i,0,n) {
	    cout << char('a' + min(scc[i], k-1));
	}
	cout << endl;
}