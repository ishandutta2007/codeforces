#include <bits/stdc++.h>
using namespace std;

bool Mbe;
#define ll long long
inline ll read() {
	ll x = 0; char s = getchar();
	while(!isdigit(s)) s = getchar();
	while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
	return x;
}
void print(ll x) {
	if(x >= 10) print(x / 10);
	putchar(x % 10 + '0');
}

const int N = 2e5 + 5;

ll n, tp, a[N];
namespace TP1 {
	ll ans[N];
	void calc(ll *a) {
		for(int i = 1; i <= n; i++) ans[i] = 0;
		for(ll i = n, last = 0; i; i--) if(a[i]) ans[i] = last += i;
		for(int i = 1; i <= n && !ans[1]; i++) if(a[i])
			for(int j = 1; j < i; j++) ans[j] = ans[i] + 1;
		if(!ans[1]) for(int i = 1; i <= n; i++) ans[i] = 1;
		for(int i = 1; i <= n; i++) if(!ans[i]) ans[i] = ans[i - 1] + a[i - 1];
	}
	void solve(ll *a) {
		calc(a);
		for(int i = 1; i <= n; i++) print(ans[i]), putchar(' ');
		putchar('\n');
	}
}

namespace BF {
	void solve() {
		for(int i = 0; i < 1 << n; i++) {
			static ll t[N];
			for(int j = 1; j <= n; j++) t[j] = i >> j - 1 & 1;
			TP1 :: calc(t);
			bool ok = 1;
			for(int j = 1; j <= n; j++)
				ok &= !a[j] || a[j] == TP1 :: ans[j];
			if(ok) {
				for(int j = 1; j <= n; j++) putchar((i >> j - 1 & 1) + '0'), putchar(' ');
				putchar('\n'); break;
			}
		}
	}
}

namespace TP2 {
	ll sum(ll l, ll r) {return (l + r) * (r - l + 1) / 2;}
	bool check(int l, int r, int d, ll need) { // [l, r]  d  need 
		ll low = sum(l, l + d - 1), high = sum(r - d + 1, r);
		return low <= need && need <= high;
	}
	int check(int lv, int rv, ll need) {
		int l = 0, r = rv - lv + 1;
		while(l < r) {
			int m = l + r >> 1;
			if(sum(rv - m + 1, rv) >= need) r = m;
			else l = m + 1;
		} return check(lv, rv, l, need) ? l : -1;
	}
	vector <int> calc(int lv, int rv, ll need) {
		int rest = check(lv, rv, need);
		assert(rest != -1);
		vector <int> ret;
		for(int i = lv; i <= rv && rest; i++)
			if(check(i + 1, rv, rest - 1, need - i))
				ret.push_back(i), rest--, need -= i;
		return ret;
	}
	
	bool ask(int i, int j, int lv, ll vi, ll vj) {
		ll need = vi - i - vj;
//		cerr << i << " " << j << " " << "need " << need << endl;
		if(need < 0) return 0;
		return check(lv, j - 1, need) != -1;
	}
	
	
	ll premax[N], ans[N], tr[N], rlim[N], val[N];
	map <ll, int> pos;
	void fillans(int p) {
//		cerr << p << " " << tr[p] << " " << val[p] << endl;
		if(p > n) return;
		ans[p] = 1;
		vector <int> res = calc(rlim[p] + 1, tr[p] - 1, val[p] - p - val[tr[p]]);
		for(int it : res) ans[it] = 1;
		fillans(tr[p]);
	}
	
