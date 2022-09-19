#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;

const int N = 2e5 + 10;

struct Gauss{
	int wh[32];
	Gauss (){
		memset(wh, 0, sizeof wh);
	}
	void Add(int x){
		for(int i = 30; i >= 0; i--)
			if(x >> i & 1){
				if(!wh[i])
					wh[i] = x;
				x ^= wh[i];
			}
		
	}
	bool Query(int x){
		for(int i = 30; i >= 0; i--)
			if(x >> i & 1){
				if(!wh[i]) return false;
				x ^= wh[i];
			}
		return true;
	}
	int size(){
		int sz = 0;
		for(int i = 0; i < 31; i++)
			if(wh[i])
				sz ++;
		return sz;
	}
};
struct node{
	Gauss Base;
	int lz;
	node (){
		Base.Add(1 << 30);
		lz = 0;
	}
	void Add(int x){
		Base.Add(x);
	}
	int Get(){
		int sz = Base.size();
		if(Base.Query(1 << 30)) sz --;
		return (1 << sz);
	}
	void Apply(int x){
		Base.wh[30] ^= x;
		lz ^= x;
	}
};
node Merge(node& a, node& b){
	node res;
	res.Base.wh[30] = 0;
	for(int i = 0; i <= 30; i++){
		res.Add(a.Base.wh[i]);
		res.Add(b.Base.wh[i]);
	}
	return res;
}

node seg[N*3];
inline void Shift(int id){
	seg[id << 1].Apply(seg[id].lz);
	seg[id << 1 | 1].Apply(seg[id].lz);
	seg[id].lz = 0;
}
inline void Xor(int l, int r, int x, int id = 1, int L = 0, int R = N){
	if(r <= L || R <= l) return ;
	if(l <= L && R <= r){
		seg[id].Apply(x);
		return ;
	}
	Shift(id);
	int mid = (L + R) >> 1;
	Xor(l, r, x, id << 1, L, mid);
	Xor(l, r, x, id << 1 | 1, mid, R);
	seg[id] = Merge(seg[id << 1], seg[id << 1 | 1]);
}
node res;
inline void Get(int l, int r, int id = 1, int L = 0, int R = N){
	if(r <= L || R <= l) return ;
	if(l <= L && R <= r){
		res = Merge(res, seg[id]);
		return ;
	}
	Shift(id);
	int mid = (L + R) >> 1;
	Get(l, r, id << 1, L, mid);
	Get(l, r, id << 1 | 1, mid, R);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifdef safar
		freopen("input.in", "r", stdin);
	#endif
	int n, q;
	cin >> n >> q;
	int x;
	for(int i = 1; i <= n; i++){
		cin >> x;
		Xor(i, i + 1, x);
	}
	int t, l, r;
	for(int i = 0; i < q; i++){
		cin >> t >> l >> r;
		if(t == 1){
			cin >> x;
			Xor(l, r + 1, x);
		} else {
			memset(res.Base.wh, 0, sizeof res.Base.wh);
			Get(l, r + 1);
			cout << res.Get() << '\n';
		}
	}
	return 0;
}