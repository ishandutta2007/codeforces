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
#define N 200005
#define INF 101111111111111
using namespace std;
ll a[N];
ll blocks[N], blc = 0;
main(){
    FAST;
    ll q;
    scanf("%lld", &q);
    while(q--){
    	ll n, k;
    	blc = 0;
    	scanf("%lld %lld", &n, &k);
    	for(ll i =0;i<n;i++){
    		scanf("%lld", &a[i]);
    		if(a[i]%2 == 1) blocks[blc++] = i;
    	}
    	if(blc > 0  && blocks[blc-1] != n-1) blocks[blc-1] = n-1;
    	if(blc < k || (blc - k) %2 == 1){
    		printf("%s\n", "NO");
    	}else{
    		printf("%s\n", "YES");
    		for(ll i = blc-k; i<blc;i++) printf("%lld ", blocks[i]+1);
    		printf("\n");
    	}
    }
}