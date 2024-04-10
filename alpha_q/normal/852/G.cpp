#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	node *ch[5];
	int mark = 0; 
	node() {
		for(int i = 0; i < 5; i++) {
			ch[i] = NULL;
		} mark = 0;
	} 
} *root;
void insert(string str) {
	node *curr = root; 
	for(int i = 0; i < str.size(); i++) {
		int c = str[i] - 'a';
		if(curr -> ch[c] == NULL) 
			curr -> ch[c] = new node(); 
		curr = curr -> ch[c];
	} curr -> mark++; 
}
set<node*> st; 
void count(node *curr, string &str, int pos) {
	if(curr == NULL) return;
	if(pos == str.size()) {
		st.insert(curr); return;
	}
	if(str[pos] == '?') {
		int ret = 0; 
		for(char c = 'a'; c <= 'e'; c++) {
			count(curr -> ch[c - 'a'], str, pos+1);
		} count(curr, str, pos + 1);
	} else {
		count(curr -> ch[str[pos] - 'a'], str, pos+1);
	}
}
int main(int argc, char const *argv[]) {
	root = new node(); 
	int n, m; cin >> n >> m; 
	for(int i = 0; i < n; i++) {
		string str; cin >> str; insert(str); 
	}
	for(int i = 0; i < m; i++) {
		string str; cin >> str; 
		st.clear(); 
		count(root, str, 0);
		int ans = 0;
		for(auto it : st) ans += it -> mark;
		cout << ans << endl;
	}

}