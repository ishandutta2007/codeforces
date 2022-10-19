#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

template<const int mod, const int maxf>
struct NTT {
    int rts[maxf + 1];
    int bitrev[maxf];
    int iv[maxf + 1];
 
    int fpow(int a, int k) {
        if (!k) return 1;
        int res = a, tmp = a;
        k--;
        while (k) {
            if (k & 1) {
                res = (long long) res * tmp % mod;
            }
            tmp = (long long) tmp * tmp % mod;
            k >>= 1;
        }
        return res;
    }
    int prt() {
        vector<int> dvs;
        for (int i = 2; i * i < mod; i++) {
            if ((mod - 1) % i) continue;
            dvs.push_back(i);
            if (i * i != mod - 1) dvs.push_back((mod - 1) / i);
        }
        for (int i = 2; i < mod; i++) {
            int flag = 1;
            for (int j = 0; j < dvs.size(); j++) {
                if (fpow(i, dvs[j]) == 1) {
                    flag = 0;
                    break;
                }
            }
            if (flag) return i;
        }
        assert(0);
        return -1;
    }
    NTT() {
        int k = 0; while ((1 << k) < maxf) k++;
        bitrev[0] = 0;
        for (int i = 1; i < maxf; i++) {
            bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << k - 1);
        }
        int pw = fpow(prt(), (mod - 1) / maxf);
        rts[0] = 1;
        for (int i = 1; i <= maxf; i++) {
            rts[i] = (long long) rts[i - 1] * pw % mod;
        }
        for (int i = 1; i <= maxf; i <<= 1) {
            iv[i] = fpow(i, mod - 2);
        }
    }
    void dft(int a[], int n, int sign) {
        int d = 0; while ((1 << d) * n != maxf) d++;
        for (int i = 0; i < n; i++) {
            if (i < (bitrev[i] >> d)) {
                swap(a[i], a[bitrev[i] >> d]);
            }
        }
        for (int len = 2; len <= n; len <<= 1) {
            int delta = maxf / len * sign;
            for (int i = 0; i < n; i += len) {
                int *w = sign > 0 ? rts : rts + maxf;
                for (int k = 0; k + k < len; k++) {
                    int &a1 = a[i + k + (len >> 1)], &a2 = a[i + k];
                    int t = (long long) *w * a1 % mod;
                    a1 = a2 - t;
                    a2 = a2 + t;
                    a1 += a1 < 0 ? mod : 0;
                    a2 -= a2 >= mod ? mod : 0;
                    w += delta;
                }
            }
        }
        if (sign < 0) {
            int in = iv[n];
            for (int i = 0; i < n; i++) {
                a[i] = (long long) a[i] * in % mod;
            }
        }
    }
    void multiply(int a[], int b[], int na, int nb, int c[]) {
        static int fa[maxf], fb[maxf];
        int n = na + nb - 1; while (n != (n & -n)) n += n & -n;
        for (int i = 0; i < n; i++) fa[i] = fb[i] = 0;
        for (int i = 0; i < na; i++) fa[i] = a[i];
        for (int i = 0; i < nb; i++) fb[i] = b[i];
        dft(fa, n, 1), dft(fb, n, 1);
        for (int i = 0; i < n; i++) fa[i] = (long long) fa[i] * fb[i] % mod;
        dft(fa, n, -1);
        for (int i = 0; i < n; i++) c[i] = fa[i];
    }
    vector<int> multiply(vector<int> a, vector<int> b) {
        static int fa[maxf], fb[maxf], fc[maxf];
        int na = a.size(), nb = b.size();
        for (int i = 0; i < na; i++) fa[i] = a[i];
        for (int i = 0; i < nb; i++) fb[i] = b[i];
        multiply(fa, fb, na, nb, fc);
        int k = na + nb - 1;
        vector<int> res(k);
        for (int i = 0; i < k; i++) res[i] = fc[i];
        return res;
    }
};

const int N = 200005;
const int MOD = 998244353;

NTT<MOD, (1 << 20)> ntt;

int n, p[N];
map<int, int> mp;
vi v[1000005];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	set<int> s;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		s.insert(p[i]);
	}
	int compress = 0;
	for (auto u : s) {
		mp[u] = ++compress;
	}
	for (int i = 1; i <= n; i++) {
		v[mp[p[i]]].pb(1);
	}
	priority_queue<ii> pq;
	for (int i = 1; i <= compress; i++) {
		v[i].push_back(1);
		pq.push({-v[i].size(), i});
	}
	while (pq.size() > 1) {
		int id1 = pq.top().y;
		pq.pop();
		int id2 = pq.top().y;
		pq.pop();
		v[id1] = ntt.multiply(v[id1], v[id2]);
		pq.push({-v[id1].size(), id1});
	}
	int idRes = pq.top().y;
	cout << v[idRes][n >> 1];
	return 0;
}