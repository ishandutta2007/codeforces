#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e3 + 10;

int x, n, m, w[MAXN], d[MAXN];
bool mark[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> x >> n >> m;
	while (n--){
		int l, r; cin >> l >> r;
		for (; l < r; l++)
			mark[l] = true;
	}
	memset(w, 63, sizeof(w));
	while (m--){
		int z, p; cin >> z >> p;
		w[z] = min(w[z], p);
	}
	memset(d, 63, sizeof(d));
	d[0] = 0;
	for (int i = 1; i <= x; i++)
		if (!mark[i-1])
			d[i] = d[i-1];
		else{
			for (int j = i-1; ~j; j--)
				if (w[j] < 1e6)
					d[i] = min(d[i], d[j] + (i-j)*w[j]);
		}

	if (d[x] > 1e9)
		d[x] = -1;
	cout << d[x] << "\n";
}