
// Problem : C. Case of Chocolate
// Contest : Codeforces - Codeforces Round #310 (Div. 1)
// URL : https://codeforces.com/contest/555/problem/C
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int mn;
	Node * c[2];
	Node(int _mn){
		mn = _mn;
		c[0] = c[1] = NULL;
	}
};

Node * row, * col;
int N, Q;
unordered_set<int> xst, yst;

void upd(int nl, int nr, int l, int r, int v, Node * n){
	if(nl == l && nr == r){
		n->mn = max(n->mn, v);
		return;
	}
	int mid = nl+nr>>1;
	if(!n->c[0]){
		n->c[0] = new Node(n->mn);
		n->c[1] = new Node(n->mn);
	}
	if(r <= mid){
		if(!n->c[0]){
			n->c[0] = new Node(n->mn);
		}
		upd(nl, mid, l, r, v, n->c[0]);
	}
	else if(l > mid){
		if(!n->c[1]){
			n->c[1] = new Node(n->mn);
		}
		upd(mid+1, nr, l, r, v, n->c[1]);
	}
	else{
		if(!n->c[0]){
			n->c[0] = new Node(n->mn);
		}
		if(!n->c[1]){
			n->c[1] = new Node(n->mn);
		}
		upd(nl, mid, l, mid, v, n->c[0]);
		upd(mid+1, nr, mid+1, r, v, n->c[1]);
	}
}

int get(int nl, int nr, int p, Node * n){
	if(!n){
		return 0;
	}
	int ret = n->mn;
	int mid = nl+nr>>1;
	if(p <= mid){
		return max(ret, get(nl, mid, p, n->c[0]));
	}
	else{
		return max(ret, get(mid+1, nr, p, n->c[1]));
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	col = new Node(0);
	row = new Node(0);
	while(Q--){
		int x, y;
		char c;
		cin >> x >> y >> c;
		if(c == 'U'){
			if(yst.count(y)){
				cout << 0 << "\n";
				continue;
			}
			yst.insert(y);
			int k = get(1, N, y, row);
			cout << y - k << "\n";
			//cout << " " << get(y, row) << endl;		
			//cout << x << " " << N-get(y, row) << endl;
			if(x <= N-k){
				upd(1, N, x, N-k, x, col);
			}
		}
		else{
			if(xst.count(x)){
				cout << 0 << "\n";
				continue;
			}
			xst.insert(x);
			//cout << "hey " << get(y, row) << "\n";
			int k = get(1, N, x, col);			
			cout << x - k << "\n";
			//cout << " " << get(x, col) << endl;
			//cout << y << " " << N-get(x, col) << endl;
			if(y <= N-k){
				upd(1, N, y, N-k, y, row);
			}
		}
	}
}