#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e2 + 10;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const int MOD = 1e9 + 7;

int a[N][N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    int n = 5;
    fr(i, n) fr(j, n) cin >> a[i][j];
    vector <int> v;
    fr(i, 5) v.pb(i);
    int ans = -INF;
    fr(t, 1000) {
        next_permutation(v.begin(), v.end());
        vector <int> tmp = v;
        int cur = 0;
        fr(j, 5) {
            for (int i = (int)tmp.size() - 1; i >= 1; i -= 2)
                cur += a[tmp[i]][tmp[i - 1]] + a[tmp[i - 1]][tmp[i]];
            tmp.resize(n - j - 1);
            //cout << tmp.size() << endl;
        }
        ans = max(ans, cur);
    }
    cout << ans;
}