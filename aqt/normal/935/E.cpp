
// Problem : E. Fafa and Ancient Mathematics
// Contest : Codeforces - Codeforces Round #465 (Div. 2)
// URL : https://codeforces.com/contest/935/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct node{
	int mn[105], mx[105];
	bool leaf;
	node * c[2];
	node(){
		c[0] = c[1] = NULL;
		leaf = 0;
		fill(mn, mn+105, INT_MAX);
		fill(mx, mx+105, INT_MIN);
	}
};

string s;
node * rt;
int P, M;
stack<node*> stk;

void dfs(node * n){
	if(n->leaf){
		return;
	}
	dfs(n->c[0]);
	dfs(n->c[1]);
	if(P <= M){
		for(int i = 0; i<=P; i++){
			for(int j = 0; j<=i; j++){
				if(n->c[0]->mx[j] != INT_MIN && n->c[1]->mn[i-j] != INT_MAX){
					n->mx[i] = max(n->mx[i], n->c[0]->mx[j] - n->c[1]->mn[i-j]);
				}
				if(n->c[0]->mn[j] != INT_MAX && n->c[1]->mx[i-j] != INT_MIN){
					n->mn[i] = min(n->mn[i], n->c[0]->mn[j] - n->c[1]->mx[i-j]);
				}
			}
			for(int j = 0; j<i; j++){
				if(n->c[0]->mx[j] != INT_MIN && n->c[1]->mx[i-j-1] != INT_MIN){
					n->mx[i] = max(n->mx[i], n->c[0]->mx[j] + n->c[1]->mx[i-j-1]);
				}
				if(n->c[0]->mn[j] != INT_MAX && n->c[1]->mn[i-j-1] != INT_MAX){
					n->mn[i] = min(n->mn[i], n->c[0]->mn[j] + n->c[1]->mn[i-j-1]);
				}
			}
		}
	}
	else{
		for(int i = 0; i<=M; i++){
			for(int j = 0; j<=i; j++){
				if(n->c[0]->mx[j] != INT_MIN && n->c[1]->mx[i-j] != INT_MIN){
					n->mx[i] = max(n->mx[i], n->c[0]->mx[j] + n->c[1]->mx[i-j]);
				}
				if(n->c[0]->mn[j] != INT_MAX && n->c[1]->mn[i-j] != INT_MAX){
					n->mn[i] = min(n->mn[i], n->c[0]->mn[j] + n->c[1]->mn[i-j]);
				}				
			}
			for(int j = 0; j<i; j++){
				if(n->c[0]->mx[j] != INT_MIN && n->c[1]->mn[i-j-1] != INT_MAX){
					n->mx[i] = max(n->mx[i], n->c[0]->mx[j] - n->c[1]->mn[i-j-1]);
				}
				if(n->c[0]->mn[j] != INT_MAX && n->c[1]->mx[i-j-1] != INT_MIN){
					n->mn[i] = min(n->mn[i], n->c[0]->mn[j] - n->c[1]->mx[i-j-1]);
				}				
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s >> P >> M;
	for(char c : s){
		if(c == '('){
			stk.push(new node());
		}
		else if(c >= '0' && c <= '9'){
			node * n = new node();
			n->leaf = 1;
			n->mn[0] = n->mx[0] = c-'0';
			while(stk.size()){
				if(stk.top()->c[0]){
					node * p = stk.top();
					stk.pop();
					p->c[1] = n;
					swap(n, p);
				}
				else{
					stk.top()->c[0] = n;
					break;
				}
			}
			if(stk.empty()){
				rt = n;
			}
		}
	}
	dfs(rt);
	cout << rt->mx[min(P, M)] << "\n";
}