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
const ll N = 1e3 + 1;
const ld EPS = 1e-8;

int a[N];
vector <int> ans[N];
int used[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    frab(i, 1, 1 + k) {
        cin >> a[i];
        used[a[i]] = i;
    }
    frab(i, 1, 1 + n * k)
        if (used[i])
            ans[used[i]].pb(i);
    frab(i, 1, 1 + n * k)
        if (!used[i])
            frab(j, 1, 1 + k)
                if (ans[j].size() < n) {
                    ans[j].pb(i);
                    break;
                }
    frab(i, 1, 1 + k)
        sort(ans[i].begin(), ans[i].end());
    frab(i, 1, 1 + k) {
        fr(j, ans[i].size())
            cout << ans[i][j] << " ";cout << endl;}

}