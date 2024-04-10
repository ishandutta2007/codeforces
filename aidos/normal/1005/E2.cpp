#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n;
int m;
int a[maxn];
int sumb[maxn];
int sumc[maxn];
int b[maxn];
int c[maxn];
map<int, int> t[maxn];
void add(int x, int y) {
    for(int i = x; i <= 2 * n; i = (i|(i + 1))) {
        for(int j = y; j <= 2 * n; j = (j | (j + 1))) {
            t[i][j]++;
        }
    }
}
int get(int x, int y) {
    int res = 0;
    for(int i = x; i >= 0; i=(i&(i+1)) - 1) {
        for(int j = y; j >= 0; j = (j & (j + 1)) - 1) {
            if(t[i].count(j))
                res += t[i][j];
        }
    }
    return res;
}
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] < m) {
            b[i] = -1;
            c[i] = -1;
        } else if(a[i] == m){
            b[i] = -1;
            c[i] = 1;
        } else {
            b[i] = 1;
            c[i] = 1;
        }
        sumb[i] = sumb[i-1] + b[i];
        sumc[i] = sumc[i-1] + c[i];
    }
    //b[i] + .... + b[j] <= 0
    //c[i] + ..... + c[j] > 0
    int ind = 0;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == m) {
            while(ind < i) {
                add(sumb[ind] + n, sumc[ind] + n);
                ind++;
            }
        }
        ans += get(2 * n, sumc[i] + n - 1) - get(sumb[i] + n - 1, sumc[i] + n - 1);
    }
    cout << ans << "\n";

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