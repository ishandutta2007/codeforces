#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e6 + 2;
const ld EPS = 1e-8;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    string s1 = "heavy", s2 = "metal";
    vector <int> a;
    fr(i, (int)s.size()) {
        if (s.substr(i, 5) == s1)
            a.pb(1);
        if (s.substr(i, 5) == s2)
            a.pb(2);
        //cout << s.substr(i, 5) << endl;
    }
    int c1 = 0, c2 = 0;
    //fr(i, a.size())
        //cout << a[i] << " ";
    fr(i, a.size())
        if (a[i] == 1) c1++;
        else c2++;
    ll ans = 0;
    fr(i, a.size())
        if (a[i] == 2) c2--;
        else ans += c2;
    cout << ans;

}