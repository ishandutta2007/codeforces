#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 4e5 + 10;

int a[maxn], pos[maxn], x[maxn], type[maxn], b[maxn];
bool mark[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++){
		cin >> type[i];
		if (type[i] == 1)
			cin >> pos[i] >> x[i];
		else
			cin >> x[i];
	}
	int mx = 0;
	for (int i = q; i >= 1; i--){
		if (type[i] == 2){
			mx = max(mx, x[i]);
			continue;
		}
		if (mark[pos[i]])
			continue;
		mark[pos[i]] = 1;
		b[pos[i]] = max(x[i], mx);
	}
	for (int i = 1; i <= n; i++)
		if (mark[i] == 0)
			b[i] = max(mx, a[i]);
	for (int i = 1; i <= n; i++)
		cout << b[i] << " \n"[i == n];
}