#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
pii e[200100];
int en[200100];
int pr[200100];
int *t[4*100100];
int *L[4*100100];
int *val[4*100100];
int tin[100100];
int tout[100100];
int a[100100];
int timer = 0;
int n;
int V[100100];
int lev[100100];
int r;
int M[18*100100];
int M2[18*100100];
int M3[18*100100];
void dfs(int v, int p){
	V[timer] = v;
	lev[v] = lev[p]+1;
	tin[v] = timer++;
	for(int i = en[v]; i != 0; i = pr[i]){
		int to =e[i/2].f ^ e[i/2].s ^ v;
		if(to == p) continue;
		dfs(to, v);
	}
	tout[v] = timer-1;
}
int sz;
inline void build(int v, int l,int r){
	if(l == r){
		int D = V[l];
		t[v] = M2+sz;
		val[v] = M+sz;
		M2[sz] = lev[D];
		M[sz++] = a[D];
		return;
	}
	int mid = (l + r)>>1;
	build(v * 2, l, mid);
	build(v * 2 + 1, mid+1, r);
	int i = 0, j = 0;
	val[v] = M+sz;
	t[v] = M2+sz;
	L[v] = M3+sz;
	while(i < mid - l + 1&& j < r - mid){
		if(t[v*2][i] < t[v*2+1][j]){
			M[sz] = val[v*2][i];
			M2[sz] = t[v*2][i];
			i++;
			M3[sz++] = i;
		}
		else{
			M[sz] = val[v*2+1][j];
			M2[sz] = t[v*2+1][j];
			j++;
			M3[sz++] = i;
		}
	}
	while(i < mid - l + 1){
		M[sz] = val[v*2][i];
		M2[sz] = t[v*2][i];
		i++;
		M3[sz++] = i;
	}
	while(j < r - mid){
		M[sz] = val[v*2+1][j];
		M2[sz] = t[v*2+1][j];
		j++;
		M3[sz++] = i;
	}
	for(int i = 1; i < r-l+1; i++){
		val[v][i] = min(val[v][i], val[v][i-1]);
	}
}
inline int get(int v, int tl, int tr, int l, int r, int pos){
	if(l > tr || tl > r || pos == 0) return inf;
	if(l <= tl && tr <= r){
		return val[v][pos-1];
	}
	int mid= (tl + tr)>>1;
	return min(get(v * 2, tl, mid, l, r, L[v][pos-1]), get(v*2+1, mid+1, tr, l, r, pos - L[v][pos-1]));
}

inline int nextInt() {
	register int n = 0;
	register char c = getchar();
	while(c == ' ' || c == '\t' || c == '\n'){
		c = getchar();
	}
	while(!(c == ' ' || c == '\t' || c == '\n' || c==EOF)){
		n = n * 10 + c - '0';
		c = getchar();
	}
	return n;
}
void out(int x){
	if(x >= 10){
		out(x/10);
	}
	putchar('0' + x % 10);
}
void solve(){
	n = nextInt();
	r = nextInt();

	for(int i = 1; i <= n; i++){
		a[i] = nextInt();
	}

	for(int i = 1, x, y; i < n; i++){
		x = nextInt();
		y = nextInt();
		e[i] = mp(x, y);
		pr[2*i] = en[x];
		en[x] = 2*i;
		pr[2*i+1] = en[y];
		en[y] = 2 * i + 1;
	}
	dfs(r, 0);
	build(1, 0, n-1);
	int m;
	cin >> m;
	int last = 0;
	for(int i  = 0, x, y; i < m; i++){
		x = nextInt();
		y = nextInt();
		x = (x + last) % n + 1;
		y = (y + last) % n;
		int pos = upper_bound(t[1], t[1] + n, lev[x] + y) - t[1];
		last = get(1, 0, n-1, tin[x], tout[x], pos);
		out(last);
		putchar('\n');
	}
	cerr << (clock()*1.0)/CLOCKS_PER_SEC<<endl;
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a2.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}