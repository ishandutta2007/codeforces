#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld EPS = 1e-6;
const ll INF = 1e9 + 10;
const int M = 53;
const int N = 1e6 + 10;

int f(char c) {
    if (c == 'v') return 0;
    if (c == '<') return 1;
    if (c == '^') return 2;
    if (c == '>') return 3;
}

int main() {
    //srand(time(NULL));
    //ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    char a, b;
    int n;
    cin >> a >> b >> n;
    if (n % 2 == 0) {
        cout << "undefined";
        return 0;
    }

    if (n % 4 == 1 && (f(a) + 1) % 4 == f(b) ||
        n % 4 == 3 && f(a) == (f(b) + 1) % 4)
        cout << "cw";
    else
        cout << "ccw";
}