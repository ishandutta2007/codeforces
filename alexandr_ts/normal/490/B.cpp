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
const ll N = 1e3 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-8;

struct tmp {
    int x, pos;
} a[N];

bool cmp(tmp a, tmp b) {
    return abs(a.x) > abs(b.x);
}

char ans[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    map <int, int> s1, s2, m;
    cin >> n;
    fr(i, n) {
        int t1, t2;
        cin >> t1 >> t2;
        m[t1] = t2;
        s1[t1]++;
        s2[t2]++;
    }
    vector <int> ans;
    for (auto it = s1.begin(); it != s1.end(); it++)
        if (!s2.count(it->first))
            ans.pb(it->first);
    ans.pb(m[0]);
    fr(i, n - 2)
        ans.pb(m[ans[(int)ans.size() - 2]]);
    fr(i, ans.size())
        cout << ans[i] << " ";

}