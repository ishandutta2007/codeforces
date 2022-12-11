
// Problem : H. XOR and Distance
// Contest : Codeforces - Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1553/problem/H
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int mn, mx;
	int val, cnt, dep;
	Node * lft, * rht;

	Node(int d){
		lft = rht = NULL;
		dep = d;
		val = INT_MAX / 2;
		cnt = 0;
		mn = mx = 0;
	}
};

int N, D;
Node * rt;
int ans[1 << 20];

Node * build(int h){
	Node * n = new Node(h);
	if(h == -1){
		return n;
	}
	n->lft = build(h-1);
	n->rht = build(h-1);
	return n;
}

void pu(Node * n){
	assert(n->dep != -1);
	n->cnt = n->lft->cnt + n->rht->cnt;
	n->val = min(n->lft->val, n->rht->val);
	if(n->lft->cnt){
		n->mn = n->lft->mn;
	}
	else if(n->rht->cnt){
		n->mn = n->rht->mn ^ (1 << n->dep);
	}
	if(n->rht->cnt){
		n->mx = n->rht->mx ^ (1 << n->dep);
	}
	else if(n->lft->cnt){
		n->mx = n->lft->mx;
	}
	if(n->lft->cnt && n->rht->cnt){
		//cout << "special: " << (n->rht->mn^(1<< n->dep)) - n->lft->mx << "\n";
		n->val = min((n->rht->mn^(1<< n->dep)) - n->lft->mx, n->val);
	}
}

void upd(int v, Node * n){
	if(n->dep == -1){
		n->cnt++;
		return;
	}
	if(v&(1<<n->dep)){
		upd(v, n->rht);
	}
	else{
		upd(v, n->lft);
	}
	pu(n);
}

void swapping(int h, Node * n){
	if(n->dep == h){
		swap(n->lft, n->rht);
	}
	else{
		swapping(h, n->lft);
		swapping(h, n->rht);
	}
	pu(n);
	//cout << "upd: " << n->val << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> D;
	rt = build(D-1);
	for(int i = 1; i <= N; i++){
		int n;
		cin >> n;
		upd(n, rt);
	}
	vector<int> graycode = {0};
	for(int b = D - 1; b >= 0; b--){
		for(int i = graycode.size() - 1; i >= 0; i--){
			graycode.emplace_back(graycode[i]^(1<<b));
		}
	}
	for(int i = 0; i < graycode.size(); i++){
		if(i){
			int x = (graycode[i] ^ graycode[i-1]);
			int v = __builtin_ctz(x);
			swapping(v, rt);
		}
		ans[graycode[i]] = rt->val;
	}
	for(int k = 0; k < (1 << D); k++){
		cout << ans[k] << " ";
	}
}