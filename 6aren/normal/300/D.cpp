#include <bits/stdc++.h>

using namespace std;

const int MOD = 7340033;

int add(int u, int v) {
    u += v;
    if (u >= MOD) u -= MOD;
    return u;
}

int sub(int u, int v) {
    u -= v;
    if (u < 0) u += MOD;
    return u;
}

int mul(int u, int v) {
    return (long long)u * v % MOD;
}

int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = mul(res, u); 
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

int inv(int u) {
    return power(u, MOD - 2);
}

struct NTT {
    int base = 1;
    int maxBase = 0;
    int root = 2;
    vector<int> w = {0, 1};
    vector<int> rev = {0, 1};
    NTT() {
        int u = MOD - 1;
        while (u % 2 == 0) {
            maxBase++;
            u >>= 1;
        }
        while (power(root, 1 << maxBase) != 1 || power(root, 1 << (maxBase - 1)) == 1) root++;
    }
    void ensure(int curBase) {
        assert(curBase <= maxBase);
        if (curBase <= base) return;
        rev.resize(1 << curBase);
        for (int i = 0; i < (1 << curBase); i++) {
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (curBase - 1));
        }
        w.resize(1 << curBase);
        for (; base < curBase; base++) {
            int wc = power(root, 1 << (maxBase - base - 1));
            for (int i = 1 << (base - 1); i < (1 << base); i++) {
                w[i << 1] = w[i];
                w[i << 1 | 1] = mul(w[i], wc);
            }
        }
    }
    void fft(vector<int> &a) {
        int n = a.size();
        int curBase = 0;
        while ((1 << curBase) < n) curBase++;
        int shift = base - curBase;
        for (int i = 0; i < n; i++) {
            if (i < (rev[i] >> shift)) swap(a[i], a[rev[i] >> shift]);
        }
        for (int k = 1; k < n; k <<= 1) {
            for (int i = 0; i < k; i++) {
                for (int j = i; j < n; j += k * 2) {
                    int foo = a[j];
                    int bar = mul(a[j + k], w[i + k]);
                    a[j] = add(foo, bar);
                    a[j + k] = sub(foo, bar);
                }
            }
        }
    }
    vector<int> mult(vector<int> a, vector<int> b) {
        int nResult = a.size() + b.size() - 1;
        int curBase = 0;
        while ((1 << curBase) < nResult) curBase++;
        ensure(curBase);
        int n = 1 << curBase;
        a.resize(n), b.resize(n);
        fft(a);
        fft(b);
        int invN = inv(n);
        for (int i = 0; i < n; i++) {
            a[i] = mul(a[i], mul(b[i], invN));
        }
        reverse(a.begin() + 1, a.end());
        fft(a);
        a.resize(nResult);
        return a;
    }
} ntt;
 
vector<int> powerPol(vector<int> a, int y) {
	vector<int> res;
	if (y == 0) {
		res.push_back(1);
		return res;
	}
	vector<int> temp = powerPol(a, y / 2);
	if (y % 2) {
		return ntt.mult(temp, ntt.mult(temp, a));
	} else {
		return ntt.mult(temp, temp);
	}
}

int f[32][1005];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	f[0][0] = 1;
	vector<int> a(1001);
	a[0] = f[0][0];
	for (int i = 1; i <= 31; i++) {
		a = powerPol(a, 4);
		f[i][0] = 1;
		for (int j = 1; j <= 1000; j++) {
			f[i][j] = a[j - 1];
		}
		a.resize(1001);
		for (int j = 0; j <= 1000; j++) {
			a[j] = f[i][j];
		} 
	}
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		int cnt = 0;
		while (n % 2 == 1 && n != 1) {
			cnt++;
			n /= 2;
		}
		cout << f[cnt][k] << '\n';
	}
}