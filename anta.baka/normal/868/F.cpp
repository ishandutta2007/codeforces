#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;

int n, k;
int a[100000];
ll f[21][100000];
ll tot;
int L, R = -1;
int cnt[100001];

void add(int id) {
    tot += cnt[a[id]];
    cnt[a[id]]++;
}

void del(int id) {
    cnt[a[id]]--;
    tot -= cnt[a[id]];
}

void dvig(int l, int r) {
    while(L < l) del(L++);
    while(L > l) add(--L);
    while(R < r) add(++R);
    while(R > r) del(R--);
}

void go(int x, int l, int r, int pl, int pr) {
    if(l > r) return;
    int m = (l + r) / 2, pm;
    f[x][m] = INF;
    for(int i = pl; i <= min(m, pr); i++)
        if(dvig(i, m), f[x][m] > (i != 0 ? f[x - 1][i - 1] : 0) + tot)
            f[x][m] = (i != 0 ? f[x - 1][i - 1] : 0) + tot, pm = i;
    go(x, l, m - 1, pl, pm);
    go(x, m + 1, r, pm, pr);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i], f[0][i] = INF;
    for(int i = 1; i <= k; i++) go(i, 0, n - 1, 0, n - 1);
    cout << f[k][n - 1];
}