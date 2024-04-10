/// Alexandr Tsaplin 18.08.16

#include "bits/stdc++.h"
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define TASK_NAME "salesman"

using namespace std;

typedef long long ll;

const ll N = 1e5;
const ll INF = 2e9 + 1;
const ll MOD = 1e9 + 7;

int a[N];
bool used[N];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    int each = 2 * accumulate(a, a + n, 0) / n;
    fr(i, n)
        if (!used[i]) {
            used[i] = true;
            frab(j, i + 1, n)
                if (a[i] + a[j] == each && !used[j]) {
                    cout << i + 1 << ' ' << j + 1 << endl;
                    used[j] = true;
                    break;
                }
        }
}