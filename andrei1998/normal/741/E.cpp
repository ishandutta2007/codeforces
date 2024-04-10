#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int nMAX = 100000 + 5;
const int NMAX = 2 * nMAX;

int n, m;
string S, T;
int Q;

int N;
string str;

const int MOD[] = {1000000000 + 7, 1000000000 + 9};

struct Hash {
    int h[sizeof(MOD) / sizeof(int)];

    Hash() {
        for (int i = 0; i < sizeof(MOD) / sizeof(int); ++ i)
            h[i] = 0;
    }

    //Warning: non-generic
    Hash(int v0, int v1) {
        h[0] = v0, h[1] = v1;
    }

    Hash operator+(const Hash &hs) const {
        Hash res;
        for (int i = 0; i < sizeof(MOD) / sizeof(int); ++ i) {
            res.h[i] = h[i] + hs.h[i];
            if (res.h[i] >= MOD[i])
                res.h[i] -= MOD[i];
        }
        return res;
    }

    Hash operator-(const Hash &hs) const {
        Hash res;
        for (int i = 0; i < sizeof(MOD) / sizeof(int); ++ i) {
            res.h[i] = h[i] - hs.h[i];
            if (res.h[i] < 0)
                res.h[i] += MOD[i];
        }
        return res;
    }

    Hash operator*(const Hash &hs) const {
        Hash res;
        for (int i = 0; i < sizeof(MOD) / sizeof(int); ++ i)
            res.h[i] = (1LL * h[i] * hs.h[i]) % MOD[i];
        return res;
    }

    bool operator==(const Hash &hs) const {
        for (int i = 0; i < sizeof(MOD) / sizeof(int); ++ i)
            if (h[i] != hs.h[i])
                return false;
        return true;
    }
    bool operator!=(const Hash &hs) const {
        for (int i = 0; i < sizeof(MOD) / sizeof(int); ++ i)
            if (h[i] != hs.h[i])
                return true;
        return false;
    }
};

const Hash C = {666013, 666017};

Hash powC[NMAX];
Hash sPart[NMAX];

void precomputeHashes() {
    powC[0] = Hash(1, 1);
    for (int i = 1; i <= N; ++ i)
        powC[i] = powC[i - 1] * C;
    for (int i = 1; i <= N; ++ i)
        sPart[i] = sPart[i - 1] * C + Hash(str[i], str[i]);
}

Hash getHashS(int l, int r) {
    Hash hr = sPart[r];
    Hash hl = sPart[l - 1];
    return hr - hl * powC[r - l + 1];
}

Hash getHashT(int l, int r) {
    Hash hr = sPart[r + n + 1];
    Hash hl = sPart[l - 1 + n + 1];
    return hr - hl * powC[r - l + 1];
}

//Returns 1 if l < r and 0 otherwise (in terms of suffixes)
bool lcp(int l, int r) {
    int st = 1;
    int dr = min(N - l + 1, N - r + 1);
    int ans = 0;

    while (st <= dr) {
        int mid = (st + dr) >> 1;
        if (getHashS(l, l + mid - 1) == getHashS(r, r + mid - 1)) {
            ans = mid;
            st = mid + 1;
        }
        else
            dr = mid - 1;
    }

    return str[l + ans] < str[r + ans];
}

int lcpSS(int l, int r) {
    return lcp(l, r);
}

int lcpST(int l, int r) {
    return lcp(l, r + n + 1);
}

int lcpTS(int l, int r) {
    return lcp(l + n + 1, r);
}

int lcpTT(int l, int r) {
    return lcp(l + n + 1, r + n + 1);
}

bool cmpPlacement(const int &_a, const int &_b) {
    int a = _a + 1, b = _b + 1;

    bool rev = false;
    if (b < a) {
        swap(a, b);
        rev = true;
    }

    if (b <= a + m) { //a and b intersect
        if (getHashT(1, b - a) != getHashS(a, b - 1))
            return lcpTS(1, a) ^ rev;
        else if (getHashT(b - a + 1, m) != getHashT(1, a + m - b))
            return lcpTT(b - a + 1, 1) ^ rev;
        else if (getHashS(a, b - 1) != getHashT(a + m - b + 1, m)) {
            return lcpST(a, a + m - b + 1) ^ rev;
        }
    }
    else {
        if (getHashT(1, m) != getHashS(a, a + m - 1))
            return lcpTS(1, a) ^ rev;
        else if (getHashS(a, b - m - 1) != getHashS(a + m, b - 1)) {
            return lcpSS(a, a + m) ^ rev;
        }
        else if (getHashS(b - m, b - 1) != getHashT(1, m))
            return lcpST(b - m, 1) ^ rev;
    }

    return false;
}

string ins(string a, string b, int pos) {
    a.insert(pos, b);
    return a;
}

