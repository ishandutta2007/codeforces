
// Problem : F. Julia the snail
// Contest : Codeforces - Tinkoff Challenge - Elimination Round
// URL : https://codeforces.com/contest/793/problem/F
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q, M;
const int B = 950;
int st[100005];
int ans[100005];
vector<int> cache[100005];
vector<int> graph[100005];
int bit[100005];

void upd(int n, int v){
	while(n <= N){
		bit[n] = max(bit[n], v);
		n += n&-n;
	}
}

int query(int n){
	int ret = n;
	while(n){
		ret = max(ret, bit[n]);
		n -= n&-n;
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		st[b] = a;
		graph[a].push_back(b);
	}
	for(int i = B; i<=N; i+=B){
		cache[i].resize(N+1);
		fill(bit+1, bit+1+N, 0);
		for(int j = i; j; j--){
			int bst = j;
			for(int e : graph[j]){
				if(e <= i){
					bst = max(bst, e);
				}
			}
			bst = query(bst);
			cache[i][j] = bst;
			upd(j, bst);
		}
	}
	cin >> Q;
	while(Q--){
		int l, r;
		cin >> l >> r;
		int blk = r/B*B;
		int bst = l;
		if(blk >= l){
			bst = cache[blk][l];
		}
		else{
			blk = l;
		}
		for(int i = blk; i<=r; i++){
			if(st[i] <= bst && st[i] >= l){
				bst = i;
			}
		}
		cout << bst << "\n";
	}
}