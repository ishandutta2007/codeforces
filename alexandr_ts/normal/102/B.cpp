#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e2 + 10;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-8;
const int MAX = 5e6 + 1;
const int MAX2 = 1e4;

string f(string s) {
    int sum = 0;
    fr(i, (int)s.size())
        sum += (s[i] - '0');
    string ans;
    while (sum > 0) {
        ans += (char)(sum % 10 + '0');
        sum /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int ans = 0;
    while (s.size() > 1) {
        s = f(s);
        ans++;
    }
    cout << ans;
}