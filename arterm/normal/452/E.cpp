#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <memory.h>

using namespace std;

#define M 300100
#define long long long
#define mod 1000000007ll

long P[3] = {5, 7, 11}, MOD[3] = {1000000007, 1000000009, 1000000007};
string s, A, B, C, G;
long h[3][M], pw[3][M], x[M][3], a[M], sum = 0, ans[M];
int n, l[M], r[M];
vector<int> D[M];

void pre() {
    for (int t = 0; t < 3; ++t) {
        h[t][0] = 0;
        for (int i = 1; i <= n; ++i)
            h[t][i] = (s[i - 1] + P[t] * h[t][i - 1]) % MOD[t];

        pw[t][0] = 1;
        for (int i = 1; i < M; ++i)
            pw[t][i] = (P[t] * pw[t][i - 1]) % MOD[t];
    }
}

bool equ(int i, int j, int len) {
    if (i == j)
        return true;
    for (int t = 0; t < 3; ++t)
        if ((h[t][i + len] + pw[t][len] * h[t][j] - h[t][j + len] - pw[t][len] * h[t][i]) % MOD[t] != 0)
            return false;
    return true;
}

int lcp(int i, int j) {
    int len = min(n - i, n - j);
    if (i == j)
        return len;

    int l = 0, r = len, m;

    while (l < r) {
        m = (l + r) / 2;
        if (equ(i, j, m + 1))
            l = m + 1;
        else
            r = m;
    }
    return l;
}

bool cmp(int i, int j) {
    if (i == j)
        return false;
    int len = lcp(i, j);
    if (max(i, j) + len == n)
        return i > j;
    return s[i + len] < s[j + len];
}

const int alphabet = 256;
const int maxlen = 300100;
int p[maxlen], cnt[maxlen], c[maxlen];
int pn[maxlen], cn[maxlen];
void suff_arr() {
    
    memset (cnt, 0, alphabet * sizeof(int));
    for (int i=0; i<n; ++i)
        ++cnt[s[i]];
    for (int i=1; i<alphabet; ++i)
        cnt[i] += cnt[i-1];
    for (int i=0; i<n; ++i)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i=1; i<n; ++i) {
        if (s[p[i]] != s[p[i-1]])  ++classes;
        c[p[i]] = classes-1;
    }

    for (int h=0; (1<<h)<n; ++h) {
        for (int i=0; i<n; ++i) {
            pn[i] = p[i] - (1<<h);
            if (pn[i] < 0)  pn[i] += n;
        }
        memset (cnt, 0, classes * sizeof(int));
        for (int i=0; i<n; ++i)
            ++cnt[c[pn[i]]];
        for (int i=1; i<classes; ++i)
            cnt[i] += cnt[i-1];
        for (int i=n-1; i>=0; --i)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i=1; i<n; ++i) {
            int mid1 = (p[i] + (1<<h)) % n,  mid2 = (p[i-1] + (1<<h)) % n;
            if (c[p[i]] != c[p[i-1]] || c[mid1] != c[mid2])
                ++classes;
            cn[p[i]] = classes-1;
        }
        memcpy (c, cn, n * sizeof(int));
    }

    for (int i = 0; i < n; ++i)
        a[i] = p[i];
}

void ini() {
    for (int i = 0; i < M; ++i) {
        l[i] = r[i] = i;
        for (int j = 0; j < 3; ++j)
            x[i][j] = 0;
    }
}

long prod(int t) {
    long ans = 1;
    for (int i = 0; i < 3; ++i)
        ans *= x[t][i];
    return ans % mod;
}

void uni(int t) {
    int le = l[t];
    int re = r[t + 1];

    r[le] = re;
    l[re] = le;

    sum -= prod(le);
    sum -= prod(t + 1);

    for (int i = 0; i < 3; ++i)
        x[le][i] += x[t + 1][i];

    sum += prod(le);

    sum %= mod;
}


void upd(long * x, int pos) {
    int t = G[pos] - '0';
    if (t < 3)
        x[t]++;
}

void kill() {

    for (int i = 0; i + 1 < n; ++i)
        D[lcp(a[i], a[i + 1])].push_back(i);

    for (int i = 0; i < n; ++i)
        upd(x[i], a[i]);

    for (int i = M - 1; i > 0; --i) {
        for (auto to : D[i])
            uni(to);
        
        if (sum < 0)
            sum += mod;

        ans[i] = sum;
    }

    int t = min(A.length(), min(B.length(), C.length()));

    for (int i = 1; i <= t; ++i)
        cout << ans[i] << " ";
    cout << "\n";
}


int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    cin >> A >> B >> C;
    s = A + "#" + B + "@" + C + "=";
    string A_(A.length(), '0');
    string B_(B.length(), '1');
    string C_(C.length(), '2');
    G = A_ + '3' + B_ + '3' + C_ + '3';

    n = s.length();


    pre();
    suff_arr();
    ini();
    kill();

    return 0;
}