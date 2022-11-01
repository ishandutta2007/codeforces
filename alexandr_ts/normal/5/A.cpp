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
const ld EPS = 1e-8;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll ans = 0;
    string s;
    ll cnt = 0;
    while (getline(cin, s)) {
        if (s[0] == '+' || s[0] == '-') {
            if (s[0] == '+') cnt++;
            else cnt--;
            continue;
        }
        fr(i, s.size())
            if (s[i] == ':')
                ans += max(0ll, cnt) * ((int)s.size() - i - 1);
    }
    cout << ans;

}