	void WHAT_THE_FUCK() {
		memset(ans, -1, sizeof(ans));
		memcpy(val, a, sizeof(val));
		
		for(int i = 1; i <= n; i++) premax[i] = max(a[i], premax[i - 1]);
		for(int i = 1; i <= n && a[i] <= 1; i++)
			if(n == i) {for(int i = 1; i <= n; i++) ans[i] = 0; return;}
		pos[0] = n + 1;
		
		for(ll i = n, las = 0; i; i--) {
			if(a[i]) {
				int l = i, havemin = 0;
				while(l > 1 && a[l - 1] <= a[i]) havemin |= a[--l] < a[i];
				if(!havemin && premax[i] <= a[i] + 1) l = 1;
				int r = l;
				while(!a[r]) r++;
				
				
				
				int num = 0;
				for(int j = r; j <= i; j++) num += a[i] == a[r];
				
//				cerr << "---------------------------- " << l << " " << r << endl;
				
				if(l == 1) {
//					cerr << "??\n";
					if(a[r] < a[i]) {
						if(pos.find(las) != pos.end()) {
							int p = pos[las];
							if(ask(r, p, i + 1, a[r], las)) tr[r] = p;
						}
						if(pos.find(las - 1) != pos.end()) {
							int p = pos[las - 1];
							if(ask(r, p, i + 1, a[r], las - 1)) tr[r] = p;
						}
						assert(tr[r]);
						pos[a[r]] = r, rlim[r] = i, fillans(r);
						return;
					}
					
//					cerr << "??\n";
					if(num == 1) {
						if(pos.find(las) != pos.end()) {
							int p = pos[las];
							if(ask(r, p, i + 1, a[r], las)) tr[r] = p;
						}
						if(pos.find(las - 1) != pos.end()) {
							int p = pos[las - 1];
							if(ask(r, p, i + 1, a[r], las - 1)) tr[r] = p;
						}
						if(tr[r]) {
							pos[a[r]] = r, rlim[r] = i, fillans(r);
							return;
						}
					}
					
//					cerr << i << " " << r << " " << a[i] << " " << a[r] << " " << a[3] << endl;
					for(int j = i; j; j--) if(a[j] == max(a[r], a[i]) - 1) {
//						cerr << "search " << j << " " << las << endl;
						if(pos.find(las) != pos.end()) {
							int p = pos[las];
							if(ask(j, p, i + 1, a[j], las)) tr[j] = p;
						}
						if(pos.find(las - 1) != pos.end()) {
							int p = pos[las - 1];
							if(ask(j, p, i + 1, a[j], las - 1)) tr[j] = p;
						}
//						cerr << a[j] << " " << las - 1 << endl;
						if(tr[j]) {
							val[j] = a[j], rlim[j] = i, fillans(j);
							return;
						}
					}
					
//					cerr << "??\n";
					for(int j = i; j; j--) if(!a[j]) {
//						cerr << "search " << j << " " << las << endl;
						if(pos.find(las) != pos.end()) {
							int p = pos[las];
							if(ask(j, p, i + 1, a[r] - 1, las)) tr[j] = p;
						}
						if(pos.find(las - 1) != pos.end()) {
							int p = pos[las - 1];
							if(ask(j, p, i + 1, a[r] - 1, las - 1)) tr[j] = p;
						}
						if(tr[j]) {
							val[j] = a[r] - 1, rlim[j] = i, fillans(j);
							return;
						}
					}
					
					for(int j = i + 1; !a[j]; j++) {
//						cerr << j << " " << tr[j] << endl;
						if(pos.find(las) != pos.end()) {
							int p = pos[las];
							if(ask(j, p, i + 1, a[r] - 1, las)) tr[j] = p;
						}
						if(pos.find(las - 1) != pos.end()) {
							int p = pos[las - 1];
							if(ask(j, p, i + 1, a[r] - 1, las)) tr[j] = p;
						}
						if(tr[j]) {
							val[j] = a[r] - 1, rlim[j] = i, fillans(j);
							return;
						}
					}
					
					assert(0);
				}
				
				if(a[r] < a[i]) {
					if(pos.find(las) != pos.end()) {
						int p = pos[las];
						if(ask(r, p, i + 1, a[r], las)) tr[r] = p;
					}
					if(pos.find(las - 1) != pos.end()) {
						int p = pos[las - 1];
						if(ask(r, p, i + 1, a[r], las - 1)) tr[r] = p;
					}
					assert(tr[r]);
					pos[a[r]] = r, rlim[r] = i;
				}
				
				else {
					if(num == 1) {
						assert(i == r);
//						cerr << "a[r] las " << a[r] << " " << las << endl;
						if(pos.find(las) != pos.end()) {
							int p = pos[las];
							if(ask(r, p, i + 1, a[r], las)) tr[r] = p;
						}
						if(pos.find(las - 1) != pos.end()) {
							int p = pos[las - 1];
//							cerr << "see " << a[r] << " " << las - 1 << endl;
							if(ask(r, p, i + 1, a[r], las - 1)) tr[r] = p;
						}
//						cerr << tr[r] << " " << a[i] << " " << i << endl;
						if(tr[r]) pos[a[i]] = i, rlim[r] = i;
					}
					
					for(int j = r - 1; j >= l; j--) {
						if(pos.find(las) != pos.end()) {
							int p = pos[las];
							if(ask(j, p, i + 1, a[r] - 1, las)) tr[j] = p;
						}
						if(pos.find(las - 1) != pos.end()) {
							int p = pos[las - 1];
							if(ask(j, p, i + 1, a[r] - 1, las - 1)) tr[j] = p;
						}
						if(tr[j]) {
//							cerr << "tr " << a[r] << " " << pos[a[r] - 1] << endl;
							val[j] = a[r] - 1, rlim[j] = i, pos[a[r] - 1] = j;
							break;
						}
					}
				}
				
				las = a[i], i = l;
			}
		}
	}
	void solve() {
		WHAT_THE_FUCK();
		for(int i = 1; i <= n; i++) if(ans[i] == -1) ans[i] = 0;
		for(int i = n; i; i--) putchar(ans[i] + '0');
		putchar('\n');
		
		/*
		TP1 :: calc(ans);
		for(int i = 1; i <= n; i++) 
			cerr << i << " " << a[i] << " " << TP1 :: ans[i] << endl,
			assert(!a[i] || a[i] == TP1 :: ans[i]);
		*/
	}
}

bool Med;
int main() {
	fprintf(stderr, "%.4lf\n", fabs(&Med - &Mbe) / 1048576.0);
//	freopen("game.in", "r", stdin);
//	freopen("game.out", "w", stdout);
	cin >> n, a[0] = 1e18, tp = 2;
	for(int i = 1; i <= n; i++) a[i] = read();
	reverse(a + 1, a + n + 1);
	if(tp == 1) TP1 :: solve(a);
//	else if(n <= 20) BF :: solve();
	else TP2 :: solve();
	return cerr << clock() << endl, 0;
}

/*
6 2
5 6 6 0 0 5

6 2
0 9 7 4 5 5
*/