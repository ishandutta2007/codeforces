#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PLL pair <LL, LL>
#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

const int mxn = 1e6 + 7;
const int mxt = (1 << 21) + 9;

int n, m;
int K = 1;
map <int, int> M;
int tree[mxt];
int ciag[mxn];
int ans[mxn];
pair <PII, int> req[mxn];

int wynik(int a, int b){
	a += K;
	b += K;

	int res = 0;
	while(a < b){
		if(a%2 == 1)	res ^= tree[a];
		if(b%2 == 0)	res ^= tree[b];
		a = (a + 1) / 2;
		b = (b - 1) / 2;
	}
	
	if(a == b)
		return res ^ tree[a];
	return res;
}

void add(int a, int b, int v){
	a += K;
	b += K;
	
	while(a < b){
		if(a%2 == 1)	tree[a] ^= v;
		if(b%2 == 0)	tree[b] ^= v;
		a = (a + 1) / 2;
		b = (b - 1) / 2;
	}
	
	if(a == b)
		tree[a] ^= v;
}

int value(int x){
	x += K;
	int res = 0;
	while(x > 0){
		res ^= tree[x];
		x /= 2;
	}
	
	return res;
}

int main(){
	scanf("%d", &n);
	while(K < n)
		K *= 2;
	--K;
	
	for(int i = 1; i <= n; ++i){
		scanf("%d", &ciag[i]);
		tree[i + K] = ciag[i];
	}
	
	for(int i = K; i >= 1; --i)
		tree[i] = tree[2 * i] ^ tree[2 * i + 1];
	
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d %d", &req[i].st.nd, &req[i].st.st);
		ans[i] = wynik(req[i].st.nd, req[i].st.st);
		req[i].nd = i;
	}
	sort(req + 1, req + m + 1);
	
	for(int i = 1; i <= 2 * K + 1; ++i)
		tree[i] = 0;
	
	int j = 1;
	for(int i = 1; i <= n; ++i){
		add(M[ciag[i]] + 1, i, ciag[i]);
		while(j <= m && req[j].st.st <= i){
			ans[req[j].nd] ^= value(req[j].st.nd);
			++j;
		}

		M[ciag[i]] = i;
	}

	for(int i = 1; i <= m; ++i)
		printf("%d\n", ans[i]);
	return 0;
}