#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

struct node {
	int pos;
	int val;
	short pr;
	ll sum = 0;
	node *l = 0, *r = 0;
	node(int pos, int val, short pr) : pos(pos), val(val), pr(pr){}
};

ll SUM(node *v){
	return v ? v->sum : 0;
}

void split(node *t, int x, node* &l, node* &r){
	if(t==0){
		l = r = 0;
		return;
	}
	if(t->pos < x){
		l = t;
		split(t->r, x, t->r, r);
	} else {
		r = t;
		split(t->l, x, l, t->l);
	}
	t->sum = t->val + SUM(t->l) + SUM(t->r);
}

void insert(node* &t, int pos, int val, short pr){
	if(t == 0 || t->pr < pr){
		node* v = new node(pos, val, pr);
		split(t, pos, v->l, v->r);
		v->sum = val + SUM(v->l) + SUM(v->r);
		t = v;
		return;
	}
	t->sum += val;
	if(t->pos < pos) insert(t->r, pos, val, pr);
	else insert(t->l, pos, val, pr);
}

ll ask(node *t, int pos){
	if(t == 0) return 0LL;
	if(t->pos <= pos)
		return t->val + SUM(t->l) + ask(t->r, pos);
	else
		return ask(t->l, pos);
}

void up(node* &t, int fr, int to, int dif){
	insert(t, fr, dif, rand());
	insert(t, to, -dif, rand());
}

struct ST2{
	int n;
	vector<node*> vs;
	ST2(int n) : n(n) {
		vs.resize(4*n);
	}
	void upd(int x1, int x2, int y1, int y2, int dif,
		     int i=1, int fr=0, int to=-1){
		if(to==-1){
			to = n;
		}
		if(x1<=fr && to<=x2){
			up(vs[i], y1,y2,dif);
		}
		else if(to<=x1 || x2<=fr) return;
		else {
			int mi = (fr+to)/2;
			upd(x1,x2,y1,y2,dif, 2*i  , fr, mi);
			upd(x1,x2,y1,y2,dif, 2*i+1, mi, to);
		}
	}
	ll que(int x, int y){
		int i = 1, fr = 0, to = n;
		ll ans = 0;
		while(true){
			ans += ask(vs[i], y);
			if(fr+1 == to) break;
			int mi = (fr+to)/2;
			if(x < mi){
				to = mi;
				i = 2*i;
			} else {
				fr = mi;
				i = 2*i+1;
			}
		}
		return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vi as(n);
	vector<set<int>> ls(n);
	trav(x, as) cin >> x, --x;
	ST2 root(n);

	auto change = [&](int pos, int val, int c){
		auto it = ls[val].lower_bound(pos);
		int pr = -1, nx = n;
		if(it != ls[val].begin()){
			--it;
			pr = *it;
		}
		it = ls[val].upper_bound(pos);
		if(it != ls[val].end()){
			nx = *it;
		}
		if(pr != -1) root.upd(0, pr+1, pos, nx, c*(pos-pr));
		if(nx != n)  root.upd(pr+1, pos+1, nx, n, c*(nx-pos));
		if(c == 1) ls[val].insert(pos);
		else ls[val].erase(pos);
	};

	rep(i,0,n){
		change(i, as[i], 1);
	}

	rep(_,0,m){
		int t, a, b;
		cin >> t >> a >> b;
		if(t == 1){
			int p = a-1, x = b-1;
			change(p, as[p], -1);
			as[p] = x;
			change(p, as[p],  1);
		} else {
			cout << root.que(a-1, b-1) << endl;
		}
	}
}