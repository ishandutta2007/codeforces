#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 1e3;
const ll INF = 2e9 + 10;
const ll N = 2e5 + 10;

ll a[N];

int main() {
    //freopen("sweets.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int mx = 0;
    fr(i, s.size())
        mx += max(s[i] - 'a', 'z' - s[i]);
    if (k > mx) {
        cout << -1;
        return 0;
    }
    string s2;
    fr(i, n) {
        int mx = 0;
        for (char c = 'a'; c <= 'z'; c++)
            if (abs(c - s[i]) > mx)
                mx = abs(c - s[i]);
        if (k >= mx) {
            for (char c = 'a'; c <= 'z'; c++)
                if (abs(c - s[i]) == mx) {
                    s2 += c;
                    k -= abs(c - s[i]);
                    break;
                }
        }
        else
            for (char c = 'a'; c <= 'z'; c++)
                if (abs(c - s[i]) == k) {
                    s2 += c;
                    k = 0;
                    break;
                }
    }
    cout << s2;
}