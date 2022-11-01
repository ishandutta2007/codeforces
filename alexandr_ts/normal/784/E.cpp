#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 3;
const ll MOD = 10000*10000;
const ll INF = 2e9 + 10;

int g(int a, int b) {
    return a || b;
}

int f(int a, int b) {
    return a ^ b;
}

int h(int a, int b) {
    return a & b;
}

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << f(h(f(a, b), g(c, d)), g(h(b, c), f(a, d)));
}