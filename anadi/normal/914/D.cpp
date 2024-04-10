#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int T = 1 << 19;

const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, m;
int tree[T + T + 7];

bool ask(int p, int k, int v){
	vector <int> bad;
	p += T, k += T;
	
	while(p < k){
		if((p & 1) && tree[p]%v != 0)
			bad.pb(p);
		if(!(k & 1) && tree[k]%v != 0)
			bad.pb(k);
		
		p = (p + 1) >> 1;
		k = (k - 1) >> 1;
	}
	
	if(p == k && tree[p]%v != 0)
		bad.pb(p);
	
	if(bad.size() > 1)
		return false;
	if(bad.size() == 0)
		return true;
	
	int cur = bad[0];
	while(cur < T){
		if(tree[cur + cur]%v != 0 && tree[cur + cur + 1]%v != 0)
			return false;

		cur += cur;
		if(tree[cur]%v == 0)
			cur = cur + 1;
	}
	
	return true;
}

void add(int x, int v){
	x += T;
	tree[x] = v;
	
	while(x > 1){
		x >>= 1;
		tree[x] = __gcd(tree[x + x], tree[x + x + 1]);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &tree[i + T]);
	for(int i = T - 1; i >= 1; --i)
		tree[i] = __gcd(tree[i + i], tree[i + i + 1]);
	
	scanf("%d", &m);
	while(m--){
		int t, l, r, x;
		scanf("%d", &t);
		if(t == 1){
			scanf("%d %d %d", &l, &r, &x);
			if(ask(l - 1, r - 1, x))
				puts("YES");
			else
				puts("NO");
		}
		else{
			scanf("%d %d", &l, &x);
			add(l - 1, x);
		}
	}

	return 0;
}