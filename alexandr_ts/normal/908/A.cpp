#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ll N = 1e6 + 10;


int main() {
    //freopen("a.in", "r", stdin);
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < (int)s.size(); i++)
        if (isdigit(s[i]) && (s[i] - '0') % 2 == 1)
            ans++;
        else if (s[i] == 'a' || s[i] == 'i' || s[i] == 'o' || s[i] == 'e' || s[i] == 'u')
            ans++;

    cout << ans;


}