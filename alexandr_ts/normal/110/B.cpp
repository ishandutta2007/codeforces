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

vector <int> a[26];

bool isHappy(int a) {
    while (a > 0) {
        if (a % 10 != 4 && a % 10 != 7)
            return false;
        a /= 10;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    string ans;
    fr(i, n)
        fr(j, 26)
            if (!a[j].size() || isHappy(i - a[j][(int)a[j].size() - 1])) {
                a[j].pb(i);
                ans += (char)('a' + j);
                break;
            }
    cout << ans;
}