#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < (ll)n; i++)
#define frab(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e4 + 10;
const ll INF = 2e9;
const ll ALPH = 300;

int main() {
        //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    int n, k;
    cin >> n >> k;
    fr(i, n) {
        fr(j, n)
            if (i == j) cout << k << " ";
            else
                cout << 0 << " ";
    cout << endl;}
}