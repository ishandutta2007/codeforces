
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
int n, m;

void solve(){
    ll p, q, b;
    scanf("%lld%lld%lld", &p, &q, &b);
    ll d = __gcd(p, q);
    q/=d;
    ll g = __gcd(q, b);
    while(q>1){
        g = __gcd(g, q);
        q/=g;
        if( g == 1) break;
    }
    if(q == 1) printf("Finite\n");
    else printf("Infinite\n");
}

int main () {
    //ios::sync_with_stdio(0); cin.tie(0);
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
        //printf("Case %d: ", i);
        solve();
    }

    return 0;
}