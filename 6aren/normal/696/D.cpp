#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

struct Trie {
    char pch;
    int go[26];
    int nx[26];
    int p;
    int link = -1;
    int finish = 0;
    int val = -1;

    Trie(int p = 0, char pch = '$') : p(p), pch(pch) {
        memset(go, -1, sizeof(go));
        memset(nx, -1, sizeof(nx));
    }
};

vector<Trie> tr(1);

void insert(string s, int val) {
    int cur = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (tr[cur].nx[c] == -1) {
            tr[cur].nx[c] = tr.size();
            tr.pb(Trie(cur, ch));
        }
        cur = tr[cur].nx[c];
    }
    tr[cur].finish += val;
}

int go(int k, char pch);

int getlink(int k) {
    if (tr[k].link == -1) {
        if (k == 0 || tr[k].p == 0) tr[k].link = 0;
        else tr[k].link = go(getlink(tr[k].p), tr[k].pch);
    }
    return tr[k].link;
}

int go(int k, char pch) {
    int c = pch - 'a';
    if (tr[k].go[c] == -1) {
        if (tr[k].nx[c] != -1) tr[k].go[c] = tr[k].nx[c];
        else if (k != 0) tr[k].go[c] = go(getlink(k), pch);
        else tr[k].go[c] = 0;
    }
    return tr[k].go[c];
}

int calc(int k) {
    if (tr[k].val != -1) return tr[k].val;
    if (k == 0) tr[k].val = tr[k].finish;
    else tr[k].val = tr[k].finish + calc(getlink(k));
    return tr[k].val;
}

const int N = 205;
const long long oo = 1e18;

int n, l;
string s[N];
int a[N];

struct Matrix {
    long long a[205][205];

    Matrix() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) a[i][j] = -oo;
        }
    }
};

Matrix mult(Matrix &a, Matrix &b) {
    Matrix res;
    for (int i = 0; i < tr.size(); i++) {
        for (int j = 0; j < tr.size(); j++) {
            for (int k = 0; k < tr.size(); k++) {
                res.a[i][j] = max(res.a[i][j], a.a[i][k] + b.a[k][j]);
            }
        }
    }
    return res;
}

Matrix powr(Matrix &t, long long y) {
    Matrix res;
    for (int i = 0; i < tr.size(); i++) res.a[i][i] = 0;
    if (y == 0) return res;
    res = powr(t, y / 2);
    res = mult(res, res);
    if (y % 2) res = mult(res, t);
    return res;
}

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n >> l;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        insert(s[i], a[i]);
    }
    Matrix mat;
    for (int i = 0; i < tr.size(); i++) {
        for (int j = 0; j < 26; j++) {
            int u = go(i, 'a' + j);
            int val = calc(u);
            mat.a[u][i] = val;
        }
    }
    Matrix mat2 = powr(mat, l); 
    // for (int i = 0; i < tr.size(); i++) {
    //     for (int j = 0; j < tr.size(); j++) {
    //         cout << mat2.a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    long long ans = 0;
    for (int i = 0; i < tr.size(); i++) ans = max(ans, mat2.a[i][0]);
    cout << ans;
    return 0;
}