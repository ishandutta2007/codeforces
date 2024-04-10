#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;
 
#define ll long long

typedef class UnionFound {
	public:
		int n;
		int *f;
		int *w;

		void init(int n) {
			this->n = n;
			f = new int[(n + 1)];
			w = new int[(n + 1)];
			for (int i = 0; i <= n; i++) {
				f[i] = i;
			}
			fill(w, w + n + 1, 0);
		}
		
		int find(int x) {
			if (f[x] == x)
				return x;
			int y = f[x];
			f[x] = find(f[x]);
			w[x] ^= w[y];
			return f[x];
		}

		bool unit(int x, int y, int t) {
			int fx = find(x), fy = find(y);
			if (fx == fy) {
				return !(w[x] ^ w[y] ^ t);
			}
			w[fx] = w[x] ^ t;
			f[fx] = y;
			return true;
		}
} UnionFound;

const int N = 1e3 + 5;
const int Mod = 998244353;
 
int add(int a, int b) {
    return ((a += b) >= Mod) ? (a -= Mod) : (a);
}
 
int n;
char s[N];
int pw2[N << 1];
 
int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    reverse(s + 1, s + n + 1);
    pw2[0] = 1;
    for (int i = 1; i <= (n << 1); i++)
        pw2[i] = add(pw2[i - 1], pw2[i - 1]);
    ll ans = 0;
    for (int l = 1; l < n; l++) {
        int res = 1;
		UnionFound uf;
        uf.init(l + n + 1);
        for (int j = 1; (j << 1) <= l; j++) {
            res = res && uf.unit(j, l - j + 1, 0);
        }
        for (int j = 1; (j << 1) <= n; j++) {
            res = res && uf.unit(l + j, l + n - j + 1, 0);
        }
        res = res && uf.unit(l, l + n + 1, 1);
        for (int i = 1; i <= l && res; i++) {
            if (s[i] == '?') continue;
            if (!uf.unit(i, l + i, s[i] - '0')) {
                res = 0;
            }
        }
        for (int i = l + 1; i <= n && res; i++) {
            if (s[i] == '?') continue;
            if (!uf.unit(l + i, n + l + 1, s[i] - '0')) {
                res = 0;
            }
        }
        if (res) {
            int cnt = 0;
            for (int i = 1; i <= n + l; i++) {
                if (uf.find(i) == i) {
                    cnt += uf.find(i) != uf.find(l + n + 1);
                }
            }
            ans = ans + pw2[cnt];
        }
    }
    ans %= Mod;
    printf("%lld\n", ans);
    return 0;
}