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

string f(char c) {
    if (c == '>') return "1000";
    if (c == '<') return "1001";
    if (c == '+') return "1010";
    if (c == '-') return "1011";
    if (c == '.') return "1100";
    if (c == ',') return "1101";
    if (c == '[') return "1110";
    if (c == ']') return "1111";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    cin >> n;
    ll ans = 0;
    frab(c, 1, n + 1)
        frab(b, 1, c) {
            ll a = sqrt(c * c - b * b);
            if (a * a + b * b == c * c && a <= b && b <= c)
                ans++;
        }
    cout << ans;

}