#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

#define lint long long int
using namespace std;

#define lsb(x) ((x) & (-(x)))

const int NMAX = 100000 + 5;

int h[NMAX];

vector <int> all_vals;

struct Op {
    int type;
    int p, x;
    lint v;
} ops[NMAX];

int sz;
int aib_cnt[2 * NMAX];
lint aib_sum[2 * NMAX];

template <class T>
void update(T aib[], int where, T val) {
    for (; where <= sz; where += lsb(where))
        aib[where] += val;
}

template <class T>
T query(T aib[], int where) {
    T ans = 0;
    for (; where; where -= lsb(where))
        ans += aib[where];
    return ans;
}

bool works(lint water, int bound) {
    int cnt = query(aib_cnt, bound);
    lint sum = query(aib_sum, bound);

    return sum + water <= 1LL * (all_vals[bound - 1]) * cnt;
}

long double works2(lint water, int bound) {
    int cnt = query(aib_cnt, bound - 1);
    lint sum = query(aib_sum, bound - 1);

    return (1.0L * sum + water) / cnt;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++ i) {
        cin >> h[i];
        all_vals.push_back(h[i]);
    }


    for (int i = 1; i <= q; ++ i) {
        cin >> ops[i].type;
        if (ops[i].type == 1) {
            cin >> ops[i].p >> ops[i].x;
            all_vals.push_back(ops[i].x);
        }
        else
            cin >> ops[i].v;
    }

    sort(all_vals.begin(), all_vals.end());
    all_vals.resize(unique(all_vals.begin(), all_vals.end()) - all_vals.begin());

    sz = all_vals.size();
    for (int i = 1; i <= n; ++ i) {
        h[i] = lower_bound(all_vals.begin(), all_vals.end(), h[i]) - all_vals.begin() + 1;
        update(aib_cnt, h[i], 1);
        update(aib_sum, h[i], 1LL * all_vals[h[i] - 1]);
    }

    all_vals.push_back(all_vals.back() + 1e9);
    for (int i = 1; i <= q; ++ i)
        if (ops[i].type == 1) {
            update(aib_cnt, h[ops[i].p], -1);
            update(aib_sum, h[ops[i].p], -1LL * all_vals[h[ops[i].p] - 1]);

            h[ops[i].p] = ops[i].x;
            h[ops[i].p] = lower_bound(all_vals.begin(), all_vals.end(), h[ops[i].p]) - all_vals.begin() + 1;

            update(aib_cnt, h[ops[i].p], 1);
            update(aib_sum, h[ops[i].p], 1LL * all_vals[h[ops[i].p] - 1]);
        }
        else {
            int st = 1;
            int dr = sz;
            int ans = sz + 1;
            int mid;

            while (st <= dr) {
                mid = (st + dr) >> 1;
                if (works(ops[i].v, mid)) {
                    ans = mid;
                    dr = mid - 1;
                }
                else
                    st = mid + 1;
            }

            cout << fixed << setprecision(5) << works2(ops[i].v, ans) << '\n';
        }

    return 0;
}