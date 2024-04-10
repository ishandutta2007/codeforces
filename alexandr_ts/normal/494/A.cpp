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

ll a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int cnt = 0;
    int last = 0;
    fr(i, s.size())
        if (s[i] == '#') last = i, cnt++;
    string t;
    int bal = 0;
    fr(i, s.size())
        if (s[i] == '(') bal++;
        else if (s[i] == ')') bal--;
    if (cnt > bal) {
        cout << -1;
        return 0;
    }
    vector <int> ans;
    fr(i, cnt)
        ans.pb(1);
    ans[(int)ans.size() - 1] += bal - cnt;
    int cur = 0;
    fr(i, s.size())
        if (s[i] == '#') {
            fr(j, ans[cur])
                t += ')';
            cur++;
        }
        else t += s[i];
    int balance = 0;
    fr(i, t.size())
        if (t[i] == '(')
            balance++;
        else {
            balance--;
            if (balance < 0) {
                cout << -1;
                return 0;
            }
        }
    if (!balance)
        fr(i, ans.size())
            cout << ans[i] << endl;
    else
        cout << -1;
}