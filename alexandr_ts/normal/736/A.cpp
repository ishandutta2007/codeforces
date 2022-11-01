#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 10;
const int M = 1e7 + 1;;
const ll INF = 2e9 + 10;
const ll MOD = 1000*1000*1000 + 7;
const ld EPS = 1e-9;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll a = 1, b = 1, i = 0;
    while (true) {
        b = a + b;
        a = b - a;
        i++;
        if (b > n) {
            cout << i - 1;
            break;
        }
    }
}