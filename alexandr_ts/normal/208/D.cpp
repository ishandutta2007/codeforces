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

ll a[N], b[N], ans[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    fr(i, 5)
        cin >> b[i];
    ll balance = 0;
    fr(i, n) {
        balance += a[i];
        bool bought = true;
        while (bought) {
            bought = false;
            for (int j = 4; j >= 0; j--)
                if (!bought && balance >= b[j]) {
                    bought = true;
                    ans[j] += balance / b[j];
                    balance = balance % b[j];
                    break;
                }
        }
    }
    fr(i, 5)
        cout << ans[i] << " ";
    cout << endl << balance;


}