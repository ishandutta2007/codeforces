#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef long double ld;
using namespace std;

const int MAXN = 100;
pair<int, int> a[MAXN + 1];
int used[MAXN + 1];

int main() {
    //ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a + 1, a + n);
    reverse(a + 1, a + n);
    vector<pair<int, int> > res;
    used[0] = 1;
    for(int i = 0; i < n; i++) {
        int x = a[i].first;
        if(!used[i])
            break;
        for(int j = i + 1; j < n && x > 0; j++) {
            if(!used[j]) {
                res.push_back({ a[i].second + 1, a[j].second + 1 });
                used[j] = 1;
                x--;
            }
        }
    }
    for(int i = 0; i < n; i++)
        if(!used[i]) {
            cout << -1 << "\n";
            return 0;
        }
    cout << (int)res.size() << "\n";
    for(auto x: res)
        cout << x.first << " " << x.second << "\n";
    return 0;
}