#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e5 + 1;
const ll INF = 2e9;
const ll MAX = 1e6 + 1;
const ll ALPH = 300;
const ld PI = acos(-1);
const ll MOD = 1e9 + 7;

string s[N];

int main() {
    //setlocale(LC_CTYPE,"Russian");
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    srand(time(NULL));
    cout << fixed << setprecision(12);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    fr(i, n)
        cin >> s[i];
    int ans = 0;
    for (char c1 = 'a'; c1 <= 'z'; c1++)
        for (char c2 = 'a'; c2 <= 'z'; c2++) {
            bool er = false;
                int curans = 0;
            fr(i, n) {
                er = false;
                fr(j, s[i].size())
                    if (s[i][j] != c1 && s[i][j] != c2)
                        er = true;
                if (!er)
                    curans += s[i].size();
            }
            ans = max(ans, curans);
        }
    cout << ans;

}