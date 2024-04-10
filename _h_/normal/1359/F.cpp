#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long double ld;
typedef vector<int> vi;

struct Node {
	int i, pr;
	Node *l = 0, *r = 0;
	Node(int i) : i(i){
		pr = rand();
	}
};

Node* mini(Node *v){
	return v->l ? mini(v->l) : v;
}

Node* maxi(Node *v){
	return v->r ? mini(v->r) : v;
}

Node* merge(Node* l, Node* r){
	if(l && r){
		if(l->pr > r->pr){
			l->r = merge(l->r, r);
			return l;
		} else {
			r->l = merge(l, r->l);
			return r;
		}
	} else {
		return l ?: r;
	}
}

const int mx = 25000;

ld k[mx], m[mx];

ld yt(ld t, int i){
	return k[i] * t + m[i];	
}

void split(Node* v, ld yi, ld t, Node* &l, Node* &r){
	if(v){
		if(yt(t, v->i) < yi){
			split(v->r, yi, t, v->r, r);
			l = v;
		} else {
			split(v->l, yi, t, l, v->l);
			r = v;
		}
	} else {
		l = r = 0;
	}
}

Node* ins(Node* v, int i, ld t){
	Node *l, *r;
	split(v, yt(t, i), t, l, r);
	return merge(l, merge(new Node(i), r));
}

bool lt(ld x, ld y){
	ld eps = 1e-11 / max(ld(1), min(x,y));
	return x + eps < y;
}

Node* ers(Node *v, int i, ld t, bool &flag){
	Node *l, *m, *r;
	split(v, yt(t, i), t, l, r);
	split(r, nextafter(yt(t, i), INFINITY), t, m, r);
	if( m && m->i == i
	      && m->l == 0
	      && m->r == 0
	      && ( !l || lt(yt(t, maxi(l)->i), yt(t, i)) )
	      && ( !r || lt(yt(t, i), yt(t, mini(r)->i)) ) ){
		return merge(l, r);
	} else {
		flag = true;
		return 0;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vi x(n), y(n), dx(n), dy(n), s(n);
	rep(i,0,n){
		cin >> x[i] >> y[i] >> dx[i] >> dy[i] >> s[i];
		k[i] = ld(dy[i]) / dx[i];
		m[i] = y[i] - x[i] * k[i];
	}

	auto collide = [&](ld t){
		vector<pair<ld, int>> evs;
		rep(i,0,n){
			ld en = x[i] + dx[i] * s[i] * t / hypotl(dx[i], dy[i]);
			evs.emplace_back(min((ld)x[i]-1e-9, en), i);
			evs.emplace_back(max((ld)x[i]+1e-9, en), -1-i);
		}
		sort(all(evs));
		bool flag = false;
		Node *root = 0;
		trav(pa, evs){
			if(pa.second < 0){
				root = ers(root, -1-pa.second, pa.first, flag);
				if(flag) return true;
			} else {
				root = ins(root, pa.second, pa.first);
			}
		}
		return false;
	};

	ld lo = 0, hi = 1e10;

	if(!collide(hi)){
		cout << "No show :(" << endl;
		return 0;
	}

	while((hi-lo)/max(ld(1), lo) > 1e-7){
		ld mi = (lo + hi)/2;
		if(collide(mi)) hi = mi;
		else lo = mi;
	}
	cout.precision(9);
	cout << hi << endl;
}