#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int SQRT = 330;

int a[maxn];
ll lazy[maxn], cnt[maxn], lf[maxn];

int getA(int x){
	return max(a[x]-lazy[x/SQRT], 0ll);
}

int main(){
	ios_base::sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i < n; i++){
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < n; i++){
		if (i/SQRT == a[i]/SQRT){
			lf[i] = lf[a[i]];
			cnt[i/SQRT]++;
		}
		else
			lf[i] = i;
	}
	while (q--){
		int t;
		cin >> t;
		if (t == 1){
			int l, r, x;
			cin >> l >> r >> x;
			l--;
			while (l < r or (l < n and l % SQRT != 0)){
				if (l%SQRT == 0 and l+SQRT <= r and cnt[l/SQRT] == 0){
					lazy[l/SQRT] += x;
					l += SQRT;
				}
				else{
					if (l < r){
						int wasBefore = (l/SQRT == getA(l)/SQRT);	
						a[l] = max(a[l]-x,0);
						cnt[l/SQRT] += (l/SQRT == getA(l)/SQRT) - wasBefore;
					}
					if (l/SQRT != getA(l)/SQRT)
						lf[l] = l;
					else
						lf[l] = lf[getA(l)];
					l++;
				}
			}
		}
		else{
			int v, u;
			cin >> v >> u;
			v--, u--;
			while (v != u){
				if (v < u)
					swap(v,u);
				if (lf[v] == lf[u]){
					v = getA(v);
					continue;
				}
				if (v/SQRT != u/SQRT)
					v = getA(lf[v]);
				else{
					v = getA(lf[v]);
					u = getA(lf[u]);
				}
			}
			cout << ++v << '\n';
		}
	}
}