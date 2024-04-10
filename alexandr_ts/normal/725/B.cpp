#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 3;

vector <int> a[N];
int cur[N];
vector <int> op;

int f(char c) {
    if (c == 'f') return 1;
    if (c == 'e') return 2;
    if (c == 'd') return 3;
    if (c == 'a') return 4;
    if (c == 'b') return 5;
    if (c == 'c') return 6;
}

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    ll n;
    char c;
    scanf("%lld%c", &n, &c);
    //cout << n << " " << c;
    if (n % 4 == 1 || n % 4 == 2)
        cout << 7 * (n / 2) + (n - 1) / 4 * 2 + f(c);
    else
        cout << 7 * (n / 2 - 1) + (n - 1) / 4 * 2 + f(c);
}