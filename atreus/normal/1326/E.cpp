#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 3e5 + 10;

int p[maxn], q[maxn], pos[maxn];

int seg[4*maxn], lazy[4*maxn];

void shift(int,int,int);

void add(int id, int L, int R, int l, int r, int val){
	if (r <= L or R <= l)
		return;
	if (l <= L and R <= r){
		seg[id] += val;
		lazy[id] += val;
		return;
	}
	shift(id, L, R);
	int mid = (L + R) >> 1;
	add(2*id+0, L, mid, l, r, val);
	add(2*id+1, mid, R, l, r, val);
	seg[id] = max(seg[2*id+0], seg[2*id+1]);
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
	for (int i = 1; i <= n; i++){
		cin >> p[i];
		pos[p[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		cin >> q[i];
	int now = n;
	add(1, 1, n+1, 1, pos[n]+1, +1);
	for (int i = 1; i <= n; i++){
		cout << now << " ";
		add(1, 1, n+1, 1, q[i]+1, -1);
		while (seg[1] <= 0){
			now --;
			add(1, 1, n+1, 1, pos[now]+1, +1);
		}
	}
	cout << '\n';
}