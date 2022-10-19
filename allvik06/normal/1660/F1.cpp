#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <array>

using namespace std;
#define int long long

struct node {
    node* l = nullptr;
    node* r = nullptr;
    int x, y, sz;

    node(int x) : x(x), y(rand()), sz(1) {}
};

inline int sz(node* a) {
    if (a == nullptr) return 0;
    return a->sz;
}

void update(node* a) {
    a->sz = 1 + sz(a->l) + sz(a->r);
}

node* merge(node* a, node* b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;
    if (a->y < b->y) {
        a->r = merge(a->r, b);
        update(a);
        return a;
    } else {
        b->l = merge(a, b->l);
        update(b);
        return b;
    }
}

pair <node*, node*> split(node* a, int x) {
    if (a == nullptr) return {nullptr, nullptr};
    if (a->x < x) {
        auto now = split(a->r, x);
        a->r = now.first;
        update(a);
        return {a, now.second};
    } else {
        auto now = split(a->l, x);
        a->l = now.second;
        update(a);
        return {now.first, a};
    }
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (0) {
            vector<node *> all(3, nullptr);
            int cur = 0, ans = 0;
            all[0] = new node(0);
            for (int i = 0; i < n; ++i) {
                if (s[i] == '+') ++cur;
                else --cur;
                int o = (cur % 3 + 3) % 3;
                auto now = split(all[o], cur);
                ans += sz(now.second);
                all[o] = merge(now.first, now.second);
                all[o] = merge(all[o], new node(cur));
            }
            cout << ans << "\n";
        } else {
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                int cur = 0;
                for (int j = i; j < n; ++j) {
                    if (s[j] == '+') ++cur;
                    else --cur;
                    if (cur % 3 == 0 && cur <= 0) ++ans;
                }
            }
            cout << ans << "\n";
        }
    }
}