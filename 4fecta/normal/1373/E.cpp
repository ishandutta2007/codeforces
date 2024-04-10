#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int t, n, k;

string build(int sum, int lst, int free, int nines) {
    string ret;
    int cur = 0;
    for (int i = 0; i < nines; i++) ret += "9", cur += 9;
    if (cur > sum) return "$";
    if (sum - cur < lst) {
        if (!free) return "$";
        ret += to_string(sum - cur);
        return ret;
    }
    ret += to_string(lst), cur += lst;
    if (!free) {
        if (sum - cur < 9) {
            ret = to_string(sum - cur) + ret;
            return ret;
        }
        ret = "8" + ret, cur += 8;
    }
    while (sum - cur > 9) ret = "9" + ret, cur += 9;
    ret = to_string(sum - cur) + ret;
    return ret;
}

int fpow(int b, int p) {
    int ret = 1;
    for (int i = 1; i <= p; i++) ret *= b;
    return ret;
}

bool check(int sum, string &st, int k) {
    int x = stoll(st);
    int ret = 0;
    for (int i = x; i <= x + k; i++) {
        string tmp = to_string(i);
        for (char c : tmp) ret += c - '0';
    }
    return ret == sum;
}

int32_t main() {
    boost();

    cin >> t;
    main:
    while (t--) {
        cin >> n >> k;
        int cnt = k + 1, sum = k * (k + 1) / 2;
        if ((n - sum) % cnt == 0) {
            int req = (n - sum) / cnt;
            string ans = build(req, 9 - k, 1, 0);
            //if (req == 0) ans = "0";
            if (ans != "$") {
                //assert(ans == "0" || ans[0] != '0');
                //if (!check(req, ans, k)) goto fall;
                printf("%lld\n", stoll(ans));
                goto main;
            }
        }
        fall:
        for (int nin = 1; nin < 200; nin++) {
            int nine = nin * 9;
            for (int i = 0; i <= k; i++) {
                if ((n - sum + i * nine) % cnt) continue;
                int req = (n - sum + i * nine) / cnt;
                //if (req < 0) continue;
                string ans = build(req, 9 - k + i, 0, nin - 1);
                //if (req == 0) ans = "0";
                if (ans == "$") continue;
                //printf("%lld %lld %lld ", nin, i, i * nine);
                //assert(ans == "0" || ans[0] != '0');
                //if (!check(req, ans, k)) continue;
                printf("%lld\n", stoll(ans));
                goto main;
            }
        }
        printf("-1\n");
    }

    return 0;
}