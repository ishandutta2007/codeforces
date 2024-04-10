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

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
ll n;
int q;
ll go(ll d){
	if(d&1) return (d+1)/2;
	return go(d/2) + d/2;
}
ll get(ll x){
	x--;
	if(x % 2 == 0) return (x/2) + 1;
	x=(x+1)/2;	
	return go(n-x)+x;
}
void solve(){
	scanf("%lld%d", &n, &q);
	for(int i = 0; i < q; i++){
		ll x;
		scanf("%lld", &x);
		printf("%lld\n", get(x));
	}
}
int main () {
	
	int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}