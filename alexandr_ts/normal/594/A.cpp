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
const ll MAX = 1e6 + 1;
const ll ALPH = 300;
const ld PI = acos(-1);
const ll MOD = 1e9 + 7;

int a[N];

int main() {
    //setlocale(LC_CTYPE,"Russian");
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    srand(time(NULL));
    cout << fixed << setprecision(12);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);
    int q = (n - 1) / 2;
    int ans = INF;
    fr(i, q + 1)
        ans = min(ans, a[n + i - q - 1] - a[i]);
    cout << ans;

}