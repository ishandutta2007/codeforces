#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const ll INF = 2e12 + 1;
const int ST = 110;
const ld EPS = 1e-12;
const ld PI = acos(-1);

int main() {
    //freopen("input.txt", "r", stdin);
    ll n, m;
    cin >> n >> m;
    frab(i, n + 1, m) {
        bool er = false;
        frab(j, 2, min(i, (ll)sqrt(i) + 1))
            if (i % j == 0)
                er = true;
        if (!er) {
            cout << "NO";
            return 0;
        }
    }
    bool er = false;
    frab(j, 2, sqrt(m) + 1)
        if (m % j == 0)
            er = true;
    if (!er)
        cout << "YES";
    else
        cout << "NO";
}