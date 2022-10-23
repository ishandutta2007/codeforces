# include <bits/stdc++.h>
using namespace std;
const int MAXN = 100051;
int T, n, k;
int a[MAXN];
vector<int> adj;
int qry(int x){
	for (int i = 1; i <= n; i++) if ((i >> x) & 1) adj.push_back(i);
	if (adj.size() == 0) return false;
	cout << "? ";
	cout << adj.size() << ' ';
	for (int i : adj) cout << i << ' ';
	cout << '\n';
	adj.clear();
	cout.flush();
	string res;
	cin >> res;
	return res[0] == 'Y';
}
int fa[MAXN];
bool f[MAXN];
bool res[MAXN];
bool chk(){
	int ans = 0;
	for (int i = 0; i <= 16; i++){
		res[i] = res[fa[i]] ^ f[i];
		if (res[i]) ans |= (1 << i);
	}
	if (ans <= 0 || ans > n) return false;
	cout << "! " << ans << '\n';
	cout.flush();
	string res;
	cin >> res;
	return res[1] == ')';
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	int asz = 0;
	int nq = 0;
	a[++asz] = qry(nq);
	for (int i = 1; i <= 16; i++){
		a[++asz] = qry(i);
		a[++asz] = qry(i);
		a[++asz] = qry(nq);
		if (a[asz - 2] == a[asz - 1]){
			fa[i] = 20;
			f[i] = a[asz - 1];
		} else if (a[asz] == a[asz - 3]){
			fa[nq] = 20;
			f[nq] = a[asz];
			nq = i;
			a[++asz] = qry(nq);
		} else {
			fa[i] = nq;
			f[i] = a[asz] ^ a[asz - 1] ^ 1;
		}
	}
	fa[nq] = 20;
	f[nq] = 0;
	if (!chk()){
		f[nq] = 1;
		chk();
	}
	return 0;
}