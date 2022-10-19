#include<bits/stdc++.h>
using namespace std;


#define ii pair<int, int>
#define x first
#define y second
#define pb push_back

const int N = 1505;

int a[N][N];
int n;


set<ii> leaf;
map<ii, ii> p;
vector<ii> g[N];

map<ii, vector<ii>> gr;
unordered_map<long long, int> counter;
// map<set<int>, vector<int>> ans;

const int MOD = 998244353;
const int MOD2 = 1000000007;
 
int power(int x, int y, int mod) {
	if (y == 0) return 1;
	int res = 1;
	while (y) {
		if (y % 2)
			res = 1LL * res * x % mod;
		y >>= 1;
		x = 1LL * x * x % mod;
	}
	return res;
}

ii Hash(set<int> s) {
	ii res = {0, 0};
	for (int e : s) {
		res.x += power(3, e, MOD);
		res.y += power(3, e, MOD2);
		res.x %= MOD;
		res.y %= MOD2;
	}
	return res;
}


inline int add(int u, int v) {
    return (u += v) >= MOD ? u - MOD : u;
}
 
inline int sub(int u, int v) {
    return (u -= v) < 0 ? u + MOD : u;
}
 
inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}
 
inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = mul(res, u);
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}
 
inline int inv(int u) {
    return power(u, MOD - 2);
}
 
const int INV_2 = inv(2);
struct NTT {
    int base = 1;
    int maxBase = 0;
    int root = 2;
    vector<int> w = {0, 1};
    vector<int> rev = {0, 1};
    NTT () {
        int u = MOD - 1;
        while (u % 2 == 0) {
            u >>= 1;
            maxBase++;
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
            a[i] = mul(mul(a[i], b[i]), invN);
        }
        reverse(a.begin() + 1, a.end());
        fft(a);
        a.resize(nResult);
        return a;
    }
    vector<int> polyInv(vector<int> r, vector<int> f) {
        vector<int> foo = mult(r, f);
        foo.resize(f.size());
        foo[0] = sub(2, foo[0]);
        for (int i = 1; i < foo.size(); i++) {
            foo[i] = sub(0, foo[i]);
        }
        vector<int> res = mult(r, foo);
        res.resize(f.size());
        return res;
    }
    vector<int> polySqrt(vector<int> s, vector<int> invS, vector<int> f) {
        vector<int> res = mult(f, invS);
        res.resize(f.size());
        for (int i = 0; i < s.size(); i++) {
            res[i] = add(res[i], s[i]);
        }
        for (int i = 0; i < res.size(); i++) {
            res[i] = mul(res[i], INV_2);
        }
        return res;
    }
    vector<int> getSqrt(vector<int> c, int sz) {
        vector<int> sqrtC = {1}, invSqrtC = {1}; //change this if c[0] != 1
        for (int k = 1; k < (1 << sz); k <<= 1) {
            vector<int> foo(c.begin(), c.begin() + (k * 2));
            vector<int> bar = sqrtC;
            bar.resize(bar.size() * 2, 0);
            vector<int> tempInv = polyInv(invSqrtC, bar);
            sqrtC = polySqrt(sqrtC, tempInv, foo);
            invSqrtC = polyInv(invSqrtC, sqrtC);
        }
        return sqrtC;
    }
    vector<int> getInv(vector<int> c, int sz) {
        vector<int> res = {INV_2}; // change this if c[0] != 2
        for (int k = 1; k < (1 << sz); k <<= 1) {
            vector<int> foo(c.begin(), c.begin() + (k * 2));
            res = polyInv(res, foo);
        }
        return res;
    }
} ntt;


ii p3[1505];
const int BASE = 1000000021;

long long has(ii u) {
	return 1LL * u.x * BASE + u.y;
}

vector<int> dfs(ii u) {
	if (leaf.count(u)) {
		// ans[u] = vector<int>({0, 1});
		return vector<int>({0, 1});
	}


	vector<vector<int>> to_mul;

	for (auto e : gr[u]) {
		to_mul.pb(dfs(e));
	}

	priority_queue<ii, vector<ii>, greater<ii>> pq;

	for (int i = 0; i < to_mul.size(); i++) {
		pq.push({to_mul[i].size(), i});
	}

	while (pq.size() > 1) {
		ii u = pq.top(); pq.pop();
		ii v = pq.top(); pq.pop();

		to_mul[u.y] = ntt.mult(to_mul[u.y], to_mul[v.y]);

		pq.push({to_mul[u.y].size(), u.y});
	}

	vector<int> res = to_mul[pq.top().y];


	res[1]++;

	return res;

}



int main() {
	ios::sync_with_stdio(false); cin.tie(0);


	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}

	p3[0] = {1, 1};

	for (int i = 1; i <= n; i++) {
		p3[i].x = 1LL * p3[i - 1].x * 3 % MOD;
		p3[i].y = 1LL * p3[i - 1].y * 3 % MOD2;
		leaf.insert(p3[i]);
	}

	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			g[i].pb({a[i][j], j});
			g[j].pb({a[i][j], i});
		}
	}


	int dem = 0;


	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " seconds" << endl;

	for (int i = 1; i <= n; i++) {
		sort(g[i].begin(), g[i].end());
	}


	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " seconds" << endl;

	for (int i = 1; i <= n; i++) {
		set<int> curSet;
		curSet.insert(i);
		ii curHash = p3[i];
		counter[has(curHash)] = 1;

		for (ii e : g[i]) {
			dem++;
			int u = e.y;

			curSet.insert(u);
			curHash.x += p3[u].x;
			curHash.x %= MOD;
			curHash.y += p3[u].y;
			curHash.y %= MOD2;

			counter[has(curHash)]++;

		}
	}

	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " seconds" << endl;

	for (int i = 1; i <= n; i++) {
		set<int> curSet;
		curSet.insert(i);
		ii curHash = p3[i];
		ii ok = curHash;

		for (ii e : g[i]) {
			dem++;
			int u = e.y;

			curSet.insert(u);
			curHash.x += p3[u].x;
			curHash.x %= MOD;
			curHash.y += p3[u].y;
			curHash.y %= MOD2;


			if (counter[has(curHash)] == curSet.size()) {
				p[ok] = curHash;
				ok = curHash;
			}

		}
	}	



	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " seconds" << endl;


	for (auto e : p) {
		gr[e.y].push_back(e.x);
	}
	set<int> root;
	for (int i = 1; i <= n; i++) 
		root.insert(i);


	vector<int> ans = dfs(Hash(root));


	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}

	cout << endl;

	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " seconds" << endl;


	return 0;
}