#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1'000'007;
const int MOD = 1'000'000'007;

int n;
int in[N];

int get_best(std::function <bool (int, int)> is_ok)
{
    int len = 0, res = 0;
    for (int i = 2; i <= n; ++i) {
        if (is_ok(in[i - 1], in[i])) {
            len++;
        } else {
            len = 0;
        }

        res = max(res, len);
    }

    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &in[i]);
    }

    int best_len = max(
        get_best([](const int a, const int b) {
            return a < b;
        }),
        get_best([](const int a, const int b) {
            return a > b;
        })
    );

    if (best_len & 1) {
        puts("0");
        return 0;
    }

    int good_lens = 0;
    int cur_len = 0, prv = -1;

    for (int i = 2; i <= n; ++i) {
        int tmp = in[i] < in[i - 1];
        if (tmp == prv) {
            ++cur_len;
        } else {
            cur_len = 1;
        }

        prv = tmp;
        if (cur_len == best_len) {
            ++good_lens;
        }
    }

    if (good_lens >= 3) {
        puts("0");
        return 0;
    }

    int ans = 0;
    for (int i = 2; i < n; ++i) {
        if (in[i] < in[i - 1] || in[i] < in[i + 1]) {
            continue;
        }

        int left = i;
        while (left > 1 && in[left] > in[left - 1]) {
            left--;
        }

        int right = i;
        while(right < n && in[right] > in[right + 1]) {
            right++;
        }

        left = i - left;
        right = right - i;

        if (left < best_len || right < best_len) {
            continue;
        }

        if (left == right) {
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}