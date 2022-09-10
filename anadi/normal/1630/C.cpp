#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1'000'007;
const int MOD = 1'000'000'007;

int n;
int in[N];
int first_occ[N], last_occ[N];

int dp[N];
int best[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &in[i]);

        if (!first_occ[in[i]]) {
            first_occ[in[i]] = i;
        }

        last_occ[in[i]] = i;
    }

    vector <PII> occs;
    for (int i = 1; i <= n; ++i) {
        if (first_occ[i] < last_occ[i]) {
            occs.push_back({first_occ[i], last_occ[i]});
        }
    }

    int ans = 0, last = 0;
    vector <PII> vec;
    sort(occs.begin(), occs.end());

    for (auto [x, y]: occs) {
        if (y <= last) {
            continue;
        }

        ans += y - max(last, x - 1);
        last = y;
        vec.push_back({x, y});
    }

    ans -= 2 * vec.size();

    int range = 0;
    for (int i = 0; i < (int)vec.size(); ++i) {
        if (i + 1 == (int)vec.size()) {
            if (vec[i].first < range) {
                ++ans;
            }
            
            break;
        }

        if (vec[i + 1].first > range) {
            if (vec[i].first < range) {
                ++ans;
            }

            range = vec[i].second;
        } else {
            ans += 2;
        }
    }

    printf("%d\n", ans);
    return 0;
}