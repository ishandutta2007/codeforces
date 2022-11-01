#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-9;
const int M = 1e3 + 2;
const int N = 1e6 + 2;



int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    string s, t;
    int n1, n2;
    cin >> n1 >> n2;
    cin >> s >> t;
    int ans = INF;
    vector <int> answer;
    fr(l, (int)t.size() - (int)s.size() + 1) {
        vector <int> cur;
        fr(i, s.size())
            if (s[i] != t[i + l]) {
                cur.pb(i);
            }
        if (ans > cur.size()) {
            answer = cur;
            ans = cur.size();
        }
    }
    cout << ans << endl;
    fr(i, answer.size())
        cout << answer[i] + 1 << " ";
}