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

struct tmp {
    ll x, num;
};

ll b[N];
tmp a[N];
bool used[N];

int main() {
        //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    ll n;
    cin >> n;
    unordered_set <ll> divs;
    while (n > 1) {
        bool fnd = false;
        frab(i, 2, sqrt(n) + 1)
            if (n % i == 0) {
                fnd = true;
                divs.insert(i);
                n /= i;
                break;
            }
        if (!fnd) {
            divs.insert(n);
            n = 0;
            break;
        }
    }
    ll ans = 1;
    for (auto it = divs.begin(); it != divs.end(); it++)
        ans *= (*it);
    cout << ans;

}