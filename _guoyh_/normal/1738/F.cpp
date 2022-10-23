# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1005;
int T, n;
int d[MAXN];
int a[MAXN];
bool flg[MAXN];
int p[MAXN];
int fdrt(int nw){
	if (p[nw] == nw) return nw;
	else return p[nw] = fdrt(p[nw]);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> d[i];
		for (int i = 1; i <= n; i++) a[i] = i;
		sort(a + 1, a + n + 1, [&](int u, int v){ return d[u] > d[v]; });
		for (int i = 1; i <= n; i++) p[i] = i;
		for (int i = 1; i <= n; i++) flg[i] = false;
		for (int i = 1; i <= n; i++){
			int nw = a[i];
			if (flg[nw]) continue;
			flg[nw] = true;
			for (int j = 1; j <= d[nw]; j++){
				cout << "? " << nw << '\n';
				cout.flush();
				int v;
				cin >> v;
				if (flg[v]){
					p[fdrt(nw)] = fdrt(v);
					break;
				} else {
					flg[v] = true;
					p[fdrt(v)] = fdrt(nw);
				}
			}
		}
		cout << "! ";
		for (int i = 1; i <= n; i++) cout << fdrt(i) << ' ';
		cout << '\n';
		cout.flush();
	}
	return 0;
}