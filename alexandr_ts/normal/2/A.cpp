#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define SSTR(x) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e6 + 10;
const ld EPS = 1e-13;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

string s[N];
int t[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int mx = -INF;
    map <string, int> m;
    fr(i, n) {
        cin >> s[i] >> t[i];
        m[s[i]] += t[i];
    }
    for (auto it = m.begin(); it != m.end(); it++)
        mx = max(mx, it->second);
    map <string, int> m1;
    fr(i, n) {
        m1[s[i]] += t[i];
        if (m1[s[i]] >= mx && m[s[i]] == mx) {
            cout << s[i];
            return 0;
        }
    }

}