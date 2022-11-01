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
    ll n, t;
    cin >> n;
    fr(i, n) {
        cin >> t;
        a[t]++;
    }
    vector <ll> ans;
    for (ll i = N; i >= 0; i--) {
        if (b[i] && a[i])
            ans.pb(i), b[i]--, a[i]--;
        while (a[i] > 1)
            ans.pb(i), a[i] -= 2;
        if (a[i])
            b[i - 1]++, a[i] = 0;
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    //fr(i, ans.size())
      //  cout << ans[i] << endl;
    ll answer = 0;
    fr(i, (ll)ans.size() - 1)
        answer += ans[i] * ans[i + 1], i++;
    cout << answer;
}