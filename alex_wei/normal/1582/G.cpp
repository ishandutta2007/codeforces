#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using db = double;
using ld = long double;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
using vint = vector <int>;
using vpii = vector <pii>;

#define fi first
#define se second
#define pb push_back
#define mem(x, v, s) memset(x, v, sizeof(x[0]) * (s))
#define cpy(x, y, s) memcpy(x, y, sizeof(x[0]) * (s))
#define FileI(x) freopen(x, "r", stdin)
#define FileO(x) freopen(x, "w", stdout)
bool Mbe;

// IO template
#define gc (p1 == p2 && (p2 = (p1 = buf) + \
	fread(buf, 1, 1 << 22, stdin), p1 == p2) ? EOF : *p1++)
#define pc(x) (*O++ = x)
#define flush() fwrite(obuf, 1, O - obuf, stdout) 
char buf[1 << 22], *p1 = buf, *p2 = buf, obuf[1 << 25], *O = obuf;
int read() {
	int x = 0, sgn = 0; char s = gc;
	while(!isdigit(s)) sgn |= s == '-', s = gc;
	while(isdigit(s)) x = (x << 1) + (x << 3) + s - '0', s = gc;
	return sgn ? -x : x;
}
void recprint(int x) {if(x > 9) recprint(x / 10); pc(x % 10 + '0');}
void print(int x) {if(x < 0) x = -x, pc('-'); recprint(x);}

template <class T1, class T2> void cmin(T1 &x, T2 y) {x = x < y ? x : y;}
template <class T1, class T2> void cmax(T1 &x, T2 y) {x = x > y ? x : y;}

const int N = 1e6 + 5;
int vis[N], mp[N], pr[N], cnt;
void sieve() {
	for(int i = 2; i < N; i++) {
		if(!vis[i]) mp[i] = pr[++cnt] = i;
		for(int j = 1; j <= cnt && i * pr[j] < N; j++) {
			vis[i * pr[j]] = 1, mp[i * pr[j]] = pr[j];
			if(i % pr[j] == 0) break;
		}
	}
}

int n, pre[N], a[N];
vint buc[N];

int top, stc[N], w[N];
ll ans;

bool Med;
int main() {
	fprintf(stderr, "%.3lf\n", (&Med - &Mbe) / 1048576.0);
	cin >> n, sieve();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) {
		char s = gc;
		while(s != '*' && s != '/') s = gc;
		if(s == '*') {
			while(a[i] > 1) {
				int p = mp[a[i]];
				buc[p].pb(i), a[i] /= p;
			} pre[i] = i;
		} else {
			pre[i] = i;
			while(a[i] > 1) {
				int p = mp[a[i]];
				if(buc[p].empty()) pre[i] = -1;
				else cmin(pre[i], buc[p].back()), buc[p].pop_back();
				a[i] /= p;
			}
		}
	}
	for(int i = n; i; i--) {
		int nw = 1;
		while(top && pre[i] <= stc[top]) nw += w[top], top--;
		stc[++top] = pre[i], w[top] = nw;
		if(pre[i] == i) ans += nw;
	} cout << ans << endl;
	return cerr << "Time : " << clock() << endl, flush(), 0;
}