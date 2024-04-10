#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

char s[N];
int n, q, t[N << 2];
void upd(int v, int tl, int tr, int pos, int x){
	if(tl == tr){
		t[v] = (1 << (x - 'a'));
		return;
	}
	int tm = (tl + tr) >> 1;
	if(pos <= tm)
    	upd(v << 1, tl, tm, pos, x);
	else
		upd(v << 1 | 1, tm + 1, tr, pos, x);
	t[v] = (t[v << 1] | t[v << 1 | 1]);
}
int get(int v, int tl, int tr, int l, int r){
	if(r < tl || tr < l || l > r)
		return 0;
	if(l <= tl && tr <= r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return (get(v << 1, tl, tm, l, r) | get(v << 1| 1, tm + 1, tr, l, r));
}
int cnt(int x){
	if(x == 0)
		return 0;
	return (x & 1) + cnt(x / 2);
}
int main()
{
	scanf("%s", &s);
	n = strlen(s);
	for(int i = 1; i <= n; i++)
		upd(1, 1, n, i, s[i - 1]);
	scanf("%d", &q);
	while(q--){
		int t;
		scanf("%d", &t);
		if(t == 1){
			int p;
			char c;
			scanf("%d %c", &p, &c);
			upd(1, 1, n, p, c);
        }else{
        	int l, r;
        	scanf("%d%d", &l, &r);
        	printf("%d\n", cnt(get(1, 1, n, l, r)));
        }	
	}
	return 0;
}