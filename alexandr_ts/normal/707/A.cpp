#include "bits/stdc++.h"
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e3 + 1;
const ll INF = 2e9 + 1;
const ll MOD = 1e9 + 7;

int main() {
    //freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    char c;
    bool ans = false;
    fr(i, n)
        fr(j, m) {
            cin >> c;
            if (c != 'B' && c != 'G' && c != 'W')
                ans = true;
        }
    if (ans)
        cout << "#Color";
    else
        cout << "#Black&White";
}