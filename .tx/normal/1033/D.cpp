#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

const int M = 998244353;

llong msqrt(llong x) {
    llong y = max(0., sqrt(x));
    while (y * y < x) {
        y++;
    }
    while (y * y > x) {
        y--;
    }
    if (y * y == x) {
        return y;
    }
    return -1;
}

llong mcrt(llong x) {
    llong y = max(0., pow(x, 1.0 / 3));
    while (y * y * y < x) {
        y++;
    }
    while (y * y * y > x) {
        y--;
    }
    if (y * y * y == x) {
        return y;
    }
    return -1;
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    map<llong, int> cnt;
    llong fn;
    for (int i = 0; i < n; i++) {
        llong x;
        cin >> x;
        cnt[x]++;
        if (i == 0) {
            fn = x;
        }
    }

//    if (n == 500 && fn == 13 * 5) {
//        cout << -31;
//        return 0;
//    }

    vector<llong> a;
    for (auto& p : cnt) {
        a.push_back(p.first);
    }

    vector<llong> gs;
//    set<llong> wg;

    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            llong g = __gcd(a[i], a[j]);
            llong og = g;
            if (g == 1) {
                continue;
            }

            llong k = mcrt(g);
            if (k != -1) {
                g = k;
            } else {
                llong t = msqrt(g);
                if (t != -1) {
                    g = t;
                    t = msqrt(g);
                    if (t != -1) {
                        g = t;
                    }
                }
            }

//            if (g == 0) {
//                cout << "|" << og << "|" << a[i] << "|" << a[j] << endl;
//                return 0;
//            }

            gs.push_back(g);
        }
    }

    sort(gs.begin(), gs.end());
    gs.resize(unique(gs.begin(), gs.end()) - gs.begin());
    vector<int> cgs(gs.size());
    llong ans = 1;
    map<llong, int> ncnt;

//    if (n == 500 && fn == 13 * 5) {
//        cout << gs[0] << "|" << gs[1] << endl;
//        return 0;
//    }

    for (auto& p : cnt) {
        llong x = p.first;
        int i = 0;
        for (llong g : gs) {
            while (x % g == 0) {
                x /= g;
                cgs[i] += p.second;
            }
            i++;
        }

        if (x == p.first) {
            ncnt[x] = p.second;
            continue;
        }

        if (x != 1) {
            ans = ans * (p.second + 1) % M;
        }
    }

    for (int i : cgs) {
        ans = ans * (i + 1) % M;
    }



    for (auto& p : ncnt) {
        llong x = p.first;
        int cnt = p.second;
        int cur = 0;
//        for (llong i = 2; i * i * i <= x; i++) {
//            if (x % i == 0) {
//                int t = 0;
//                while (x % i == 0) {
//                    t++;
//                    x /= i;
//                }
//                if (t == 1) {
//                    cur = (cnt + 1) * (cnt + 1);
//                } else {
//                    cur = t * cnt + 1;
//                }
//                break;
//            }
//            if (i > 2) {
//                i++;
//            }
//        }
        llong k = mcrt(x);
        if (k != -1) {
            cur = 3 * cnt + 1;
        } else {
            k = msqrt(x);
            if (k != -1) {
                llong f = msqrt(k);
                if (f != -1) {
                    cur = 4 * cnt + 1;
                }
            }
        }
        if (cur == 0) {
            llong t = sqrt(x) - 10;
            t = max(1LL, t);
            while ((t + 1) * (t + 1) <= x) {
                t++;
            }
            if (t * t == x) {
                cur = 2 * cnt + 1;
            } else {
                cur = (cnt + 1) * (cnt + 1);
            }
        }

//        cout << cur << "\n";

        ans = ans * cur % M;
    }


    cout << ans;

    return 0;
}//ovouyh