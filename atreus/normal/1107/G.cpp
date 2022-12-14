/**
 *    author:  Atrues
 *    created: 26.01.2019
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll inf = 1e18;
const int maxn = 3e5 + 10;
ll seg[4 * maxn][2], lazy[4 * maxn][2];

void propagate(int, int, int, int);

ll get(int id, int L, int R, int idx, int w){
	if (L + 1 == R)
		return seg[id][w];
	propagate(id, L, R, w);
	int mid = (L + R) >> 1;
	if (idx < mid)
		return get(2 * id + 0, L, mid, idx, w);
	else	
		return get(2 * id + 1, mid, R, idx, w);
}

void change(int id, int L, int R, int l, int r, ll val, int w){
	if (L == l and R == r){
		seg[id][w] += val;
		lazy[id][w] += val;
		return;
	}
	propagate(id, L, R, w);
	int mid = (L + R) >> 1;
	if (l < mid)
		change(2 * id + 0, L, mid, l, min(mid, r), val, w);
	if (mid < r)
		change(2 * id + 1, mid, R, max(l, mid), r, val, w);
	seg[id][w] = max(seg[2 * id + 0][w], seg[2 * id + 1][w]);
}

void propagate(int id, int L, int R, int w){
	if (lazy[id][w] == 0)
		return;
	int mid = (L + R) >> 1;
	change(2 * id + 0, L, mid, L, mid, lazy[id][w], w);
	change(2 * id + 1, mid, R, mid, R, lazy[id][w], w);
	lazy[id][w] = 0;
}

ll d[maxn], c[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, a;
	cin >> n >> a;
	for (int i = 1; i <= n; i++)
		cin >> d[i] >> c[i];
	ll answer = 0;
	for (int i = 1; i <= n; i++){
		change(1, 1, n + 1, 1, i + 1, a - c[i], 1);
		if (i > 1){
			ll x = d[i] - d[i - 1];
			x *= -x;
			int idx = i - 1;
			int lo = 0, hi = idx;
			ll k = get(1, 1, n + 1, idx, 0);
			if (k > x){
				while (true){
					k = get(1, 1, n + 1, idx, 0);
					while (hi - lo > 1){
						int mid = (hi + lo) >> 1;
						if (get(1, 1, n + 1, mid, 0) == k)
							hi = mid;
						else
							lo = mid;
					}
					if (lo == 0){
						change(1, 1, n + 1, hi, idx + 1, x - k, 0);
						change(1, 1, n + 1, hi, idx + 1, x - k, 1);
						break;
					}
					else{
						ll q = get(1, 1, n + 1, lo, 0);
						if (q > x){
							change(1, 1, n + 1, hi, idx + 1, q - k, 0);
							change(1, 1, n + 1, hi, idx + 1, q - k, 1);
						}
						else{
							change(1, 1, n + 1, hi, idx + 1, x - k, 0);
							change(1, 1, n + 1, hi, idx + 1, x - k, 1);
							break;
						}
						lo = 0;
					}
				}
			}
		}
		answer = max(answer, seg[1][1]);
	}
	cout << answer << endl;
}