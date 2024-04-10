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
const ll N = 1e3 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-6;

char a[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    bool sm = false, bg = false, dig = false;
    fr(i, s.size()) {
        if (isdigit(s[i])) dig = true;
        if (islower(s[i])) sm = true;
        if (isupper(s[i])) bg = true;
    }
    if (s.size() >= 5 && dig && sm && bg)
        cout << "Correct";
    else
        cout << "Too weak";
}