int ord[NMAX];
int inv[NMAX];
int logar2[NMAX];

void precLogar2() {
    for (int i = 2; i <= N; ++ i)
        logar2[i] = 1 + logar2[i >> 1];
}

const int RAD = 65;

struct RMQ {
    vector <int> v;

    int dims;
    //vector <vector <int> > dp;
    int **dp;

    void destroy() {
        v.clear();
        for (int i = 0; i <= dims; ++ i)
            delete dp[i];
        delete dp;
        dims = 0;
    }

    void computeDp() {
        dims = logar2[v.size()];
        if ((1 << dims) < v.size())
            ++ dims;

        //dp.resize(dims + 1);
        dp = new int*[dims + 1];
        for (int i = 0; i <= dims; ++ i) {
            //dp[i].resize(v.size());
            dp[i] = new int[v.size()];
        }

        for (int i = 0; i < v.size(); ++ i)
            dp[0][i] = v[i];

        for (int i = 1; i <= dims; ++ i)
            for (int j = 0; j + (1 << i) - 1 < v.size(); ++ j)
                if (inv[dp[i - 1][j]] < inv[dp[i - 1][j + (1 << (i - 1))]])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j + (1 << (i - 1))];
    }

    int query(int a, int b) {
        if (b < a)
            return n + 1; //INF

        int y = logar2[b - a + 1];
        if (inv[dp[y][a]] < inv[dp[y][b - (1 << y) + 1]])
            return dp[y][a];
        return dp[y][b - (1 << y) + 1];
    }
} all;

RMQ rmqs[RAD + 5];

struct Query {
    int l, r, x, y;
    int pos;
};

vector <Query> queries[RAD + 5];

int anss[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin >> S >> T >> Q;

    n = S.size();
    m = T.size();

    str = "#" + S + "#" + T;
    N = str.size() - 1;
    str += "#";

    precomputeHashes();
    /*for (int i = 1; i <= 7; ++ i)
        for (int j = 1; j <= 7; ++ j)
            cout << i << ' ' << j << ' ' << lcp(i, j) << endl;*/

    /*for (int i = 0; i <= n; ++ i) {
        for (int j = 0; j <= n; ++ j) {
            string str1 = ins(S, T, i);
            string str2 = ins(S, T, j);

            if ((str1 < str2) != cmpPlacement(i, j))
                cout << "Off " << i << ' ' << j << endl;
        }
    }*/

    for (int i = 0; i <= n; ++ i)
        ord[i] = i;
    stable_sort(ord, ord + n + 1, cmpPlacement);
    for (int i = 0; i <= n; ++ i)
        inv[ord[i]] = i;
    inv[n + 1] = n + 2;

    precLogar2();

    //Main RMQ
    all.v.resize(n + 1);
    for (int i = 0; i <= n; ++ i) {
        //cout << i << ' ' << inv[i] << '\n';
        all.v[i] = i;
    }
    all.computeDp();

    //Read queries and solve big ones
    for (int i = 1; i <= Q; ++ i) {
        int l, r, k, x, y;
        cin >> l >> r >> k >> x >> y;

        int ans = n + 1;
        if (k > RAD) {
            //Rectify left end
            if (x <= l % k && l % k <= y) {
                ans = all.query(l, min(r, l + y - l % k));
                l += y - l % k + 1;
            }
            l += (k + x - l % k) % k;

            //Step by step walk
            while (l <= r) {
                int aux = all.query(l, min(r, l + y - x));
                if (inv[aux] < inv[ans])
                    ans = aux;
                l += k;
            }

            if (ans == n + 1)
                anss[i] = -1;
            else
                anss[i] = ans;
        }
        else {
            //Push for later solving
            queries[k].push_back({l, r, x, y, i});
        }
    }

    for (int k = 1; k <= RAD; ++ k) {
        for (int i = 0; i <= n; ++ i)
            rmqs[i % k].v.push_back(i);
        for (int res = 0; res < k; ++ res)
            rmqs[res].computeDp();

        for (auto it: queries[k]) {
            int x = it.x;
            int y = it.y;
            int l = it.l;
            int r = it.r;
            int pos = it.pos;

            int ans = n + 1;
            for (int res = x; res <= y && res <= r; ++ res) {
                int a, b;
                b = (r - res) / k;

                if (l - res < 0)
                    a = 0;
                else
                    a = (l - res + k - 1) / k;

                int qu = rmqs[res].query(a, b);
                if (inv[qu] < inv[ans])
                    ans = qu;
            }

            if (ans == n + 1)
                anss[pos] = -1;
            else
                anss[pos] = ans;
        }

        for (int res = 0; res < k; ++ res)
            rmqs[res].destroy();
    }

    //Print answers
    for (int i = 1; i <= Q; ++ i)
        cout << anss[i] << " \n"[i == Q];
    return 0;
}