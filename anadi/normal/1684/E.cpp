#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1'000'007;
const int MOD = 1'000'000'007;
const ll INF = 1LL * MOD * MOD;

int n, k;
int in[N];
int is[N];

void solve()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i <= n; ++i) {
        is[i] = 0;
    }

    k = min(k, n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &in[i]);
        if (in[i] < n) {
            is[in[i]] = 1;
        }
    }

    int best_mex = 0;
    for (int i = 1; i <= n; ++i) {
        is[i] += is[i - 1];
        if (i - is[i - 1] <= k) {
            best_mex = i;
        }
    }

    vector <int> counter;
    map <int, int> cur;

    for (int i = 1; i <= n; ++i) {
        cur[in[i]]++;
    }

    for (auto &[v, c]: cur) {
        if (v >= best_mex) {
            counter.push_back(c);
        }
    }

    sort(counter.begin(), counter.end());
    reverse(counter.begin(), counter.end());

    while (k > 0 && !counter.empty()) {
        int v = counter.back();
        if (v <= k) {
            k -= v;
            counter.pop_back();
        } else {
            break;
        }
    }

    printf("%lu\n", counter.size());
}

int main()
{
    int cases = 1;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}