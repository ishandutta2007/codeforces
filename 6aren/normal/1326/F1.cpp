#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

vector<int> g[15], neg[15];
int n, l, r;
long long ans[1 << 15];
bool check[1 << 15];
int cntl[15][1 << 7];
int cntr[15][1 << 7];
int sumr[2][15][1 << 7];
int gr[15][15];

void solve(int mask) {
    memset(cntl, 0, sizeof(cntl));
    memset(cntr, 0, sizeof(cntr));
    memset(sumr, 0, sizeof(sumr));
    vector<int> le, ri;
    for (int i = 0; i < n; i++) {
        if (bit(mask, i) == 1) le.pb(i);
        else ri.pb(i);
    }
    do {
        int mas = 0;
        for (int i = 1; i < le.size(); i++) {
            if (gr[le[i - 1]][le[i]]) mas ^= (1 << (l - 1 - i));
        }
        cntl[le.back()][mas]++;
    } while (next_permutation(all(le)));
    do {
        int mas = 0;
        for (int i = 1; i < ri.size(); i++) {
            if (gr[ri[i - 1]][ri[i]]) mas ^= (1 << (r - 1 - i));
        }
        cntr[ri[0]][mas]++;
    } while (next_permutation(all(ri)));
    for (int u : le) {
        for (int imask = 0; imask < (1 << (r - 1)); imask++) {
            for (int e : g[u]) {
                sumr[1][u][imask] += cntr[e][imask];
            }
            for (int e : neg[u]) {
                sumr[0][u][imask] += cntr[e][imask];
            }
        }
        for (int imask1 = 0; imask1 < (1 << (l - 1)); imask1++) {
            for (int imask2 = 0; imask2 < (1 << (r - 1)); imask2++) {
                int mas = (imask1 << r) + imask2;
                ans[mas] += cntl[u][imask1] * sumr[0][u][imask2];
                mas = (mas ^ (1 << (r - 1)));
                ans[mas] += cntl[u][imask1] * sumr[1][u][imask2];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n;
    string inp;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        for (int j = 0; j < n; j++) {
            gr[i][j] = inp[j] - '0';
            if (inp[j] == '1') {
                g[i].pb(j);
            } else neg[i].pb(j);
        }
    }
    l = (n + 1) / 2;
    r = n - l;
    for (int mask = 1; mask < (1 << n); mask++) {
        if (!check[mask] and __builtin_popcount(mask) == l) {
            solve(mask);
        }
    }
    for (int i = 0; i < (1 << (n - 1)); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}