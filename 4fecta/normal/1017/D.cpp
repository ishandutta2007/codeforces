#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 13, MM = 500005;

int n, m, q, k, a[MN], cnt[1 << MN]; ll val[1 << MN][1500];
string s;

int main() {
    boost();

    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        cin >> s;
        int msk = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') msk |= 1 << j;
        }
        cnt[msk]++;
    }
    for (int i = 0; i < 1 << MN; i++) {
        for (int msk = 0; msk < 1 << MN; msk++) {
            if (!cnt[msk]) continue;
            int res = i ^ msk;
            int sum = 0;
            for (int k = 0; k < n; k++) {
                if (res & (1 << k)) continue;
                sum += a[k];
            }
            val[i][sum] += cnt[msk];
        }
    }
/*    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j <= 60; j++) printf("%d ", val[i][j]);
        printf("\n");
    }*/
    for (int i = 0; i < 1 << MN; i++) {
        for (int j = 1; j < 1500; j++) val[i][j] += val[i][j - 1];
    }
    for (; q > 0; q--) {
        cin >> s >> k;
        int msk = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') msk |= 1 << j;
        }
        printf("%lld\n", val[msk][k]);
    }

    return 0;
}