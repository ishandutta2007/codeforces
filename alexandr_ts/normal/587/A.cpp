#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e6 + 10;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const int MOD = 1e9 + 7;

int a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    int n, t;
    cin >> n;
    map <int, int> m;
    fr(i, n) {
        cin >> t;
        a[t]++;
    }
    fr(i, MAX) {
        a[i + 1] += a[i] / 2;
        a[i] %= 2;
    }
    cout << accumulate(a, a + MAX, 0);
}