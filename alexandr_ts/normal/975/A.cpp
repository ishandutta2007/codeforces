#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 1e6 + 10;

char t1[M];

void solve() {
    int n;
    scanf("%d", &n);
    set <vector <int> > s;
    string t;
    for (int i = 0; i < n; i++) {
        scanf("%s", &t1);
        t = t1;
        vector <int> ch(256);
        for (int j = 0; j < t.size(); j++)
                ch[t[j]] = 1;
        s.insert(ch);
    }
    cout << s.size() << endl;
}

int main() {
    //freopen("a.in", "r", stdin);
    solve();
}