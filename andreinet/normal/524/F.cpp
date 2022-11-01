#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9, INF = 0x3f3f3f3f;
const int NMAX = 1000005;

int pow2_1[2 * NMAX], pow2_2[2 * NMAX];
int hadd1[2 * NMAX], hadd2[2 * NMAX];

string inverse(string s) {
    for (char& c: s) {
        c = c == '(' ? ')': '(';
    }
    return s;
}

string reverse(string s) {
    reverse(s.begin(), s.end());
    return s;
}

vector<int> getNeed(string S, int k) {
    int n = SZ(S);
    vector<int> need(n - k);
    vector<int> sum(n, 0);
    int s = 0;

    deque<int> d;
    for (int i = 0; i < k - 1; ++i) {
        s += (S[i] == ')' ? 1: -1);
        sum[i] = s;
        while (!d.empty() && s >= sum[d.back()])
            d.pop_back();
        d.push_back(i);
    }
    int sprev = 0;
    for (int i = 0; i + k < n; ++i) {
        s += (S[i + k - 1] == ')' ? 1: -1);
        sum[i + k - 1] = s;
        while (!d.empty() && d.front() < i) {
            d.pop_front();
        }
        while (!d.empty() && s > sum[d.back()]) {
            d.pop_back();
        }
        d.push_back(i + k - 1);
        need[i] = max(0, sum[d.front()] - sprev);
        sprev = sum[i];
    }
    return need;
}

vector<pair<int, int>> getHashes(const string& S) {
    int n = SZ(S);
    int h1 = 0, h2 = 0;
    vector<pair<int, int>> result(n);
    for (int i = 0; i < n; ++i) {
        int c = S[i] == ')' ? 1: 0;
        h1 = (h1 * 2 + c) % MOD1;
        h2 = (h2 * 2 + c) % MOD2;
        result[i] = make_pair(h1, h2);
    }
    pow2_1[0] = pow2_2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pow2_1[i] = 2 * pow2_1[i - 1] % MOD1;
        pow2_2[i] = 2 * pow2_2[i - 1] % MOD2;
    }
    hadd1[0] = hadd2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        hadd1[i] = (2 * hadd1[i - 1] + 1) % MOD1;
        hadd2[i] = (2 * hadd2[i - 1] + 1) % MOD2;
    }
    return result;
}

pair<int, int> getHash(const vector<pair<int, int>>& partialHash,
                       int front, int pos, int mlen, int back, int len) {
    int h1 = 0, h2 = 0;
    if (front > 0) {
        int p = min(len, front);
        h1 = pow2_1[p - 1];
        h2 = pow2_2[p - 1];
    }
    int clen = min(mlen, len - front);
    int rpos = pos + clen - 1;
    if (clen > 0) {
        int ah1 = partialHash[rpos].first;
        int ah2 = partialHash[rpos].second;
        if (pos > 0) {
            ah1 = (ah1 + MOD1 -
            (int64_t) pow2_1[clen] * partialHash[pos - 1].first % MOD1) % MOD1;

            ah2 = (ah2 + MOD2 -
            (int64_t) pow2_2[clen] * partialHash[pos - 1].second % MOD2) % MOD2;
        }
        h1 = ((int64_t) h1 * pow2_1[clen] + ah1) % MOD1;
        h2 = ((int64_t) h2 * pow2_2[clen] + ah2) % MOD2;
    }

    clen = min(back, len - front - mlen);
    if (clen > 0) {
        h1 = ((int64_t) h1 * pow2_1[clen] + hadd1[clen - 1]) % MOD1;
        h2 = ((int64_t) h2 * pow2_2[clen] + hadd2[clen - 1]) % MOD2;
    }
    return make_pair(h1, h2);
}

int compare(const string& S, const vector<pair<int, int>>& hashes,
            const vector<int>& need1, const vector<int>& need2,
            int p1, int p2, int len) {

    int elen = 0, step;
    int mxlen = need1[p1] + len + need2[p1];
    for (step = 1; step < mxlen; step *= 2);
//    cerr << getHash(hashes, need1[p1], p1, len, need2[p1], 1).first << endl;
//    cerr << getHash(hashes, need1[p1], p1, len, need2[p1], 1).second << endl;
//    cerr << getHash(hashes, need1[p2], p2, len, need2[p2], 1).first << endl;
//    cerr << getHash(hashes, need1[p2], p2, len, need2[p2], 1).first << endl;
    for (; step > 0; step /= 2) {
        if (elen + step < mxlen &&
                getHash(hashes, need1[p1], p1, len, need2[p1], elen + step) == 
                getHash(hashes, need1[p2], p2, len, need2[p2], elen + step)) {
            elen += step;
        }
    }
    if (elen == mxlen) return 0;
    char c1 = elen < need1[p1] ? '(': (elen < need1[p1] + len ? 
                S[p1 + elen - need1[p1]]: ')');
    return c1 == '(' ? -1: 1;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    int n = SZ(S);
    S += S;

    vector<int> need1 = getNeed(S, n);
    vector<int> need2 = getNeed(inverse(reverse(S)), n);
    need2.push_back(need2[0]);
    need2.erase(need2.begin());
    reverse(need2.begin(), need2.end());

    vector<pair<int, int>> hashes = getHashes(S);

    int nmin = INF;
    for (int i = 0; i < n; ++i) {
        //cerr << need1[i] << ' ' << need2[i] << endl;
        nmin = min(nmin, need1[i] + need2[i]);
    }

    int pos = -1;
    for (int i = 0; i < n; ++i) {
        int t = need1[i] + need2[i];
        if (t == nmin && (pos == -1 ||
                    compare(S, hashes, need1, need2, pos, i, n) > 0)) {
            pos = i;
        }
    }

    string ans = string(need1[pos], '(') + S.substr(pos, n) + 
                 string(need2[pos], ')');
    cout << ans << '\n';
}