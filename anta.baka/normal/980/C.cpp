#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<int> b(256, -1), gsz(256, 0);
	int gn = 0;
	for(int i = 0; i < n; i++) if(b[a[i]] == -1) {
		int l = a[i];
		while(a[i] - l + 1 < k && l && b[l - 1] == -1) l--;
		if(l && b[l - 1] != -1 && a[i] - l + 1 + gsz[b[l - 1]] <= k) {
			for(int j = l; j <= a[i]; j++) b[j] = b[l - 1];
			gsz[b[l - 1]] += a[i] - l + 1;
		} else {
			for(int j = l; j <= a[i]; j++) b[j] = gn;
			gsz[gn] = a[i] - l + 1;
			gn++;
		}
	}
	vector<int> lo(256, INF);
	for(int i = 0; i < 256; i++) if(b[i] != -1) lo[b[i]] = min(lo[b[i]], i);
	for(int i = 0; i < n; i++) cout << lo[b[a[i]]] << ' ';
}