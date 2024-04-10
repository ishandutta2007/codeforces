#include <bits/stdc++.h>
#define frab(i, a, b) for (int i = a; i < b; i++)
#define fr(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e6 + 10;
const ll INF = 2e9 + 10;
const ll N = 1e6 + 10;
const ll MOD = 1e9 + 7;

string s[N];

bool ans[N];

ll Hash(string s) {
    ll ans = 0;
    fr(i, s.size())
        ans = ans * 27ll + ll(s[i] - 'a' + 1);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //srand(time(NULL));
    //map <string, int> m;
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n;
    cin >> n;
    fr(i, n) {
        cin >> s[n - i - 1];
    }
    unordered_set <ll> m;
    fr(i, n) {
        ll tmp = Hash(s[i]);
        if (!m.count(tmp)) {
            ans[i] = true;
            m.insert(tmp);
        }
    }
    fr(i, n)
        if (ans[i]) {
            fr(j, s[i].size())
                putchar(s[i][j]);
            putchar(10);
        }
}