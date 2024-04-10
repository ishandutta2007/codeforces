#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) freopen(argv[1], "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s;
    int k;
    cin >> s >> k;
    int n = isz(s);
    int mn = 0;
    int mx = 0;
    int ws = -1;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '?') {
            mn--;
        } else if (c == '*') {
            ws = i;
            mn--;
            mx = 1e9;
        } else {
            mn++;
            mx = min(mx + 1, int(1e9));
        }
    }

    if (mn > k || mx < k) {
        cout << "Impossible\n";
        return 0;
    }


    if (ws == -1) {
        int cur = 0;
        vector<bool> del(n);
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && s[i + 1] == '?') {
                del[i] = true;
            } else if (s[i] == '?') {
                del[i] = true;
            } else {
                cur++;
            }
        }
        for (int i = 0; cur < k; i++) {
            if (s[i] != '?' && del[i]) {
                del[i] = false;
                cur++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!del[i]) {
                cout << s[i];
            }
        }
    } else {
        int cur = 0;
        vector<int> cnt(n);
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && (s[i + 1] == '?' || s[i + 1] == '*')) {
                cnt[i] = 0;
            } else if (s[i] == '?' || s[i] == '*') {
                cnt[i] = 0;
            } else {
                cnt[i] = 1;
                cur++;
            }
        }
        cnt[ws - 1] += k - cur;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                cout << s[i];
            }
        }
    }

    return 0;
}//ydlvwr