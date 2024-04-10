#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

struct state {
    int len, link, cnt;
    map<char, int> nxt;
};

const int MN = 1000005;

state sa[MN * 2];
int sz, lst, n;
string s;

bool cmp(int x, int y) {
    return sa[x].len > sa[y].len;
}

void init() {
    sa[0].len = 0;
    sa[0].link = -1;
    sa[0].cnt = 0;
    sz = 1;
    lst = 0;
}

void append(char c) {
    int cur = sz++;
    sa[cur].len = sa[lst].len + 1;
    sa[cur].cnt = 1;
    int p = lst;
    while (p != -1 && !sa[p].nxt.count(c)) sa[p].nxt[c] = cur, p = sa[p].link;
    if (p == -1) sa[cur].link = 0;
    else {
        int q = sa[p].nxt[c];
        if (sa[p].len + 1 == sa[q].len) sa[cur].link = q;
        else {
            int clone = sz++;
            sa[clone].len = sa[p].len + 1;
            sa[clone].nxt = sa[q].nxt;
            sa[clone].link = sa[q].link;
            sa[clone].cnt = 0;
            while (p != -1 && sa[p].nxt[c] == q) sa[p].nxt[c] = clone, p = sa[p].link;
            sa[cur].link = sa[q].link = clone;
        }
    }
    lst = cur;
}

int32_t main() {
    boost();

    cin >> s;
    init();
    for (char c : s) append(c);
    vector<int> v;
    for (int i = 1; i < sz; i++) v.push_back(i);
    sort(v.begin(), v.end(), cmp);
    for (int p : v) sa[sa[p].link].cnt += sa[p].cnt;
    sa[0].cnt = 0;
    cin >> n;
    while (n--) {
        cin >> s;
        int cur = 0, len = 0;
        for (char c : s) {
            while (cur > 0 && !sa[cur].nxt.count(c)) cur = sa[cur].link, len = sa[cur].len;
            if (sa[cur].nxt.count(c)) cur = sa[cur].nxt[c], len++;
        }
        set<int> vis;
        int ans = 0;
        for (char c : s) {
            while (cur > 0 && !sa[cur].nxt.count(c)) cur = sa[cur].link, len = sa[cur].len;
            if (sa[cur].nxt.count(c)) cur = sa[cur].nxt[c], len++;
            while (cur > 0 && sa[sa[cur].link].len >= s.size()) cur = sa[cur].link, len = sa[cur].len;
            if (!vis.count(cur) && len >= s.size()) ans += sa[cur].cnt, vis.insert(cur);
        }
        printf("%d\n", ans);
    }

    return 0;
}