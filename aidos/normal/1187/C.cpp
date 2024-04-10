#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
int eq[maxn];
int t[maxn];
int l[maxn];
int r[maxn];
int a[maxn];
void solve() {
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        cin >> t[i] >> l[i] >> r[i];
        if(t[i]) {
            for (int j = l[i]; j < r[i]; j++) {
                eq[j] = 1;
            }
        }
    }
    int last=1;
    for(int i = n; i > 0 && last<=n; i--) {
        while(true) {
            a[last] = i;
            last++;
            if(!eq[last-1]) break;
        }
    }
    for(int i = 0; i < k; i++) {
        if(t[i]) continue;
        int ok = 0;
        for(int j = l[i]+1; j <= r[i]; j++) {
            if(a[j] < a[j-1]) ok = 1;
        }
        if(!ok) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for(int i = 1;i <= n; i++) cout << a[i] << " ";
}

int main() {
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