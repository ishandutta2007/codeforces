#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 2e5;

int mn[N << 2], mx[N << 2];
int n, a[N], b[N], up[N];
ll ans[N];
bool was[N];
void build(int v, int tl, int tr){
	if(tl == tr){
		mn[v] = mx[v] = a[tl];
		return; 
	}
	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);          
	mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
	mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
}              
int get1(int v, int tl, int tr, int l, int k){
	if(tr < l || mx[v] < k)
		return -1;
	if(tl == tr)
		return tl;
	int tm = (tl + tr) >> 1;
	int res = get1(v << 1, tl, tm, l, k);
	if(res == -1)
		res = get1(v << 1 | 1, tm + 1, tr, l, k);
	return res; 
}
int get2(int v, int tl, int tr, int l, int k){
	if(tr < l || mn[v] > k)
		return - 1;
	if(tl == tr)
		return tl;
	int tm = (tl + tr) >> 1;
	int res = get2(v << 1, tl, tm, l, k);
	if(res == -1)
		res = get2(v << 1 | 1, tm + 1, tr, l, k);
	return res; 
}
ll get(int v){
	if(was[v])
		return ans[v];
	was[v] = 1;
	ans[v] = inf;
	if(up[v] == -1)
		ans[v] = b[v];
	else
		ans[v] = b[v] + get(up[v]);
	return ans[v];
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)
		a[i + n] = a[i];
	build(1, 0, n + n);
	for(int i = 0; i < n; i++){
		int p = get1(1, 0, n + n, i + 1, a[i]);
		int q = get2(1, 0, n + n, i + 1, (a[i] - 1) / 2);		
		if(q < p)
			up[i] = -1, b[i] = q - i;
		else
			up[i] = p % n, b[i] = p - i;			
	}
	for(int i = 0; i < n; i++)
		printf("%d ", (get(i) < inf ? get(i) : -1));
	return 0;
}