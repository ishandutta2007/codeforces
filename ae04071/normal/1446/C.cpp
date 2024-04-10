#include <bits/stdc++.h>
using namespace std;

struct node {
	node *nxt[2];
	int cnt;

	node() {
		nxt[0] = nxt[1] = nullptr;
		cnt = 0;
	}
}*root;

void add(node *cur,int val,int s) {
	cur->cnt++;

	if(s==-1) return;
	int n = val>>s&1;
	if(!cur->nxt[n]) cur->nxt[n] = new node();
	add(cur->nxt[n], val, s-1);
}
int get(node *cur, int s) {
	if(s==-1) return 0;

	if(!cur->nxt[1]) return get(cur->nxt[0], s-1);
	else if(!cur->nxt[0]) return get(cur->nxt[1], s-1);
	else {
		return min(cur->nxt[0]->cnt-1 + get(cur->nxt[1], s-1), cur->nxt[1]->cnt-1 + get(cur->nxt[0], s-1));
	}
}

int main() {
	int n;
	scanf("%d",&n);
	
	root = new node();
	for(int i=0,v;i<n;i++) {
		scanf("%d",&v);
		add(root, v, 30);
	}
	
	printf("%d\n",get(root, 30));
	
	return 0;
}