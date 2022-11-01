#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e6 + 10;
const ll INF = 2e9 + 10;
const ll N = 2e6 + 10;
const ll MOD = 1e9 + 7;

string s[N];

bool fnd[N], used[N];
int prv[N], nxt[N];

string f(int i) {
    string ans;
    int i1 = i;
    while (i1) {
        ans = (char)i1 + ans;
        used[i1] = true;
        i1 = prv[i1];
    }
    //cout << ans << endl;
    int i2 = i;
    while (i2) {
        if (i2 != i)
            ans += (char)i2;
        used[i2] = true;
        i2 = nxt[i2];
    }
    //cout << ans << endl << endl;
    return ans;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    fr(i, n)
        cin >> s[i];
    fr(i, n)
        fr(j, s[i].size()) {
            fnd[s[i][j]] = true;
            if (j)
                prv[s[i][j]] = s[i][j - 1];
            if (j + 1 < s[i].size())
                nxt[s[i][j]] = s[i][j + 1];
        }
    string ans;
    frab(i, 'a', 'z' + 1)
        if (fnd[i] && !used[i]) {
            ans += f(i);
        }
    cout << ans;
}