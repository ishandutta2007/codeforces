#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second
const int N = 100087;
int hashh[10];
const int MOD = 998244353, p = 8641975;
lli pn[N], piv[N], pp[N];

lli modpow (lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % MOD) {
        if (b & 1) ans = ans * a % MOD;
    }
    return ans;
}

lli modinv (lli a) {
    return modpow(a, MOD - 2);
}

struct Seg {
	int l,r,m, addTag;
	lli sum;
	Seg* ch[2];
	Seg (int l, int r): l(l), r(r), m(l + r >> 1) {
		sum = 0;
		addTag = -1;
		if (r - l != 1) {
			ch[0] = new Seg(l,m);
			ch[1] = new Seg(m,r);
			pull();
		}
	}
	void pull() {sum = ch[0]->sum + ch[1]->sum;}
	void push() {
		if (addTag > -1) {
			if (r - l != 1) {
				ch[0]->sum = pp[m - l] * hashh[addTag] % MOD * pn[l] % MOD;
				ch[0]->addTag = addTag;
				ch[1]->sum = pp[r - m] * hashh[addTag] % MOD * pn[m] % MOD;
				ch[1]->addTag = addTag;
			}
			addTag = -1;
		}
	}
	void add(int a, int b, int v) {
		if (a >= b) return;
		if (a <= l and r <= b) {
			sum = pp[r - l] * hashh[v] % MOD * pn[l] % MOD;
			addTag = v;
		} else {
			push();
			if (a < m) ch[0]->add(a,b,v);
			if (m < b) ch[1]->add(a,b,v);
			pull();
		}
	}
	void set(int p, int v) {
		if (r - l == 1) {
			sum = hashh[v] * pn[p] % MOD;
		} else {
			if (p < m) {
				ch[0]->set(p,v); 
			} else {
				ch[1]->set(p,v);
			}
			pull();
		}
	}
	lli query(int a, int b) {
	    if (a >= b) return 0;
		if (a <= l and r <= b) return sum;
		lli ans = 0;
		push();
		if (a < m) ans = (ans + ch[0]->query(a,b)) % MOD; 
		if (m < b) ans = (ans + ch[1]->query(a,b)) % MOD; 
		return ans;
	}
};

lli myrand() {
    lli ans = 0, t = 6;
    while (t--) {
        ans = (ans << 10) | (rand() & 1023);
    }
    return ans % MOD;
}

int main () {
    srand(time(NULL));
    int n, m, q;
    cin >> n >> m >> q;
    char c;
    pn[0] = 1;
    fop (i,1,N) {
        pn[i] = pn[i-1] * p % MOD;
    }
    pp[0] = 0;
    fop (i,1,N) {
        pp[i] = (pp[i-1] + pn[i-1]) % MOD;
    }
    fop (i,0,10) hashh[i] = myrand();
    Seg root(0, n);
    fop (i,0,n) {
        cin >> c;
        root.set(i, c - '0');
    }
    int t, x, y, d;
    fop (i,0,m+q) {
        cin >> t >> x >> y >> d;
        x--;
        if (t == 1) {
            root.add(x, y, d);
        } else {
            lli aa = root.query(x + d, y) * modinv(pn[x + d]) % MOD, bb = root.query(x, y - d) * modinv(pn[x]) % MOD;
            if (aa == bb) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}