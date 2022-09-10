#include <bits/stdc++.h>

using namespace std;

const int N = 1'000'007;
const int MOD = 1'000'000'007;

int n, k;
int in[N];
int has[N];

vector <int> ans[N];
pair <int, int> occs[N];

void get(int p, int q)
{
    for (int i = 1; i <= p; ++i) {
        ans[i].resize(q + 1);
    }

    int need = p * q;
    int x = 1, y = 1;
    for (int i = k; i >= 1; --i) {
        occs[i].first = min(occs[i].first, min(p, need));
        need -= occs[i].first;

        while (occs[i].first--) {
            ans[x][y] = occs[i].second;
            if (x == p) {
                x = 1, y = (y - 1 + q - p + 2) % q + 1;
            } else {
                x++;
                y = y % q + 1;
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &in[i]);
    }

    sort(in + 1, in + n + 1);

    for (int i = 1; i <= n; ++i) {
        if (in[i] != in[i - 1]) {
            ++k;
            occs[k].second = in[i];
        }

        ++occs[k].first;
    }

    vector <int> lens;
    sort(occs + 1, occs + k + 1);

    for (int i = 1; i <= k; ++i) {
        has[occs[i].first]++;
        if (has[occs[i].first] == 1) {
            lens.push_back(occs[i].first);
        }
    }

    int best_p = 1, best_q = 1;
    for (int p = 1; p * p <= n; ++p) {
        int sum = 0;
        for (auto v: lens) {
            sum += min(v, p) * has[v];
        }

        sum -= sum % p;
        if (sum / p < p) {
            continue;
        }

        if (sum / p * p > best_p * best_q) {
            best_p = p, best_q = sum / p;
        }
    }

    printf("%d\n%d %d\n", best_p * best_q, best_p, best_q);
    get(best_p, best_q);

    for (int i = 1; i <= best_p; ++i) {
        for (int j = 1; j <= best_q; ++j) {
            printf("%d%c", ans[i][j], " \n"[j == best_q]);
        }
    }

    return 0;
}