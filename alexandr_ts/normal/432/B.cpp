#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const ll INF = 2e9 + 1;
const int ST = 110;
const ld EPS = 1e-12;
const ld PI = acos(-1);

int home[N], guest[N];

map <int, int> g;

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    fr(i, n) {
        scanf("%d %d", &home[i], &guest[i]);
        g[home[i]]++;
    }
    fr(i, n)
        printf("%d %d\n", n - 1 + g[guest[i]], 2 * (n - 1) - (n - 1 + g[guest[i]]));
}