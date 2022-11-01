#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
const int MAGIC = 320;

int tag[325];
int n, q, a[100005], pre[100005];
int geta(int x)
{
	return max(a[x] - tag[x / MAGIC], 1);
}
void regen(int x)
{
	for(int i = max(x * MAGIC, 1); i <= n && i < (x + 1) * MAGIC; i ++) {
		int ca = max(a[i] - tag[x], 1);
		pre[i] = ca == 1 || ca / MAGIC < x ? ca : pre[ca];
	}
}

int main()
{
	scanf("%d%d", &n, &q);
	a[1] = 1;
	for(int i = 2; i <= n; i ++) scanf("%d", &a[i]);
	rep1(i, n) pre[i] = a[i] == 1 || a[i] / MAGIC < i / MAGIC ? a[i] : pre[a[i]];
	
	rep(i, q) {
		int tp;
		scanf("%d", &tp);
		if(tp == 1) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			int lb = l / MAGIC, rb = r / MAGIC;
			if(lb == rb) {
				for(int i = l; i <= r; i ++) a[i] = max(a[i] - x, 1);
				regen(lb); 
			} else {
				for(int i = l; i < (lb + 1) * MAGIC; i ++) a[i] = max(a[i] - x, 1);
				for(int i = rb * MAGIC; i <= r; i ++) a[i] = max(a[i] - x, 1);
				for(int i = lb + 1; i < rb; i ++) tag[i] += x;
				regen(lb); regen(rb);
				for(int i = lb + 1; i < rb; i ++) {
					if(tag[i] <= MAGIC + x) regen(i);
					tag[i] = min(tag[i], n + MAGIC);
				}
			}
		} else {
			int u, v;
			scanf("%d%d", &u, &v);
			for(int i = n / MAGIC; i >= 0; i --) {
				int nu = u / MAGIC >= i ? min(pre[u], geta(u)) : u, nv = v / MAGIC >= i ? min(pre[v], geta(v)) : v;
				if(nu == nv) {
					while(u != v) {
						if(u > v) u = max(geta(u), 1);
						else v = max(geta(v), 1);
					}
					printf("%d\n", u);
					break;
				}
				u = nu; v = nv;
			}
		}
	}
	return 0;
}