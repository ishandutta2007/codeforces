#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).end()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int a[2222];
int b[2222];
int c[2222];

struct list {
    list *next, *prev;
    int i, mv, a;

    list(int i, int mv, int a) {
        this->i = i;
        this->mv = mv;
        this->a = a;
        next = prev = 0;
    }
};

int main() {
    scid(n);
    for (int i = 0; i < n; ++i) {
        sci(a[i]);
        --a[i];
    }
    for (int i = 0; i < n; ++i) {
        sci(b[i]);
        --b[i];
        c[b[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        a[i] = c[a[i]];
    }

    list* h = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] != i) {
            int mv = a[i] < i ? -1 : 1;
            if (h == 0) {
                h = new list(i, mv, a[i]);
            } else {
                list* t = new list(i, mv, a[i]);
                t->next = h;
                h->prev = t;
                h = t;
            }
        }
    }
    set<list*> s;
    for (list* cur = h; cur != 0 && cur->next != 0; cur = cur->next) {
        if (cur->mv == 1 && cur->next->mv == -1) {
            s.insert(cur);
        }
    }
    lint len = 0;
    vector<pair<int, int>> ans;
    while (!s.empty()) {
        list* cur = *s.begin();
        list* next = cur->next;
        ans.push_back({cur->i, next->i});
        len += next->i - cur->i;
        swap(cur->i, next->i);
        if (cur->prev != 0) {
            cur->prev->next = next;
        }
        if (next->next != 0) {
            next->next->prev = cur;
        }
        cur->next = next->next;
        next->prev = cur->prev;
        next->next = cur;
        cur->prev = next;
        if (cur == h) {
            h = next;
        }
        if (cur->i == cur->a) {
            if (cur == h) {
                h = h->next;
            } else {
                cur->prev->next = cur->next;
                if (cur->next != 0) {
                    cur->next->prev = cur->prev;
                }
            }
            s.erase(cur);
        }
        if (next->i == next->a) {
            if (next == h) {
                h = h->next;
            } else {
                next->prev->next = next->next;
                if (next->next != 0) {
                    next->next->prev = next->prev;
                }
            }
        }
        if (cur->i != cur->a) {
            if (cur->next == 0 || cur->next->mv != -1) {
                s.erase(cur);
            }
        }
        if (next->i != next->a) {
            if (next->prev != 0 && next->prev->mv == 1) {
                s.insert(next->prev);
            }
        }
        if (cur->i == cur->a && next->i == next->a && next->prev != 0 && cur->next != 0 && next->prev->mv == 1 && cur->next->mv == -1) {
            s.insert(next->prev);
        }
    }
    printf("%d\n", len);
    printf("%d\n", ans.size());
    for (const auto& i : ans) {
        printf("%d %d\n", i.first + 1, i.second + 1);
    }

    return 0;
}