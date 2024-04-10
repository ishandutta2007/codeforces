#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define read(a) scanf("%d", &a)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const int INF = 2e9 + 1;

int a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    int n, t;
    cin >> n >> t;
    fr(i, 2 * n)
        cin >> a[i];
    sort(a, a + 2 * n);
    double x = min((double)a[0], a[n] / 2.);
    cout << fixed << setprecision(12) << min(3. * x * (double)n, (double)t);
}