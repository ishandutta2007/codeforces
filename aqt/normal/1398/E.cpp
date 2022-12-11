
// Problem : E. Two Types of Spells
// Contest : Codeforces - Educational Codeforces Round 93 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1398/problem/E
// Memory Limit : 256 MB
// Time Limit : 3500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

struct Node{
	long long sum;
	int v;
	int sz;
	int t;
	int cnt;
	int pri;
	Node * c[2];
	Node(int val, int typ){
		v = sum = val;
		sz = 1;
		t = typ;
		cnt = typ;
		pri = uniform_int_distribution<int>(INT_MIN, INT_MAX)(rando);
		c[0] = c[1] = NULL;
	}
};

Node * treap;

int getsz(Node * n){
	return (!n ? 0 : n->sz);
}

Node * pu(Node * n){
	if(!n){
		return n;
	}
	n->sum = n->v;
	n->cnt = n->t;
	n->sz = 1;
	for(int k = 0; k<2; k++){
		if(n->c[k]){
			n->sum += n->c[k]->sum;
			n->sz += n->c[k]->sz;
			n->cnt += n->c[k]->cnt;
		}
	}
	return n;
}

pair<Node *, Node *> split(int k, Node * n){
	if(!n){
		return {n, n};
	}
	if(n->v <= k){
		auto p = split(k, n->c[0]);
		n->c[0] = p.second;
		return {p.first, pu(n)};
	}
	else{
		auto p = split(k, n->c[1]);
		n->c[1] = p.first;
		return {pu(n), p.second};
	}
}

pair<Node *, Node *> splitsz(int k, Node * n){
	if(!n){
		return {n, n};
	}
	if(getsz(n->c[0]) >= k){
		auto p = splitsz(k ,n->c[0]);
		n->c[0] = p.second;
		return {p.first, pu(n)};
	}
	else{
		auto p = splitsz(k - getsz(n->c[0]) - 1, n->c[1]);
		n->c[1] = p.first;
		return {pu(n), p.second};
	}
}

Node * merge (Node * lft, Node * rht){
	if(!lft){
		return rht;
	}
	if(!rht){
		return lft;
	}
	if(lft->pri > rht->pri){
		lft->c[1] = merge(lft->c[1], rht);
		return pu(lft);
	}
	else{
		rht->c[0] = merge(lft, rht->c[0]);
		return pu(rht);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int Q;
	cin >> Q;
	while(Q--){
		int t, v;
		cin >> t >> v;
		if(v < 0){
			v = -v;
			auto p = split(v-1, treap);
			auto q = split(v, p.first);
			treap = merge(q.first, p.second);
		}
		else{
			auto p = split(v, treap);
			treap = merge(p.first, merge(new Node(v, t), p.second));
		}
		if(treap){
			long long out = treap->sum;
			int c = treap->cnt;
			auto p = splitsz(c, treap);
			if(p.first){
				if(p.first->cnt == c){
					auto q = splitsz(c-1, p.first);
					if(q.first){
						out += q.first->sum;
					}
					p.first = merge(q.first, q.second);
					if(p.second){
						auto r = splitsz(1, p.second);
						if(r.first){
							out += r.first->sum;
						}
						p.second = merge(r.first, r.second);
					}
					treap = merge(p.first, p.second);
				}
				else{
					out += p.first->sum;
					treap = merge(p.first, p.second);
				}
			}
			cout << out << endl;
		}
		else{
			cout << 0 << endl;
		}
	}
}