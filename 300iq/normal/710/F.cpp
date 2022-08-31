#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

int BASE;
const int M1 = (int) 1e9 + 7, M2 = (int) 1e9 + 9;
const int MAXN = (int) 3e5 + 7;
char c[MAXN];
int f[MAXN];

struct hsh {
    int m;
    int len, h;
    hsh(int a, int b, int c) {
        m = a, len = b, h = c;
    }
};

struct hush {
    size_t operator () (const hsh &k) const {
        return (k.len * (ll) BASE + k.h) % k.m;
    }
};

struct eq {
    bool operator () (const hsh &a, const hsh &b) const {
        return a.len == b.len && a.h == b.h;
    }
};

hsh her(const string &s, int mod) {
    int p = 0;
    for (auto c : s) {
        p = (p * (ll) BASE + c) % mod; 
    }
    return {mod, (int) s.size(), p};
}

string next() {
    string w = "";
    char c;
    scanf("%c", &c);
    while (c <= 32) {
        scanf("%c", &c);
    }
    while (c > 32) {
        w += c;
        scanf("%c", &c);
    }
    return w;
}

//unordered_set <hsh, hush, eq> s[2];
set <hsh> s[2];

bool operator < (const hsh &a, const hsh &b) {
	if (a.len == b.len) {
		return a.h < b.h;
	} else {
		return a.len < b.len;
	}
}

struct hash_str {
    int m;
    vector <int> h, p;
    hash_str(const string &s, int mod) {
        m = mod;
        int n = s.size();
        h.resize(n + 1);
        p.resize(n + 1);
        p[0] = 1, h[0] = 0;
        for (int i = 1; i <= n; i++) {
            p[i] = (p[i - 1] * (ll) BASE) % m;
            h[i] = (h[i - 1] * (ll) BASE + s[i - 1]) % m;
        }
    }
    hsh get(int l, int r) {
        int res = h[r] - (h[l] * (ll) p[r - l]) % m;
        if (res < 0) res += m;
        return {m, r - l, res};
    }
};

int main() {
    srand(time(NULL));
    BASE = rand();
    int m;
    scanf("%d", &m);
    while (m--) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            string p = next();
            f[p.size()]++;
            s[0].insert(her(p, M1));
            //s[1].insert(her(p, M2));
        } else if (t == 2) {
            string p = next();
            f[p.size()]--;
            s[0].erase(her(p, M1));
            //s[1].erase(her(p, M2));
        } else {
            string p = next();
            int n = p.size();
            hash_str h1(p, M1);
            int cnt = 0;
            for (int len = 1; len <= n; len++) {
                if (f[len] == 0) continue;
                for (int i = 0; i + len <= n; i++) {
                    cnt += (s[0].count(h1.get(i, i + len))); 
                }
            }
            printf("%d\n", cnt);
            fflush(stdout);
        }
    }
}