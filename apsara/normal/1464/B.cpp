#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 100100;
const int ooo = 1e9;
const LL oo = (LL) ooo * ooo;
struct Node{
    int l, r, s;
}tr[4 * V];

void init(int id, int l, int r) {
    tr[id].l = l;
    tr[id].r = r;
    tr[id].s = 0;
    if (l == r) return;
    int mid = (l + r) / 2;
    init(id * 2, l, mid);
    init(id * 2 + 1, mid + 1, r);
}

void update(int id, int pos, int v) {
    if (tr[id].l == pos && tr[id].r == pos) {
        tr[id].s = v;
        return;
    }
    int mid = (tr[id].l + tr[id].r) / 2;
    if (pos <= mid) update(id * 2, pos, v);
    else update(id * 2 + 1, pos, v);
    tr[id].s = tr[id * 2].s + tr[id * 2 + 1].s;
}

int read(int id, int l, int r) {
    if (l > r) return 0;
    if (tr[id].l == l && tr[id].r == r) return tr[id].s;
    int mid = (tr[id].l + tr[id].r) / 2;
    if (r <= mid) return read(id * 2, l, r);
    else if (l > mid) return read(id * 2 + 1, l, r);
    else {
        int a = read(id * 2, l, mid);
        int b = read(id * 2 + 1, mid + 1, r);
        return a + b;
    }
}

char s[V];
int x, y;
int main() {
    while (~scanf("%s", s)) {
        scanf("%d%d", &x, &y);
        int n = strlen(s);
        vector<int> pos;
        for (int i = 0; i < n; ++i) if (s[i] == '?') pos.PB(i);
        LL res = oo;
        LL ans = 0;
        init(1, 0, n - 1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                ans += (LL) y * read(1, 0, i - 1);
            }
            if (s[i] == '1') {
                ans += (LL) x * (i - read(1, 0, i - 1));
                update(1, i, 1);
            }
            if (s[i] == '?') {
                ans += (LL) y * read(1, 0, i - 1);
            }
        }
        res = min(res, ans);
        for (int i = 0; i < pos.size(); ++i) {
            ans -= (LL) y * read(1, 0, pos[i] - 1);
            ans -= (LL) x * read(1, pos[i] + 1, n - 1);
            update(1, pos[i], 1);
            ans += (LL) x * (pos[i] - read(1, 0, pos[i] - 1));
            ans += (LL) y * (n - 1 - pos[i] - read(1, pos[i] + 1, n - 1));
            res = min(res, ans);
        }

        ans = 0;
        init(1, 0, n - 1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                ans += (LL) y * read(1, 0, i - 1);
            }
            if (s[i] == '1') {
                ans += (LL) x * (i - read(1, 0, i - 1));
                update(1, i, 1);
            }
            if (s[i] == '?') {
                ans += (LL) x * (i - read(1, 0, i - 1));
                update(1, i, 1);
            }
        }
        res = min(res, ans);
        for (int i = 0; i < pos.size(); ++i) {
            ans -= (LL) x * (pos[i] - read(1, 0, pos[i] - 1));
            ans -= (LL) y * (n - 1 - pos[i] - read(1, pos[i] + 1, n - 1));
            update(1, pos[i], 0);
            ans += (LL) y * read(1, 0, pos[i] - 1);
            ans += (LL) x * read(1, pos[i] + 1, n - 1);
            res = min(res, ans);
        }

        printf("%I64d\n", res);
    }
    return 0;
}

/*
0?1
2 3

?????
13 37

?10?
239 7

01101001
5 7
*/