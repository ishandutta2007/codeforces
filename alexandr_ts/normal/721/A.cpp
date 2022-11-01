#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int M = 301;
const int INF = 2e9 + 10;
const int MOD = 1e9 + 7;



int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <int> ans;
    int cur = 0;
    fr(i, n) {
        if (s[i] == 'W') {
            if (cur)
                ans.pb(cur);
            cur = 0;
        }
        if (s[i] == 'B') {
            cur++;
        }
        if (i == n - 1 && s[i] == 'B')
            ans.pb(cur);
    }
    cout << ans.size() << endl;
    for (auto it: ans)
        cout << it << " ";

}