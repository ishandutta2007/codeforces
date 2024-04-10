#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int T = 1 << 18;

const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, w;
int val[N];
int from[N], to[N];
vector <int> in[N];

LL ans;
PII order[N];

int pt[N];
vector <int> tree[N];

int ask(int t, int s, int e){
	int ret = -MX;
	s += pt[t], e += pt[t];

	while(s <= e){
		if(s & 1)
			ret = max(ret, tree[t][s]);
		if(!(e & 1))
			ret = max(ret, tree[t][e]);
		
		s = (s + 1) >> 1;
		e = (e - 1) >> 1;
	}
	
	return ret;
}

int main(){
	scanf("%d %d", &n, &w);
	for(int i = 1; i <= n; ++i){
		int l;
		scanf("%d", &l);
		
		in[i].resize(l + 2, 0);
		for(int j = 1; j <= l; ++j)
			scanf("%d", &in[i][j]);
		
		pt[i] = 1;
		while(pt[i] <= l + 1)
			pt[i] *= 2;
		
		tree[i].resize(pt[i] + pt[i], 0);
		for(int j = 0; j <= l + 1; ++j)
			tree[i][j + pt[i]] = in[i][j];
		
		for(int j = pt[i] - 1; j >= 1; --j)
			tree[i][j] = max(tree[i][j + j], tree[i][j + j + 1]);
		order[i] = {l, i};
	}
	
	sort(order + 1, order + n + 1);
	for(int i = 1; i <= n; ++i){
		to[i] = 1;
		from[i] = in[i].size() < (w + 2) ? 0 : 1;

		val[i] = ask(i, from[i], to[i]);
		ans += val[i];
	}
	
	for(int i = 1; i < w; ++i){
		printf("%lld ", ans);
		for(int j = n; j >= 1; --j){
			int l = order[j].st, id = order[j].nd;
			if(i + l < w && i > l)
				break;
			
			ans -= val[id];
			if(i + l >= w)
				from[id]++;
			if(i <= l)
				++to[id];
			
			val[id] = ask(id, from[id], to[id]);
			ans += val[id];
//			printf("%d -> %d %d\n", id, from[id], to[id]);
		}
		
//		puts("KONIEC");
	}

	printf("%lld\n", ans);
	return 0;
}