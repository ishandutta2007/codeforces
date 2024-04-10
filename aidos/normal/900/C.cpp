#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
int a[maxn];
int t[maxn];
int b[maxn];
void upd(int pos) {
    while(pos <= n) {
        t[pos]++;
        pos |= pos + 1;
    }
}
int get(int pos) {
    int res = 0;
    while(pos >= 0) {
        res += t[pos];
        pos = (pos & (pos + 1)) - 1;
    }
    return res;
}
void solve() {
    cin >> n;
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        b[x] = i;
        int c = get(x);
        if(c == i-2){
            a[mx]--;
        } else if(c == i-1) {
            a[x]++;
        }
        upd(x);
        mx = max(mx, x);
    }
    cout << min_element(a + 1, a + n + 1) - a << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}