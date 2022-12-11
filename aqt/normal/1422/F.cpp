
// Problem : F. Boring Queries
// Contest : Codeforces - Codeforces Round #675 (Div. 2)
// URL : https://codeforces.com/contest/1422/problem/F
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int v;
	Node * c[2];
	Node * cop(){
		Node * x = new Node();
		x->v = v;
		x->c[0] = c[0];
		x->c[1] = c[1];
		return x;
	}
};

int N;
int arr[200005];
vector<pair<int, int>> v[200005];
Node * rt[200005];
const long long MOD = 1e9+7;

long long mult(long long a, long long b){
	return a*b%MOD;
}

long long qikpow(long long b, long long e){
	if(!e){
		return 1;
	}
	long long ret = qikpow(b, e/2);
	ret = mult(ret, ret);
	if(e&1){
		ret = mult(ret, b);
	}
	return ret;
}

Node * build(int l, int r){
	Node * n = new Node();
	n->v = 1;
	if(l == r){
		return n;
	}
	int mid = (l+r)/2;
	n->c[0] = build(l, mid);
	n->c[1] = build(mid+1, r);
	return n;
}

Node * upd(int ll, int rr, int p, long long v, Node * x){
	auto n = x->cop();
	n->v = mult(n->v, v);
	if(ll == rr){
		return n;
	}
	int mid = (ll+rr)/2;
	if(p <= mid){
		n->c[0] = upd(ll, mid, p, v, n->c[0]);
	}
	else{
		n->c[1] = upd(mid+1, rr, p, v, n->c[1]);
	}
	return n;
}

int query(int ll, int rr, int l, int r, Node * n){
	if(ll == l && rr == r){
		//cout << ll << " " << rr << " " << n->v << "\n";
		return n->v;
	}
	int mid = (ll + rr)/2;
	if(r <= mid){
		return query(ll, mid, l, r, n->c[0]);
	}
	else if(l > mid){
		return query(mid+1, rr, l, r, n->c[1]);
	}
	else{
		return mult(query(ll, mid, l, mid, n->c[0]), query(mid+1, rr, mid+1, r, n->c[1]));
	}
}

void add(int k, int p, int i){
	int lst = 1;
	while(v[k].size()){
		if(v[k].back().first <= p){
			rt[i] = upd(1, N, v[k].back().second, qikpow(v[k].back().first/lst, MOD-2), rt[i]);
			lst = v[k].back().first;
			v[k].pop_back();
		}
		else{
			rt[i] = upd(1, N, v[k].back().second, qikpow(p/lst, MOD-2), rt[i]);			
			break;
		}
	}
	v[k].emplace_back(p, i);	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	rt[0] = build(1, N);
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		rt[i] = upd(1, N, i, arr[i], rt[i-1]);
		for(int k = 2; k*k<=arr[i]; k++){
			if(arr[i]%k == 0){
				int cnt = 0;
				int p = 1;
				do{
					cnt++;
					arr[i] /= k;
					p *= k;
				}
				while(arr[i]%k == 0);
				add(k, p, i);
			}
		}
		if(arr[i]-1){
			add(arr[i], arr[i] ,i);
		}
	}
	int Q;
	cin >> Q;
	int lst = 0;
	while(Q--){
		int l, r;
		cin >> l >> r;
		l += lst;
		r += lst;
		l %= N;
		r %= N;
		l++;
		r++;
		if(l > r){
			swap(l, r);
		}
		cout << (lst = query(1, N, l, r, rt[r])) << "\n";
	}
}