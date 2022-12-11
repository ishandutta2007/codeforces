
// Problem : F. T-Shirts
// Contest : Codeforces - Educational Codeforces Round 15
// URL : https://codeforces.com/contest/702/problem/F
// Memory Limit : 1024 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct node{
	int lzyv, lzyc, idx, val, cap, pri;
	node * c[2];
	node (int v, int q){
		val = 0;
		idx = q;
		lzyv = lzyc = 0;
		cap = v;
		pri = rand()*rand();
		c[0] = c[1] = NULL;
	}
	node (node * n){
		val = n->val;
		idx = n->idx;
		lzyv = lzyc = 0;
		cap = n->cap;
		pri = rand()*rand();
		c[0] = c[1] = NULL;
	}
};

int N, Q;
pair<int, int> arr[200005];
int ans[200005];
node * treap;

void pd(node * n){
	for(int i = 0; i<2; i++){
		if(n->c[i]){
			n->c[i]->lzyv += n->lzyv;
			n->c[i]->val += n->lzyv;
			n->c[i]->lzyc += n->lzyc;
			n->c[i]->cap += n->lzyc;
		}
	}
	n->lzyv = n->lzyc = 0;
}

pair<node *, node *> split(node * n, int k){
	if(!n){
		return {n, n};
	}
	pd(n);
	if(n->cap >= k){
		auto p = split(n->c[0], k);
		n->c[0] = p.second;
		return {p.first, n};
	}
	else{
		auto p = split(n->c[1], k);
		n->c[1] = p.first;
		return {n, p.second};
	}
}

node * merge(node * lft, node * rht){
	if(!lft){
		return rht;
	}
	if(!rht){
		return lft;
	}
	pd(lft);
	pd(rht);
	if(lft->pri > rht->pri){
		lft->c[1] = merge(lft->c[1], rht);
		return lft;
	}
	else{
		rht->c[0] = merge(lft, rht->c[0]);
		return rht;
	}
}

node * insert(int n, int q){
	auto p = split(treap, n);
	return merge(p.first, merge(new node(n, q), p.second));
}

node * insert(int n, node * nd){
	auto p = split(treap, n);
	return merge(p.first, merge(new node(nd), p.second));
}

void trav1(node * n){
	if(!n){
		return;
	}
	pd(n);
	trav1(n->c[0]);
	treap = insert(n->cap, n);
	trav1(n->c[1]);
}

void trav2(node * n){
	if(!n){
		return;
	}
	pd(n);
	trav2(n->c[0]);
	ans[n->idx] = n->val;
	trav2(n->c[1]);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i].second >> arr[i].first;
		arr[i].first *= -1;
	}
	sort(arr+1, arr+1+N);
	cin >> Q;
	for(int q = 1; q<=Q; q++){
		int k;
		cin >> k;
		treap = insert(k, q);
	}
	for(int n = 1; n<=N; n++){
		int t = arr[n].second;
		auto p = split(treap, t);
		if(p.second){
			//cout << t << "\n";
			p.second->val++;
			p.second->lzyv++;
			p.second->cap -= t;
			p.second->lzyc -= t;
		}
		treap = p.first;
		auto q = split(p.second, t);
		trav1(q.first);
		treap = merge(treap, q.second);
	}
	trav2(treap);
	for(int q = 1; q<=Q; q++){
		cout << ans[q] << " ";
	}
}