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

int a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    cin>> n;
    fr(i, n)
        cin >> a[i];
    int ans = a[0] + n;
    int curh = a[0];
    frab(i, 1, n) {
        ans++;
        if (a[i] < curh) {
            ans += curh - a[i];
            curh = a[i];
        }
        else if (a[i] > curh) {
            ans += a[i] - curh;
            curh = a[i];
        }
    }
    cout << ans;
}