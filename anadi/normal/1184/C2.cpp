#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 3e5 + 7;
const int M = 2e6 + 7;
const int T = 1 << 22;

int n, r;
PII in[N];
int add[T + T + 7];
int tree[T + T + 7];

void Add(int from, int to, int val, int s = 1, int e = T, int cur = 1){
	if(from <= s && e <= to){
		add[cur] += val;
		tree[cur] += val;
		return;
	}
	
	int mid = (s + e) >> 1;
	if(from <= mid)
		Add(from, to, val, s, mid, cur + cur);
	if(mid < to)
		Add(from, to, val, mid + 1, e, cur + cur + 1);

	tree[cur] = max(tree[cur + cur], tree[cur + cur + 1]) + add[cur];
}

int main(){
	scanf("%d %d", &n, &r);
	for(int i = 1; i <= n; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		in[i] = {x + y, x - y};
	}
	
	int wsk = 1;
	sort(in + 1, in + n + 1);
	
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		while(in[wsk].st + 2 * r < in[i].st){
			Add(max(in[wsk].nd - r + M, 1), min(in[wsk].nd + r + M, 2 * M), -1);
			++wsk;
		}

		Add(max(in[i].nd - r + M, 1), min(in[i].nd + r + M, 2 * M), 1);
		ans = max(ans, tree[1]);
	}
	
	printf("%d\n", ans);
	return 0;
}