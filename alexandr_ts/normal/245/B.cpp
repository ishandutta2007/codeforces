#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const ll INF = 2e9;
const ld EPS = 1e-8;
const int MAX = 1e6 + 1;

ll a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    string ans;
    if (s.substr(0, 3) == "ftp") {
        ans += "ftp://";
        s = s.substr(3, (int)s.size() - 3);
    }
    else {
        ans += "http://";
        s = s.substr(4, (int)s.size() - 4);
    }
    for (int i = (int)s.size() - 2; i >= 0; i--)
        if (s[i] == 'r' && s[i + 1] == 'u') {
            ans += s.substr(0, i);
            ans += ".ru/";
            ans += s.substr(i + 2, (int)s.size() - i - 2);
            if (ans[(int)ans.size() - 1] == '/')
                ans = ans.substr(0, (int)ans.size() - 1);
            cout << ans;
            return 0;
        }
}