#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define abs(x) (x > 0 ? x : -x)
  
using namespace std;

const int MAXN = 500000 + 7;
int t[4 * MAXN], d[4 * MAXN];
int pr[MAXN];
int n;

void build(int v, int l, int r) {
    if (r - l == 1) {
        t[v] = 1;
        d[v] = -1;
    } else {
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
        t[v] = t[v * 2 + 1] + t[v * 2 + 2];
        d[v] = -1;
    }
}

void push(int v, int l, int r) {
    if (d[v] != -1) {
        int m = (l + r) / 2;
        t[v * 2 + 1] = (m - l) * d[v];
        t[v * 2 + 2] = (r - m) * d[v];
        d[v * 2 + 2] = d[v * 2 + 1] = d[v];
        d[v] = -1;
    }
}

int get(int v, int l, int r, int tl, int tr) {
    if (tl >= r || tr <= l) {
        return 0;
    } else if (tl >= l && tr <= r) {
        return t[v];
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return get(v * 2 + 1, l, r, tl, tm) + get(v * 2 + 2, l, r, tm, tr);
    }
}

void upd(int v, int l, int r, int tl, int tr) {
    if (tl >= r || tr <= l) {
        return;
    } else if (tl >= l && tr <= r) {
        t[v] = 0;
        d[v] = 0;
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        upd(v * 2 + 1, l, r, tl, tm);
        upd(v * 2 + 2, l, r, tm, tr);
        t[v] = t[v * 2 + 1] + t[v * 2 + 2];
    }
}

int get_r(int v, int l, int r, int ind) {
    if (r - l == 1) {
        return l;
    } else {
        int m = (l + r) / 2;
        push(v, l, r);
        if (t[v * 2 + 1] >= ind) {
            return get_r(v * 2 + 1, l, m, ind);
        } else {
            ind -= t[v * 2 + 1];
            return get_r(v * 2 + 2, m, r, ind);
        }
    }
}

int right(int i) {
    int need = get(0, 0, i + 1, 0, n);
    if (need + 1 > get(0, 0, n, 0, n)) {
        return -1;
    }
    return get_r(0, 0, n, need + 1);
}

int left (int i) {
    int need = get(0, 0, i, 0, n);
    if (need == 0) {
        return -1;
    }
    return get_r(0, 0, n, need);
}

int need(int x) {
    return get(0, x, x + 1, 0, n);
}

int nextInt() {
    char c = getchar();
    int p = 0;
    while (c > '9' || c < '0') {
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        p = p * 10 + (c - '0');
        c = getchar();   
    }
    return p;
}

string nextPSP() {
    string s = "";
    char c = getchar();
    int p = 0;
    while (c != ')' && c != '(') {
        c = getchar();
    }
    while (c == ')' || c == '(') {
        s += c;
        c = getchar();   
    }
    return s;
}
 
main() {
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int m, p;
    string s;
    scanf("%d%d%d\n", &n, &m, &p);
    getline(cin, s);
    stack <int> pos;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            pos.push(i);
        } else if (s[i] == ')') {
            pr[i] = pos.top();
            pr[pos.top()] = i;
            pos.pop();
        }
    }
    build(0, 0, n);
    p--;
    char c;
    for (int i = 0; i < m; i++) {
        scanf(" %c", &c);
        if (c == 'R') {
            p = right(p);
        } else if (c == 'L') {
            p = left(p);
        } else if (c == 'D') {
            int lft = min(p, pr[p]);
            int rght = max(p, pr[p]);
            upd(0, lft, rght + 1, 0, n);
            int to = right(p);
            if (to != -1) {
                p = to;
            } else {
                p = left(p);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (need(i) != 0) {
            printf("%c", s[i]);
        }
    }
    puts("");
}