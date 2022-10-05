#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)4e6 + 123;
 
int t, n, k, m, ans[N], a[N];
bool g(int v){
	if(!a[v << 1] && !a[v << 1 | 1])
		return !(v < (1 << k));		
	if(a[v << 1] > a[v << 1 | 1])
		return g(v << 1);
	else
		return g(v << 1 | 1);
}
void h(int v){
	if(!a[v << 1] && !a[v << 1 | 1]){
		a[v] = 0;
		return;
	}
	if(a[v << 1] > a[v << 1 | 1]){
		a[v] = a[v << 1];
		h(v << 1);
	}else{
		a[v] = a[v << 1 | 1];
		h(v << 1 | 1);
	}
}
void f(int v){
	if(a[v] == 0)
		return;
	if(g(v)){
	 	ans[m++] = v;
	 	h(v);
	 	f(v);
		return;
	}
	f(v << 1);
	f(v << 1 | 1);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1; i < (1 << n); i++)
			scanf("%d", &a[i]);
		f(1);
		ll s = 0;
		for(int i = 1; i < (1 << k); i++)
			s += a[i];
		printf("%lld\n", s);
		for(int i = 0; i < m; i++)
			printf("%d ", ans[i]);
		printf("\n");
		m = 0;
		for(int i = 1; i < (1 << n); i++)
			a[i] = 0;
	}
}