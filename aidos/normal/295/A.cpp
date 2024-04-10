#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n, m, k;
int l[maxn], r[maxn];
ll d[maxn];
ll a[maxn];
int cntq[maxn];
ll sumq[maxn];
void solve(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i] >> d[i];
    }
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        cntq[x]++;
        cntq[y+1]--;
    }
    for(int i = 1; i <= m; i++) {
        cntq[i] += cntq[i-1];
        sumq[l[i]] += cntq[i] * d[i];
        sumq[r[i] + 1] -= cntq[i] * d[i];
    }
    for(int i = 1; i <= n; i++) {
        sumq[i] += sumq[i-1];
        cout << a[i] + sumq[i] << " ";
    }
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