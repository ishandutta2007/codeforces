#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e2 + 2;
const ld EPS = 1e-8;

ll c[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin >> s >> t;
    if (s.size() != t.size()) {
        cout << "NO";
        return 0;
    }
    vector <int> ans;
    fr(i, s.size())
        if (s[i] != t[i])
            ans.pb(i);
    if (ans.size() != 2)
        cout << "NO";
    else {
        swap(s[ans[0]], s[ans[1]]);
        if (s == t)
            cout << "YES";
        else
            cout << "NO";
    }
}