#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1'000'007;
const int MOD = 1'000'000'007;

int n;
int a, b, c, d;
char in[N];

void solve()
{
    scanf("%d %d %d %d %s", &a, &b, &c, &d, in);
    n = strlen(in);

    int cnt_a = 0, cnt_b = 0;

    int c_pairs = 0, len = 0;
    char exp = ' ', start = ' ';
    vector <pair <int, int> > vec;

    for (int i = 0; i < n; ++i) {
        if (in[i] == 'A') {
            cnt_a++;
        } else {
            cnt_b++;
        }

        if (in[i] != exp) {
            if (len > 1) {
                int l1 = 0, l2 = 0;
                if (start == 'A') {
                    l1 = len / 2, l2 = (len - 1) / 2;
                } else {
                    l2 = len / 2, l1 = (len - 1) / 2;
                }

                c_pairs += l1;
                vec.push_back({l1, l2});
            }

            exp = in[i];
            len = 0, start = in[i];
        }

        exp = exp == 'A' ? 'B' : 'A';
        len++;
    }

    if (len > 1) {
        int l1 = 0, l2 = 0;
        if (start == 'A') {
            l1 = len / 2, l2 = (len - 1) / 2;
        } else {
            l2 = len / 2, l1 = (len - 1) / 2;
        }

        c_pairs += l1;
        vec.push_back({l1, l2});
    }

    if (cnt_a != a + c + d || cnt_b != b + c + d) {
        puts("NO");
        return;
    }

    sort(vec.begin(), vec.end(), [&](pair <int, int> fa, pair <int, int> fb) {
        int ta = fa.first - fa.second;
        int tb = fb.first - fb.second;
        return make_pair(ta, -ta * fa.second) > make_pair(tb, -tb * fb.second);
    });

    int equal_sum = 0;
    for (auto &[l1, l2]: vec) {
        if (l1 == l2) {
            equal_sum += l1;
        }
    }

    int d_pairs = 0;
    while (d_pairs < d && !vec.empty()) {
        auto [l1, l2] = vec.back();
        vec.pop_back();

        int need = d - d_pairs;
        c_pairs -= l1;
        
        if (need >= l2) {
            d_pairs += l2;
            continue;
        }

        if (l1 < l2 && equal_sum >= need) {
            c_pairs += l1;
            c_pairs -= need;
            d_pairs += need;
            break;
        }
        
        d_pairs += need;
        c_pairs += min(l1, l2) - need;
    }

    if (c_pairs >= c && d_pairs >= d) {
        puts("YES");
        return;
    }

    puts("NO");
}

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}