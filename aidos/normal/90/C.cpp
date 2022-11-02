#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

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

const int inf = (int)1e9;
const int maxn = (int) 1e5 + 10;

using namespace std;

int m,n, k;
int a[10100];
int suff[10100];
int pref[10100];
void solve(){
    cin >> n >> m >> k;
    for(int i = 0 ; i< n; i++)
        cin >> a[i];
    if(n==1){
        ll x = min(a[0] * 1ll, k * 1ll * m);
        cout << x << endl;
        return;
    }
    if(n % 2 == 0 || (n-1)/2 + 1 > m){
        cout << 0 << endl;
        return;
    }
    ll cur = 0;
    int x = m/((n-1)/2 + 1);
    cur = x;
    cur *= k;
    suff[n] = inf;
    for(int i = n-2; i >= 0; i-=2){
        suff[i] = min(suff[i+2], a[i+1]);
    }
    for(int i = 1; i < n; i += 2){
        pref[i] = a[i-1];
        if(i > 2) pref[i] = min(pref[i], pref[i-2]);
    }
    int ans = 0;
    for(int i = 0; i < n; i+=2){
        int cc = suff[i+1];
        if(i > 0) cc = min(cc, pref[i-1]);
        int g = min(a[i], cc);
        ans = max(ans, g);
    }
    if(ans> cur) ans = cur;
    cout << ans<<endl;

}

int main () {
    #ifdef LOCAL
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}