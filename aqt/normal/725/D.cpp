
// Problem : D. Contest Balloons
// Contest : Codeforces - Canada Cup 2016
// URL : https://codeforces.com/contest/725/problem/D
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

struct node{
	long long b, d, mn, sz;
	int pri;
	node * c[2];
	node (long long _b, long long _d){
		b = _b;
		mn = d = _d;
		sz = 1;
		pri = uniform_int_distribution<int>(INT_MIN, INT_MAX)(rando);
		c[0] = c[1] = NULL;
	}
};

int N;
long long C;
node * treap;

int getsz(node * n){
	return n ? n->sz : 0;
}

long long getmn(node * n){
	return n ? n->mn : LLONG_MAX/2;
}

node * pu(node * n){
	n->mn = min(min(getmn(n->c[0]), getmn(n->c[1])), n->d);
	n->sz = 1 + getsz(n->c[0]) + getsz(n->c[1]);
	return n;
}

pair<node *, node *> split(node * n, long long k){
	if(!n){
		return {n, n};
	}
	//cout << n->b << " " << k << endl;
	if(n->b <= k){
		auto p = split(n->c[0], k);
		n->c[0] = p.second;
		return {p.first, pu(n)};
	}
	else{
		auto p = split(n->c[1], k);
		n->c[1] = p.first;
		return {pu(n), p.second};
	}
}

pair<node *, node *> splitsz(node * n, int k){
	if(!n){
		return {n, n};
	}
	if(getsz(n->c[0]) >= k){
		auto p = splitsz(n->c[0], k);
		n->c[0] = p.second;
		return {p.first, pu(n)};
	}
	else{
		auto p =splitsz(n->c[1], k - getsz(n->c[0]) - 1);
		n->c[1] = p.first;
		return {pu(n), p.second};
	}
}

node * merge(node * l, node * r){
	if(!l){
		return r;
	}
	if(!r){
		return l;
	}
	if(l->pri > r->pri){
		l->c[1] = merge(l->c[1], r);
		return pu(l);
	}
	else{
		r->c[0] = merge(l, r->c[0]);
		return pu(r);
	}
}

int getpos(node * n, long long k){
	assert(n);
	if(n->d == k){
		return 1 + getsz(n->c[0]);
	}
	else if(getmn(n->c[0]) == k){
		return getpos(n->c[0], k);
	}
	else{
		return getpos(n->c[1], k) + getsz(n->c[0]) + 1;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long T;
	cin >> N;
	N--;
	cin >> C >> T;
	int ans = N+5;
	while(N--){
		long long a, b;
		cin >> a >> b;
		//cout << a << " " << b << endl;
		auto p = split(treap, a);
		//cout << " " << b-a+1 << endl;
		treap = merge(p.first, merge(new node(a, b - a + 1), p.second));
	}
	while(1){
		auto p = split(treap, C);
		ans = min(ans, getsz(p.first)+1);
		//cout << "help: " << getmn(p.first) << "\n";
		if(getmn(p.first) > C){
			break;
		}
		//cout << getmn(p.first) << "\n";
		C -= getmn(p.first);
		//cout << "bling: " << getmn(p.first) << endl;
		int pos = getpos(p.first, getmn(p.first));		
		//cout << "position: " << pos << endl;
		//cout << getsz(p.first) << endl;
		auto q = splitsz(p.first, pos);
		//cout << "new size: " << getsz(q.first) << endl;
		//assert(pos == getsz(q.first));
		auto r = splitsz(q.first, getsz(q.first)-1);
		//cout << getsz(r.second) << endl;
		treap = merge(merge(r.first, q.second), p.second);
	}
	cout << ans;
}