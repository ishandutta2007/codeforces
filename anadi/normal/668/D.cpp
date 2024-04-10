#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1e5 + 7;
const int T = 1 << 30;

struct tree{
	int add = 0;
	tree *left = nullptr, *right = nullptr;
};

int n;
int cnt;
tree* root[N];
map <int, int> M;

void add(tree *cur, int p, int k, int v, int from = 1, int to = T){
	if(p <= from && to <= k){
		cur -> add += v;
		return;
	}
	
	int m = (from + to) / 2;
	if(p <= m){
		if(cur -> left == nullptr)
			cur -> left = new tree();
		add(cur -> left, p, k, v, from, m);
	}
	
	if(m < k){
		if(cur -> right == nullptr)
			cur -> right = new tree();
		add(cur -> right, p, k, v, m + 1, to);
	}
}

int ask(tree *cur, int p, int from = 1, int to = T){
	if(cur == nullptr)
		return 0;
	
	if(from == to)
		return cur -> add;
	
	int m = (from + to) / 2;
	if(p <= m)
		return ask(cur -> left, p, from, m) + cur -> add;
	return ask(cur -> right, p, m + 1, to) + cur -> add;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int t, m, v;
		scanf("%d %d %d", &t, &m, &v);
		
		if(t == 1 || t == 2){
			if(!M.count(v)){
				M[v] = ++cnt;
				root[cnt] = new tree();
			}

			v = M[v];
			add(root[v], m, T, t == 1 ? 1 : -1);
		}
		else{
			if(!M.count(v))
				puts("0");
			else
				printf("%d\n", ask(root[M[v]], m));
		}
	}

	return 0;
}