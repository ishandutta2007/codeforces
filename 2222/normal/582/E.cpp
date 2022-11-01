#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int add(int x, int y) { return (x += y) < mod ? x : x - mod; }
int sub(int x, int y) { return (x -= y) < 0 ? x + mod : x; }
int mul(int x, int y) { return (int64_t)x * y % mod; }

void addAnd(int *r, int *p, int *q, int n) {
    if (n == 1) {
        r[0] = add(r[0], mul(p[0], q[0]));
        return;
    }
    n /= 2;
    static int t[1 << 16];
    fill(t + n, t + n * 2, 0);
    addAnd(t + n, p + n, q + n, n);
    for (int i = 0; i < n; ++i) {
        r[i + n] = add(r[i + n], t[i + n]);
        r[i] = sub(r[i], t[i + n]);
        p[i] = add(p[i], p[i + n]);
        q[i] = add(q[i], q[i + n]);
    }
    addAnd(r, p, q, n);
    for (int i = 0; i < n; ++i) {
        p[i] = sub(p[i], p[i + n]);
        q[i] = sub(q[i], q[i + n]);
    }
}

void addOr(int *r, int *p, int *q, int n) {
    reverse(p, p + n);
    reverse(q, q + n);
    reverse(r, r + n);
    addAnd(r, p, q, n);
    reverse(p, p + n);
    reverse(q, q + n);
    reverse(r, r + n);
}

int n, v[16][5];
char s[512], *pos = s;

vector<int> parse() {
    if (*pos == '(') {
        ++pos;
        vector<int> a = parse();
        assert(pos[0] == ')');
        assert(pos[2] == '(');
        char op = pos[1];
        pos += 3;
        vector<int> b = parse();
        assert(*pos == ')');
        ++pos;
        vector<int> c(1 << n);
        if (op == '&' || op == '?')
            addAnd(&c[0], &a[0], &b[0], 1 << n);
        if (op == '|' || op == '?')
            addOr(&c[0], &a[0], &b[0], 1 << n);
        return c;
    }
    vector<int> r(1 << n);
    for (int i = 0; i < 4; ++i) {
        int p = 0;
        for (int j = 0; j < n; ++j)
            p |= v[j][i] << j;
        if (pos[0] == '?' || pos[0] == 'A' + i)
            r[p]++;
        if (pos[0] == '?' || pos[0] == 'a' + i)
            r[p ^ ((1 << n) - 1)]++;
    }
    ++pos;
    return r;
}

int main() {
    gets(s);
    cin >> n;
    int need = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j)
            cin >> v[i][j];
        need |= v[i][4] << i;
    }
    cout << parse()[need] << endl;
    assert(*pos == 0);
    return 0;
}