#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;

ll seg[4*maxn];
int mxm[4*maxn], mnm[4*maxn], lazy[4*maxn];

void shift(int,int,int);

void merge(int id){
	seg[id] = seg[2*id+0] + seg[2*id+1];
	mxm[id] = max(mxm[2*id+0],mxm[2*id+1]);
	mnm[id] = min(mnm[2*id+0],mnm[2*id+1]);
}

void add(int id, int L, int R, int l, int r, int val){
	if (r <= L or R <= l)
		return;
	if (l <= L and R <= r){
		seg[id] += 1LL*(R-L)*val;
		mxm[id] += val;
		mnm[id] += val;
		lazy[id] += val;
		return;
	}
	shift(id,L,R);
	int mid = (L + R) >> 1;
	add(2*id+0, L, mid, l, r, val);
	add(2*id+1, mid, R, l, r, val);
	merge(id);
}

void shift(int id, int L, int R){
	if (lazy[id] == 0)
		return;
	int mid = (L + R) >> 1;
	add(2*id+0, L, mid, L, mid, lazy[id]);
	add(2*id+1, mid, R, mid, R, lazy[id]);
	lazy[id] = 0;
}

void change(int id, int L, int R, int l, int r, int val){
	if (r <= L or R <= l or mnm[id] >= val)
		return;
	if (l <= L and R <= r and mnm[id] == mxm[id]){
		add(id, L, R, l, r, val-mxm[id]);
		return;
	}
	shift(id,L,R);
	int mid = (L + R) >> 1;
	change(2*id+0, L, mid, l, r, val);
	change(2*id+1, mid, R, l, r, val);
	merge(id);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	int suf = 0;
	ll answer = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == '1'){
			add(1, 0, n, i-suf, i+1, +1);
			if (suf != i)
				change(1, 0, n, 0, i-suf, suf+1);
			suf++;
		}
		else
			suf = 0;
		answer += seg[1];
	}
	cout << answer << '\n';
}