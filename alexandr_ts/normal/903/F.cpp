#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const int N = 1e4 + 10;

string s[N];

char t[4][4];
int a[N];

map <vector <int>, int> m;

int f(vector <int> v) {
    if (*max_element(v.begin(), v.end()) < 0) return 0;
    if (m.count(v)) return m[v];
    auto mx = *max_element(v.begin(), v.end());
    int i1 = -1;
    for (int j = 0; j < 4; j++)
        if (v[j] >= mx)
            i1 = j;
    if (s[v[i1]][i1] == '.') {
        auto v2 = v;
        v2[i1]--;
        int ans = f(v2);
        //for (auto t: v) cout << t << " ";cout << ", ans!!: " << ans << endl;
        m[v] = ans;
        return ans;
    }
    int ans = INF;
    for (int pos = 0; pos < 4; pos++)
        for (int i = 1; i <= 4; i++) {
            auto v2 = v;
            //for (int j = i1; j >= max(0, i1 - i + 1); j--)
            int newval = v2[i1] - i;
            for (int j = max(0, pos - i + 1); j <= pos; j++)
                v2[j] = min(v2[j], newval);
            if (v2 != v)
                ans = min(ans, f(v2) + a[i - 1]);
        }
    if (ans < INF) {
        m[v] = ans;
        //for (auto t: v) cout << t << " ";cout << ", ans: " << ans << endl;
        return ans;
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            s[i][j] += '0';
    for (int i = 0; i < 4; i++)
        cin >> a[i];

    string t2;
    for (int i = 0; i < 4; i++) {
        cin >> t2;
        for (int i1 = 0; i1 < n; i1++)
            s[i1][i] = t2[i1];
    }
    for (int i = 2; i >= 0; i--)
        a[i] = min(a[i], a[i + 1]);

    cout << f({n - 1, n - 1, n - 1, n - 1});
}