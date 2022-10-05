#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9;
const ll INF = 1e18;

int n, k, q;
struct point{
	int x[(1 << 5)];
	point(){}
	void read(){
		for(int i = 0; i < k; i++)
			scanf("%d", &x[i]);
	}
	int dist(point a){
		int res = 0;
		for(int i = 0; i < k; i++)
			res += abs(x[i] - a.x[i]);
		return res;
	}
	int get(int mask){
		int res = 0;
		for(int i = 0; i < k; i++)
			if((1 << i) & mask)
				res += x[i];
			else
				res -= x[i];
		return res;
	}
} a[N];
struct btr{
	int val;
	int mx[(1 << 5)];
	btr(){
		val = -1;
	}
	btr(int id){
		val = 0;
		for(int i = 0; i < (1 << k); i++)
			mx[i] = a[id].get(i);
	}
} t[N << 2];
btr Merge(btr l, btr r){
	if(l.val == -1)
		return r;
	if(r.val == -1)
		return l;
	btr res;
	res.val = max(l.val, r.val);
	for(int i = 0; i < (1 << k); i++)                            
		res.val = max(res.val, l.mx[i] + r.mx[(1 << k) - 1 - i]);
	for(int i = 0; i < (1 << k); i++)                            
		res.mx[i] = max(l.mx[i], r.mx[i]);
	return res;
}

void build(int v, int tl, int tr){
	if(tl == tr){
		t[v] = btr(tl);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	t[v] = Merge(t[v << 1], t[v << 1 | 1]);
}
void upd(int v, int tl, int tr, int pos){
	if(tl == tr){
		t[v] = btr(tl);
		return;
	}
	int tm = (tl + tr) >> 1;
	if(pos <= tm)
    	upd(v << 1, tl, tm, pos);
	else
		upd(v << 1 | 1, tm + 1, tr, pos);
	t[v] = Merge(t[v << 1], t[v << 1 | 1]);
}
btr get(int v, int tl, int tr, int l, int r){
	if(r < tl || tr < l || l > r)
		return btr();
	if(l <= tl && tr <= r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return Merge(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
}
int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		a[i].read();
	build(1, 1, n);
	scanf("%d", &q);
	while(q--){
		int type;
		scanf("%d", &type);
		if(type == 1){
			int id;
			scanf("%d", &id);
			a[id].read();
			upd(1, 1, n, id);
		}else{
			int l, r;
			scanf("%d%d", &l, &r);
			int res = get(1, 1, n, l, r).val;
			printf("%d\n", res);
		}
	}

	return 0;
}