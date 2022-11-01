#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
typedef long long int64;
typedef long double ld;
const ld eps = 1e-09;
const int inf = 100000000;
const int alph = 37;
const int maxn = 11;

string s[11];
pair <int, int> seg[maxn];
int n;

struct vert {
    int len;
    int link;
    int next[alph];
    int cnt[maxn];
};

vert aut[1100000];
int sz;
int last;

void init() {
    aut[0].len = 0;
    aut[0].link = -1;
    memset(aut[0].next, 255, sizeof(aut[0].next));
    last = 0;
    sz = 1;
}

void extend(char c, int str_num) {
    int cur = sz++;
    aut[cur].cnt[str_num] = 1;
    aut[cur].len = aut[last].len + 1;
    memset(aut[cur].next, 255, sizeof(aut[cur].next));

    int p;
    for (p = last; (p != -1) && (aut[p].next[c] == -1); p = aut[p].link)
        aut[p].next[c] = cur;
    if (p == -1) {
        aut[cur].link = 0;
    }
    else {
        int q = aut[p].next[c];
        if (aut[p].len + 1 == aut[q].len) {
            aut[cur].link = q;
        }
        else {
            int clone = sz++;
            for (int i = 0; i < alph; ++i)
                aut[clone].next[i] = aut[q].next[i];
            aut[clone].len = aut[p].len + 1;
            aut[clone].link = aut[q].link;
            aut[q].link = aut[cur].link = clone;

            for (;(p != -1) && (aut[p].next[c] == q); p = aut[p].link)
                aut[p].next[c] = clone;
        }
    }
    last = cur;
}

vector <pair <int, int> > c;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> s[0];
    
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        cin >> seg[i].first >> seg[i].second;
    }
    
    init();
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < s[i].size(); ++j) {
            extend(s[i][j] - 'a', i);           
        }
        if (i < n) 
            extend('z' - 'a' + (i + 1), i + 1);
    }
    
    c.resize(sz);
    for (int i = 0; i < sz; ++i)
        c[i] = mp(aut[i].len, i);
    sort(c.begin(), c.end());

    for (int i = sz - 1; i >= 0; --i) {
        int link = aut[c[i].second].link;

        for (int j = 0; j < maxn; ++j)
            aut[link].cnt[j] += aut[c[i].second].cnt[j];
    }
    int64 res = 0;
    for (int i = 1; i < sz; ++i)
        if (aut[i].cnt[0]) {
            bool f = true;
            for (int j = 1; j <= n; ++j)
                if ((aut[i].cnt[j] < seg[j].first) || (aut[i].cnt[j] > seg[j].second))
                    f = false;
            if (f)
                res += int64(aut[i].len - aut[aut[i].link].len);
        }
    cout << res << endl;
    return 0;
}