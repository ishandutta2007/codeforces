#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

const int N = (int) 27;
const int MAXV = (int) 1e5 * N;
int to[MAXV][2];
int cnt[MAXV];
int sz = 1;
char c[N];

string next() {
    scanf(" %s", c);
    return string(c);
}

string conv(string s) {
    string p = "";
    for (auto c : s) {
        p += ((c - '0') % 2 + '0');
    }
    reverse(all(p));
    while (p.size() < N) p += '0';
    reverse(all(p));
    return p;
}

void add(string s) {
    s = conv(s); 
    int v = 0;
    for (auto c : s) {
        if (!to[v][c - '0']) {
            to[v][c - '0'] = sz++;
        }
        v = to[v][c - '0'];
    }
    cnt[v]++;
}

void del(string s) {
    s = conv(s); 
    int v = 0;
    for (auto c : s) {
        if (!to[v][c - '0']) {
            to[v][c - '0'] = sz++;
        }
        v = to[v][c - '0'];
    }
    cnt[v]--;
}

int q(string s) {
    s = conv(s);
    int v = 0;
    for (auto c : s) {
        if (!to[v][c - '0']) {
            return 0;
        }
        v = to[v][c - '0'];
    }
    return cnt[v];
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        char c;
        scanf(" %c", &c);
        if (c == '+') {
            string s = next();
            add(s);
        } else if (c == '-') {
            string s = next();
            del(s);
        } else {
            string s = next();
            printf("%d\n", q(s));
        }
    }
}