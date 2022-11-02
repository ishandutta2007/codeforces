#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
int a[maxn];
void solve(){
    cin >> n;
    memset(a, -1, sizeof a);
    for(int i = 0; i < n; i++) {
        int x, k;
        cin >> x >> k;
        if(a[k] < x - 1) {
            cout << "NO\n";
            return;
        }
        a[k] = max(a[k], x);
    }
    cout <<"YES\n";
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