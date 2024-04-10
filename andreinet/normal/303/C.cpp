#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 5005, maxv = 1000001;

int A[NMAX];
pair<int, int> diffs[maxv + 5][11];
int psz[maxv + 5];

int father[maxv + 5];
bitset<maxv + 5> used;

int find(int x) {
    int y, p;
    for (y = father[x]; y != father[y]; y = father[y]);
    for (; x != y; x = p) {
        p = father[x];
        father[x] = y;
    }
    return y;
}

void unite(int x, int y) {
    father[find(x)] = find(y);
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    sort(A + 1, A + n + 1);

    for (int i = 1; i <= maxv; ++i) {
        father[i] = i;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i - 1; j > 0; --j) { 
            int x = A[i] - A[j];
            if (psz[x] < 11) {
                diffs[x][psz[x]++] = make_pair(A[i], A[j]);
            }
        }
    }

    pair<int, int> cdiffs[11];
    int csz;
    for (int i = 1; i <= maxv; ++i) {
        csz = psz[i];
        for (int j = 0; j < psz[i]; ++j) {
            cdiffs[j] = diffs[i][j];
        }
        bool ok = csz <= 10;
        for (int j = i + i; j <= maxv; j += i) {
            if (csz + psz[j] > 10) {
                ok = false;
                break;
            }
            for (int k = 0; k < psz[j]; ++k)
                cdiffs[csz++] = diffs[j][k];
        }
        if (ok) {
            int cnt = 0;
            for (int j = 0; j < csz; ++j) {
                const auto& p = cdiffs[j];
                unite(p.first, p.second);
                cnt += !used[p.first];
                cnt += !used[p.second];
                used[p.first] = used[p.second] = true;
            }
            for (int j = 0; j < csz; ++j) {
                const auto& p = cdiffs[j];
                cnt -= used[p.first] && father[p.first] == p.first;
                cnt -= used[p.second] && father[p.second] == p.second;
                used[p.first] = used[p.second] = false;
            }
            for (int j = 0; j < csz; ++j) {
                const auto& p = cdiffs[j];
                father[p.first] = p.first;
                father[p.second] = p.second;
            }

            if (cnt <= k) {
                cout << i << '\n';
                return 0;
            }
        }
    }
}