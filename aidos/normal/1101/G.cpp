#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n;
int a[maxn];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x ^ a[i-1];
    }
    if(a[n] == 0) {
        cout << -1 << '\n';
        return;
    }
    int st = 1;
    for(int bit = 0; bit < 30; bit++) {
        int pos = -1;
        for(int i = st; i <= n; i++) {
            if(a[i] & (1<<bit)) {
                pos = i;
            }
        }
        if(pos == -1) continue;
        swap(a[pos], a[st]);
        st++;
        for(int i = st; i <= n; i++) {
            if(a[i] & (1<<bit)) {
                a[i] ^= a[st-1];
            }
        }
    }
    cout << st - 1 << "\n";
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