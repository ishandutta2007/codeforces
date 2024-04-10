#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e6 + 3;
const ll INF = 2e9;
const ll N = 1e6 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-6;

ll a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, m;
    cin >> n >> m;
    fr(i, n)
        cin >> a[i + 1];
    ll ad = 0;
    fr(i, m) {
        int typ, x;
        cin >> typ >> x;
        if (typ == 1) {
            int pos;
            cin >> pos;
            swap(x, pos);
            a[pos] = x - ad;
        }
        else if (typ == 2) {
            ad += x;
        }
        else {
            cout << a[x] + ad << endl;
        }
    }
}