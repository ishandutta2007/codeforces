#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>
#include <fstream>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int tm = 0;

struct Node {
    Node* ch[3] = {0, 0, 0};
    bool term = false;

    int was[2];
};

Node* root = new Node();

void add(char* s) {
    Node* cur = root;
    while (*s) {
        int to = *s - 'a';
        if (cur->ch[to] == 0) {
            cur->ch[to] = new Node();
        }
        cur = cur->ch[to];
        ++s;
    }
    cur->term = true;
}

bool contains(Node* t, char *s, bool wasMiss) {
    if (!t) {
        return false;
    }
    if (t->was[wasMiss] == tm) {
        return false;
    }
    t->was[wasMiss] = tm;
    if (*s == 0) {
        return t->term && wasMiss;
    }
    int to = *s - 'a';
    for (int i = 0; i < 3; i++) {
        if (t->ch[i] == 0) {
            continue;
        }
        if (i == to && contains(t->ch[i], s + 1, wasMiss)) {
            return true;
        }
        if (i != to && !wasMiss && contains(t->ch[i], s + 1, true)) {
            return true;
        }
    }

    return false;
}

char s[666666];

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        add(s);
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", s);
        tm++;
        puts(contains(root, s, false) ? "YES" : "NO");
    }

    return 0;
}