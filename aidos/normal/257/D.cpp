#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n;
int a[maxn];

char u[maxn];
void solve() {
    cin >> n;
    ll sum = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = n - 1; i >= 0; i--) {
        if(abs(sum + a[i]) < abs(sum - a[i])) {
            sum += a[i];
            u[i] = '+';
        } else {
            sum -= a[i];
            u[i] = '-';
        }
    }
    if(sum < 0) {
        for(int i = 0; i < n; i++) u[i] = u[i] == '+' ? '-': '+';
    }
    cout << u << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}