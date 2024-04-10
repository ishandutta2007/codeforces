#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 1e6;
using ld = double;

int n, a[maxn], l[maxn], r[maxn], b[maxn], c[maxn];

void calc(int i) {
    if(l[i] != -1) calc(l[i]);
    if(r[i] != -1) calc(r[i]);
    if(a[i] == 0) b[i] = b[l[i]] & b[r[i]];
    if(a[i] == 1) b[i] = b[l[i]] | b[r[i]];
    if(a[i] == 2) b[i] = b[l[i]] ^ b[r[i]];
    if(a[i] == 3) b[i] = !b[l[i]];
}

void push(int i) {
    if(a[i] == 0 && b[l[i]] == 0 && b[r[i]] == 0) c[l[i]] = c[r[i]] = 1;
    if(a[i] == 1 && b[l[i]] == 1 && b[r[i]] == 1) c[l[i]] = c[r[i]] = 1;
    if(a[i] == 0 && b[l[i]] == 0 && b[r[i]] == 1) c[r[i]] = 1;
    if(a[i] == 0 && b[l[i]] == 1 && b[r[i]] == 0) c[l[i]] = 1;
    if(a[i] == 1 && b[l[i]] == 0 && b[r[i]] == 1) c[l[i]] = 1;
    if(a[i] == 1 && b[l[i]] == 1 && b[r[i]] == 0) c[r[i]] = 1;
    if(l[i] != -1) {
        if(c[i]) c[l[i]] = 1;
        push(l[i]);
    }
    if(r[i] != -1) {
        if(c[i]) c[r[i]] = 1;
        push(r[i]);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n;
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        if(s[0] == 'A') {
            a[i] = 0;
            cin >> l[i] >> r[i]; l[i]--; r[i]--;
        } else if(s[0] == 'O') {
            a[i] = 1;
            cin >> l[i] >> r[i]; l[i]--; r[i]--;
        } else if(s[0] == 'X') {
            a[i] = 2;
            cin >> l[i] >> r[i]; l[i]--; r[i]--;
        } else if(s[0] == 'N') {
            a[i] = 3;
            cin >> l[i]; l[i]--;
        } else {
            a[i] = 4;
            cin >> b[i];
        }
    }
    calc(0);
    push(0);
    for(int i = 0; i < n; i++) if(a[i] == 4) cout << (c[i] ? b[0] : !b[0]);
}