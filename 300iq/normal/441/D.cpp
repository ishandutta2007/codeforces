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

const int MAXN = (int) 3000 + 7;

vector <int> g[MAXN];
int go[MAXN];
int tin[MAXN];
bool used[MAXN];
int tt;

void kek(int v) {
    while (!used[v]) {
        used[v] = 1;
        tin[v] = tt++;
        v = go[v];
    }
}

int main() {
    int n, k;
    scanf("%d", &n);
    vector <int> a(n);
    for (int &x : a) {
        scanf("%d", &x);
        x--;
    }
    scanf("%d", &k);
    k = n - k;
    for (int i = 0; i < n; i++) {
        go[i] = a[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) kek(i), cnt++;
    }
    memset(used, 0, sizeof used);
    if (cnt > k) {
        printf("%d\n", cnt - k);
        kek(0);
        for (int i = 1; i < n && cnt > k; i++) {
            if (!used[i]) {
                kek(i);
                printf("%d %d ", 1, i + 1);
                cnt--;
            }
        }
        puts("");
    } else {
        printf("%d\n", k - cnt);
        for (int i = 0; i < n; i++) {
            memset(used, 0, sizeof used);
            memset(tin, 0, sizeof tin);
            kek(i);
            int p = tin[i];
            for (int j = i + 1; j < n && cnt < k; j++) {
                if (j != i && tin[j] >= p) {
                    printf("%d %d ", i + 1, j + 1);
                    p = tin[j];
                    cnt++;
                    swap(go[i], go[j]);
                }
            }
        }
        puts("");
    }
}