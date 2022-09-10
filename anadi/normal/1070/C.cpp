#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1e6 + 7;
const int T = 1 << 18;

int n, k, m;
pair <PII, PII> type[T];

vector <int> req[N];
LL tree[T + T + 7][2];

void add(int u, int t, LL v){
	u += T;
	while(u){
		tree[u][t] += v;
		u >>= 1;
	}
}

LL ask(){
	if(tree[1][0] <= k)
		return tree[1][1];
	
	int cur = 1, need = k; LL ret = 0LL;
	while(cur < T){
		cur += cur;
		if(tree[cur][0] < need){
			need -= tree[cur][0];
			ret += tree[cur][1];
			++cur;
		}
	}
	
	cur -= T;
	ret += 1LL * type[cur].st.st * need;
	return ret;
}

int main(){
	scanf("%d %d %d", &n, &k, &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d %d", &type[i].nd.st, &type[i].nd.nd);
		scanf("%d %d", &type[i].st.nd, &type[i].st.st);
	}
	
	sort(type + 1, type + m + 1);
	for(int i = 1; i <= m; ++i){
		req[type[i].nd.st].push_back(i);
		req[type[i].nd.nd + 1].push_back(-i);
	}
	
	LL res = 0LL;
	for(int i = 1; i <= n; ++i){
		for(auto v: req[i]){
			if(v < 0){
				v *= -1;
				add(v, 0, -type[v].st.nd);
				add(v, 1, -1LL * type[v].st.st * type[v].st.nd);
			}
			else{
				add(v, 0, type[v].st.nd);
				add(v, 1, 1LL * type[v].st.st * type[v].st.nd);
			}
		}
		
		res += ask();
	}
	
	printf("%lld\n", res);
	return 0;
}