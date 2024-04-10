#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 2e5 + 10;

char s1[N];
vector <int> ans[N];

int main() {
    //freopen("a.in", "r", stdin);
    string s;
    scanf("%s", &s1);
    s = s1;
    int n = s.size();

    int cnt0 = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '0')
            cnt0++;
    int cnt1 = n - cnt0;
    int cnt = cnt0 - cnt1;
    if (cnt <= 0) {
        cout << -1;
        return 0;
    }

    set <int> s0, s1;
    for (int i = 0; i < cnt; i++)
        s0.insert(i);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (s0.size() == 0) {
                cout << "-1";
                return 0;
            }
            int j = *s0.begin();
            s0.erase(j);
            ans[j].pb(i);
            s1.insert(j);
        }
        else {
            if (s1.size() == 0) {
                cout << -1;
                return 0;
            }
            int j = *s1.begin();
            s1.erase(j);
            s0.insert(j);
            ans[j].pb(i);
        }
    }

    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << ans[i].size() << " ";
        for (auto t: ans[i])
            cout << t + 1 << " ";
        cout << endl;
        assert(ans[i].size());
    }
}