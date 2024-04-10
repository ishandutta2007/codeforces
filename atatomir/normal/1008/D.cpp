#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 100011;

int t, ti;
int i, A, B, C;
vector<int> divs;
int cnt[11];

void get_divs(int x) {
    int i;

    for (i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            divs.pb(i);
            divs.pb(x / i);
        }
    }
}

ll comb(ll n, ll k) {
    ll ans, i;

    ans = 1;
    for (i = 0; i < k; i++) ans *= n - i;
    for (i = 1; i <= k; i++) ans /= i;

    return ans;
}

void solve() {
    int i, j, k, conf;
    ll aux, ans = 0;

    sort(divs.begin(), divs.end());
    divs.resize(unique(divs.begin(), divs.end()) - divs.begin());

    memset(cnt, 0, sizeof(cnt));
    for (auto d : divs) {
        conf = 0;
        if (A % d == 0) conf |= 1;
        if (B % d == 0) conf |= 2;
        if (C % d == 0) conf |= 4;
        cnt[conf]++;
    }

    //for (i = 1; i < 8; i++) {
    //    cerr << i << " " << cnt[i] << '\n';
    //}

    for (i = 1; i < 8; i++) {
        for (j = i; j < 8; j++) {
            for (k = j; k < 8; k++) {
                if ((i | j | k) != 7) continue;
                
                if (i != j && j != k) {
                    ans += cnt[i] * cnt[j] * cnt[k];
                    continue;
                }

                if (i == j && j == k) {
                    ans += comb(cnt[i] + 2, 3);
                    continue;
                }

                if (i == j) {
                    if (i == 1 || i == 2 || i == 4) continue;
                    ans += comb(cnt[i] + 1, 2) * cnt[k];
                    continue;
                }

                if (j == k) {
                    if (j == 1 || j == 2 || j == 4) continue;
                    ans += comb(cnt[j] + 1, 2) * cnt[i];
                    continue;
                }
            }
        }
    }

    printf("%lld\n", ans);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &t);
    for (ti = 1; ti <= t; ti++) {
        scanf("%d%d%d", &A, &B, &C);
        divs.clear();
        get_divs(A);
        get_divs(B);
        get_divs(C);

        solve();
    }


    return 0;
}