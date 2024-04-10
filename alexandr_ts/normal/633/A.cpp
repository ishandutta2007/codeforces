#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e4 + 10;
const ll INF = 2e9 + 10;
const ll N = 2e5 + 10;
const ll MOD = 1e9 + 7;


int main() {
    //freopen("sweets.in", "r", stdin);
    int a, b, c;
    cin >> a >> b >> c;
    fr(i, c + 1) {
        int j = (c - i * a) / b;
        if (i >= 0 && j >= 0 && i * a + j * b == c)
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";

}