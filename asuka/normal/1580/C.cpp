#include<bits/stdc++.h>
#define ll long long
#define N 200015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int B = 450;
int n, m, x[N], y[N], val[B + 10][B + 10], pre[N << 1], lst[N];
void inc(int cpos, int pos, int a, int b, int v) {
	int X = pos % (a + b), Y = (X + a - 1) % (a + b);
	// if(pos == 3) printf("(%d %d)\n", X, Y);
	if(a + b <= B) {
		if(X <= Y) rep(i, X, Y) val[a + b][i] += v;
		else {
			rep(i, 0, Y) val[a + b][i] += v;
			rep(i, X, a + b - 1) val[a + b][i] += v;
		}		
	} else {
		for(int i = pos; i <= m; i += (a + b)) {
			if(i <= cpos && cpos <= i + a - 1 && v == -1) pre[cpos + 1]--;
			pre[i] += v;
			if(i + a <= m) pre[i + a] -= v;
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d%d", &x[i], &y[i]);
	int cur = 0, tot = 0;
	rep(i, 1, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(a == 1) {
			tot++;
			inc(-1, i, x[b], y[b], 1);
			lst[b] = i;
		} else {
			tot--;
			inc(i - 1, lst[b], x[b], y[b], -1);
		}
		cur += pre[i];
		int res = cur;
		rep(j, 1, B) res += val[j][i % j];
		printf("%d\n", tot - res);
	}
	return 0;
}