#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9;
const ll INF = 1e18;

int x, n, k, a[N], pre[N];
map< int, int > cnt;
ll ans;
int main(){
	scanf("%d%d", &n, &k);
	cnt[0]++;
    x = (1<<k) - 1;
    for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		a[i] ^= a[i - 1];
		if(cnt[a[i]] > cnt[a[i] ^ x])
			a[i] ^= x;	
		ans += i - cnt[a[i]];
		//cerr << a[i]  << " " << ans << endl;
		cnt[a[i]]++;
	}
	printf("%lld", ans);
	return 0;
}