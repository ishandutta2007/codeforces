#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
const int mod = 998244353;
const int inf = 1e6 + 10;

int a[maxn];
int seg[4*maxn];
int lazy[4*maxn];

void shift(int,int,int);

int get(int id, int L, int R, int l, int r){
	if (r <= L or R <= l)
		return 2*inf;
	if (l <= L and R <= r)
		return seg[id];
	shift(id,L,R);
	int mid = (L + R) >> 1;
	return min(get(2*id+0, L, mid, l, r), get(2*id+1, mid, R, l, r));
}

void add(int id, int L, int R, int l, int r, int val){
	if (r <= L or R <= l)
		return;
	if (l <= L and R <= r){
		seg[id] += val;
		lazy[id] += val;
		return;
	}
	shift(id,L,R);
	int mid = (L + R) >> 1;
	add(2*id+0, L, mid, l, r, val);
	add(2*id+1, mid, R, l, r, val);
	seg[id] = min(seg[2*id+0], seg[2*id+1]);
}

void shift(int id, int L, int R){
	if (lazy[id] == 0)
		return;
	int mid = (L + R) >> 1;
	add(2*id+0, L, mid, L, mid, lazy[id]);
	add(2*id+1, mid, R, mid, R, lazy[id]);
	lazy[id] = 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	add(1, 0, n+1, 1, n+1, +inf);
	add(1, 0, n+1, 0, 1, 1);
	for (int i = 1; i < n; i++){
		int tmp = min({get(1,0,n+1,0,a[i+1])+1,
				get(1,0,n+1,a[i+1],a[i+1]+1),
				get(1,0,n+1,a[i+1]+1,n+1)+1});
		if (a[i] != a[i+1])
			add(1, 0, n+1, 0, n+1, +1);

		int t = get(1, 0, n+1, a[i], a[i]+1);
		if (t > tmp)
			add(1, 0, n+1, a[i], a[i]+1, tmp-t);
	}
	cout << seg[1] << endl;
}