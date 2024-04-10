#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 200100;

struct node{
	int type;
	int pre, suf;
	int sum, mx;
};
node t[N << 2];
int u[N << 2];
int n, q, a[N], VAL[N];
set< int > st[N];

node Merge(node a, node b){
	node c;
	if(a.type == 0 && b.type == 0){
		c.type = 0;
		c.pre = a.pre;
		c.suf = b.suf;
		c.sum = a.sum + b.sum + max(a.suf, b.pre);
		c.mx = max(a.mx, b.mx);
	}
    if(a.type == 1 && b.type == 1){
		c.type = 1;
		c.pre = c.suf = 0;
		c.sum = max(a.sum, b.sum);
		c.mx = max(a.mx, b.mx);
	}
	if(a.type == 0 && b.type == 1){
		c.type = 0;
		c.pre = a.pre;
		c.suf = max(a.suf, b.sum);
		c.sum = a.sum;
		c.mx = max(a.mx, b.mx);
	}
	if(a.type == 1 && b.type == 0){
		c.type = 0;
		c.pre = max(a.sum, b.pre);
		c.suf = b.suf;
		c.sum = b.sum;
		c.mx = max(a.mx, b.mx);
	}
	return c;
}
void upd(int v, int tl, int tr, int pos, int val){
	if(tl == tr){
		if(u[v]){
			t[v].type = 1;
			t[v].sum = t[v].mx = val;
			t[v].pre = t[v].suf = 0;
		}else{
			t[v].type = 0;
			t[v].pre = 0;
			t[v].suf = val;
			t[v].sum = 0;
			t[v].mx = val;
		}
		VAL[tl] = val;
		return;
	}
	int tm = (tl + tr) >> 1;
	if(pos <= tm)
		upd(v << 1, tl, tm, pos, val);
	else
		upd(v << 1 | 1, tm + 1, tr, pos, val);
	t[v] = Merge(t[v << 1], t[v << 1 | 1]);
	if(u[v]){
		t[v].type = 1, 
		t[v].sum = t[v].mx;
		t[v].pre = t[v].suf = 0;
	}
}
void add(int v, int tl, int tr, int l, int r, int k){
	if(r < tl || tr < l || l > r)
		return;
	if(l <= tl && tr <= r){
		u[v] += k;
		if(tl == tr){
			if(u[v]){
				t[v].type = 1;
				t[v].sum = t[v].mx = VAL[tl];
				t[v].pre = t[v].suf = 0;
			}else{
				t[v].type = 0;
				t[v].pre = 0;
				t[v].suf = VAL[tl];
				t[v].sum = 0;
				t[v].mx = VAL[tl];
			}
		}else{
			t[v] = Merge(t[v << 1], t[v << 1 | 1]);
			if(u[v]){
				t[v].type = 1, 
				t[v].sum = t[v].mx;
				t[v].pre = t[v].suf = 0;
			}
		}
		return;			
	}
	int tm = (tl + tr) >> 1;
	add(v << 1, tl, tm, l, r, k);
	add(v << 1 | 1, tm + 1, tr, l, r, k);
	t[v] = Merge(t[v << 1], t[v << 1 | 1]);	
	if(u[v]){
		t[v].type = 1, 
		t[v].sum = t[v].mx;
		t[v].pre = t[v].suf = 0;
	}
}
int main()
{
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		st[a[i]].insert(i);
	}
	for(int i = 1; i <= n; i++)
		upd(1, 1, n, i, 0);
	for(int i = 1; i <= 200000; i++)
		if(!st[i].empty()){
			add(1, 1, n, *st[i].begin() + 1, *st[i].rbegin(), 1);
            upd(1, 1, n, *st[i].begin(), st[i].size());
        }
    printf("%d\n", n - (t[1].pre + t[1].suf + t[1].sum));
	while(q--){
		int i, x;
		scanf("%d%d", &i, &x);
		
		add(1, 1, n, *st[a[i]].begin() + 1, *st[a[i]].rbegin(), -1);
		upd(1, 1, n, *st[a[i]].begin(), 0);
        st[a[i]].erase(i);
        if(!st[a[i]].empty()){
        	add(1, 1, n, *st[a[i]].begin() + 1, *st[a[i]].rbegin(), 1);
			upd(1, 1, n, *st[a[i]].begin(), st[a[i]].size());
        }

        a[i] = x;
		if(!st[a[i]].empty()){
			add(1, 1, n, *st[a[i]].begin() + 1, *st[a[i]].rbegin(), -1);
			upd(1, 1, n, *st[a[i]].begin(), 0);
		}
        st[a[i]].insert(i);
        add(1, 1, n, *st[a[i]].begin() + 1, *st[a[i]].rbegin(), 1);
		upd(1, 1, n, *st[a[i]].begin(), st[a[i]].size());

		printf("%d\n", n - (t[1].pre + t[1].suf + t[1].sum));
	}
	return 0;
}