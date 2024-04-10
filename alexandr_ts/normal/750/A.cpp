#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const int M = 1e3 + 2;
const int INF = 2e9 + 10;
const int MOD = 1e9 + 7;

int main() {
    //freopen("a.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    int c = 4 * 60 - k;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (c >= i * 5)
            c -= 5 * i, ans++;
        else
            break;
    cout << ans;

}