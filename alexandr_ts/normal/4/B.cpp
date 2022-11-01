#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e5 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const int MOD = 1e9 + 7;

int minl[N], maxl[N], ans[N];

int main() {
    int n, sum;
    cin >> n >> sum;
    fr(i, n) {
        cin >> minl[i] >> maxl[i];
        ans[i] = minl[i];
    }
    int smin = accumulate(minl, minl + n, 0);
    int smax = accumulate(maxl, maxl + n, 0);
    if (sum < smin || sum > smax) {
        cout << "NO";
        return 0;
    }
    int add = sum - smin;
    fr(i, n) {
        ans[i] += min(add, maxl[i] - minl[i]);
        add -= min(add, maxl[i] - minl[i]);
    }
    cout << "YES";
    cout << endl;
    fr(i, n)
        cout << ans[i] << " " ;

}