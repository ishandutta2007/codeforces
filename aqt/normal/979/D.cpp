#include <bits/stdc++.h>

using namespace std;

struct node{
	node *c[2];
	int dep;
	int val;
	node(int d){
		c[0] = c[1] = NULL;
		dep = d;
	}
};

int M = 100000, Q;
node * rt[100005];
bool done[100005];

void add(node * n, int x){
	//cout << n->dep << " " << x << "\n";
	if(n->dep == -1){
		n->val = x;
		return;
	}
	int d = n->dep;
	if(!n->c[x>>d&1]){
		n->c[x>>d&1] = new node(d-1);
	}
	add(n->c[x>>d&1], x);
}

int query(node * n, int x, int b, bool onborder){
	//cout << (n == NULL) << " " << x << " " << b << " " << onborder << "\n";
	if(n == NULL){
		return -1;
	}
	//cout << " " << (n-> val^x) << "\n";
	if(n->dep == -1){
		return (n->val^x);
	}
	int dig = x>>n->dep&1;
	//cout << " " << dig << "\n";
	if(onborder){
		int lim = b>>n->dep&1;
		int ret = -1;
		for(int l = 0; l<=lim; l++){
			ret = max(ret, query(n->c[l], x, b, l == lim));
		}
		return ret;
	}
	else{
		if(n->c[dig^1]){
			return query(n->c[dig^1], x, b, 0);
		}
		else{
			return query(n->c[dig], x, b, 0);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> Q;
	for(int n =1 ; n<=M; n++){
		rt[n] = new node(16);
	}
	while(Q--){
		int c;
		cin >> c;
		if(c == 1){
			int n;
			cin >> n;
			if(done[n]){
				continue;
			}
			done[n] = 1;
			vector<int> f;
			for(int j = 1; j<=sqrt(n); j++){
				if(n%j == 0){
					f.emplace_back(j);
					f.emplace_back(n/j);
				}
			}
			for(int k : f){
				add(rt[k], n);
			}
		}
		else{
			int x, k, s;
			cin >> x >> k >> s;
			if(x%k != 0 || s-x <= 0){
				cout << -1 << "\n";
				continue;
			}
			int ans = query(rt[k], x, s-x, 1);
			cout << (ans == -1 ? -1 : (ans^x)) << "\n";
		}
	}
}