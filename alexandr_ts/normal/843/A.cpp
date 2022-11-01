#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ld PI = acos(-1);
const ld EPS = 1e-9;
const int M = 1e3 + 5;
const int N = 1e6 + 3;

pair <int, int> a[N];
vector <vector <int> > ans;

bool cmp(pair <int, int> a, pair <int, int> b) {
    return a.second < b.second;
}

bool used[N];

void dfs(int i) {
    vector <int> cur;
    cur.pb(i);
    int j = a[i].second;
    used[i] = true;
    while (j != i) {
        cur.pb(j);
        used[j] = true;
        j = a[j].second;
    }
    ans.pb(cur);
}

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a, a + n);

    fr(i, n)
        if (!used[i])
            dfs(i);

    cout << ans.size() << endl;
    for (auto v: ans) {
        cout << v.size() << " ";
        for (auto t: v)
            cout << t + 1 << " ";
        cout << endl;
    }
}