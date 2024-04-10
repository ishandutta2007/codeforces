#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;
const int T = 3 * N + 9;

int n, K;
int val[N];
int tree[T];

void change(int x){
	x += K;
	tree[x] = 0;

	while(x > 1){
		x /= 2;
		tree[x] = max(tree[x + x], tree[x + x + 1]);
	}
}

int find(int val){
	int cur = 1;
	while(cur <= K){
		if(tree[cur + cur] > val)
			cur = cur + cur;
		else
			cur = cur + cur + 1;
	}
	
	return cur - K;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &val[i]);
	
	K = 1;
	while(K < n)
		K *= 2;
	--K;
	
	for(int i = 1; i <= n; ++i)
		tree[i + K] = val[i];
	for(int i = K; i >= 1; --i)
		tree[i] = max(tree[i + i], tree[i + i + 1]);
	
	while(tree[1] != 0){
		int last = 0;
		while(tree[1] > last){
			int pos = find(last);
			printf("%d ", val[pos]);
			last = val[pos];
			change(pos);
		}
		
		puts("");
	}
	
	return 0;
}