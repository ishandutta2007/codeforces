#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 5;
const int M = 500 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e9 + 10;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    if (a == b) {
        cout << -1;
    }
    else
        cout << max(a.size(), b.size());
}