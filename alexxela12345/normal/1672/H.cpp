#undef LOCAL
#ifndef LOCAL
#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif

#include <bits/stdc++.h>
using namespace std;

#include <cassert>

/** Begin fast allocation */
const int MAX_MEM = 2.5e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
	assert((mpos += n) <= MAX_MEM);
	return (void *)(mem + mpos - n);
}
inline void operator delete ( void * ) noexcept { } // must have!
inline void operator delete ( void *, size_t ) noexcept { } // must have!
/** End fast allocation */


typedef long long ll;
typedef long double ldb;

#define endl '\n'

struct mdata {
    vector<pair<int, int>> arr;
    int ans;
};

vector<pair<int, int>> arr;

mdata merge(const mdata &a, const mdata &b) {
    if (a.arr.empty()) {
        return b;
    }
    if (b.arr.empty()) {
        return a;
    }
    arr.clear();
    for (auto el : a.arr) {
        arr.push_back(el);
    }
    int ans = a.ans + b.ans;
    for (auto el : b.arr) {
        if (!arr.empty() && arr.back().first == el.first) {
            arr.back().second += el.second;
        } else {
            arr.push_back(el);
        }
    }
    while (arr.size() > 3) {
        bool was = 0;
        {
            for (int i = 0; i < (int) arr.size(); i++) {
                if (arr[i].second == 0) {
                    arr.erase(arr.begin() + i);
                    i -= 1;
                    continue;
                }
                if (i > 0 && arr[i].first == arr[i - 1].first) {
                    arr[i - 1].second += arr[i].second;
                    arr.erase(arr.begin() + i);
                    i -= 1;
                    continue; 
                }
            }
        }
        for (int i = 1; i + 1 < (int) arr.size(); i += 1) {
            if (arr[i].second == 1 && arr[i - 1].second > 0) {
                was = true;
                arr[i - 1].second -= 1;
                arr[i].second -= 1;
            } 
        }
        if (was) {
        {
            for (int i = 0; i < (int) arr.size(); i++) {
                if (arr[i].second == 0) {
                    arr.erase(arr.begin() + i);
                    i -= 1;
                    continue;
                }
                if (i > 0 && arr[i].first == arr[i - 1].first) {
                    arr[i - 1].second += arr[i].second;
                    arr.erase(arr.begin() + i);
                    i -= 1;
                    continue; 
                }
            }
        }
        was = false;

        }
        for (int i = 1; i + 2 < (int) arr.size(); i += 1) {
            int k = min(arr[i].second, arr[i + 1].second) - 1;
            arr[i].second -= k;
            arr[i + 1].second -= k;
            ans += k;
            if (k != 0) {
                was = 1;
            }
        }
        if (was) {
            continue;
        }
        break;
    }
    return {arr, ans};
}

string s;

vector<mdata> tree;

void build(int v, int l, int r) {
    if (l + 1 == r) {
        tree[v] = {{{s[l] - '0', 1}}, 0};
    } else {
        int m = (l + r) / 2;
        build(2 * v + 1, l, m);
        build(2 * v + 2, m, r);
        tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
    }
}

mdata get(int v, int l, int r, int ql, int qr) {
    if (l >= qr || ql >= r) {
        return {{}, 0};
    }
    if (ql <= l && r <= qr) {
        return tree[v];    
    }
    int m = (l + r) / 2;
    auto a = get(2 * v + 1, l, m, ql, qr);
    auto b = get(2 * v + 2, m, r, ql, qr);
    return merge(a, b);
}

void solve() {
    int n, q;
    cin >> n >> q;
    cin >> s;
    tree.resize(4 * n);
    build(0, 0, n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        auto [arr, ans] = get(0, 0, n, l, r);
        while (arr.size() > 1) {
            bool was = 0;
            {
                vector<pair<int, int>> arr2;
                for (auto el : arr) {
                    if (el.second) {
                        if (!arr2.empty() && arr2.back().first == el.first) {
                            arr2.back().second += el.second;
                        } else {
                            arr2.push_back(el);
                        }
                    }
                }
                arr = arr2;
            }
            if (arr.size() == 1) {
                break;
            }
            for (int i = 1; i + 1 < (int) arr.size(); i += 1) {
                if (arr[i].second == 1 && arr[i - 1].second > 0) {
                    was = true;
                    arr[i - 1].second -= 1;
                    arr[i].second -= 1;
                } 
            }
            if (was)
                continue;
            if (arr[0].second == 1) {
                arr[0].second = 0;
                continue; 
            }
            if (arr.back().second == 1) {
                arr.back().second = 0;
                continue;
            }
            for (int i = 0; i + 1 < (int) arr.size(); i += 1) {
                int k = min(arr[i].second, arr[i + 1].second) - 1;
                arr[i].second -= k;
                arr[i + 1].second -= k;
                if (k != 0) {
                    was = 1;
                    ans += k;
                    break;
                }
            }
            if (was) {
                continue;
            }
            break;
        }
        cout << ans + arr[0].second << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}