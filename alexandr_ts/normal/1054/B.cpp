#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 1e6 + 10;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    scanf("%d", &n);
    fr(i, n)
        scanf("%d", &a[i]);
    int cur = 0;
    fr(i, n) {
        if (a[i] > cur) {
            cout << i + 1;
            return 0;
        }
        if (a[i] == cur)
            cur++;
    }
    cout << -1;
}