#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 1005
#define INF 101111111111111
using namespace std;
ll cnt[N];
main(){
    FAST;
    ll n, k;
    scanf("%lld %lld", &n, &k);
    for(ll a, i = 0;i<n;i++){
    	scanf("%lld", &a);
    	cnt[a]++;
    }
    ll least = (n>>1) + (n&1);
    for(ll i = 1;i<=k;i++){
    	while(cnt[i] > 1 && least > 0){
    		least--;
    		cnt[i]-=2;
    	}
    }
    for(ll i = 1;i<=k;i++){
    	if(least > 0 && cnt[i] > 0) cnt[i]--, least--;
    }
    ll res = 0;
    for(ll i = 1;i<=k;i++) res += cnt[i];
    printf("%lld\n", n-res);
}