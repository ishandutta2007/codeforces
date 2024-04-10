
#include <bits/stdc++.h>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;
using namespace std;
int c[5050][5050];
int d[5050][5050];
int f[5050][5050];
int a[5050];
int n;
void solve(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) f[i][i] = d[i][i] = a[i];
    for(int len = 1; len < n; len++){
        for(int i = 0; i+len < n; i++){
            d[i][i+len] = d[i+1][i+len]^d[i][i+len-1];
        }
    }
    for(int len  =1; len < n; len++){
        for(int i = 0; i + len < n; i++){
            f[i][i + len] = max(d[i][i + len], max(f[i+1][i+len], f[i][i+len-1]));
        }
    }
    int q;
    scanf("%d", &q);
    for(int i = 0, l, r; i < q; i++){
        scanf("%d%d", &l, &r);
        printf("%d\n", f[l-1][r-1]);
    }
}

int main () {
    //ios::sync_with_stdio(0); cin.tie(0);
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
        //printf("Case %d: ", i);
        solve();
    }

    return 0;
}