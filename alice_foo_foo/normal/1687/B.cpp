#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 505;

int a[N], id[N], val[N];
int n, m;

bool cmp(int i, int j) { return val[i] < val[j]; }

int query() {
    cout << "? ";
    for (int i = 1; i <= m; i++) cout << (char)(a[i] + '0');
    cout << endl; int ans; cin >> ans; return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        id[i] = i; a[i] = 1;
        val[i] = query();
        a[i] = 0;
    }
    sort(id + 1, id + m + 1, cmp);
    int las = 0;
    for (int i = 1; i <= m; i++) {
        a[id[i]] = 1;
        int now = query();
        if (now != las + val[id[i]]) a[id[i]] = 0;
        else las = now;
    }
    cout << "! " << las << endl;
    return 0;
}