#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define pll pair<long long, long long>
#define all(s) (s).begin(), (s).end()

ll n, x, h, k;
int main(){
	#ifdef LOCAL
	freopen("a.in", "r",stdin);
	freopen("a.out", "w", stdout);
	#endif      
	cin >> n >> h >> k;
	ll cnt = 0;
	ll timer = 0;
	for(int i = 0; i < n; i++){
		cin >> x;
		if(cnt+x <= h) {
			cnt += x;
		}
		else {
			
			ll y = (cnt - h+x + k - 1)/k;	
			timer += y;
			cnt -= k * 1ll * y;
			if(cnt < 0) cnt = 0;
			cnt += x;
		}
	}
	timer += cnt/k;
	cnt %= k;
	if(cnt>0) timer++;
	cout << timer << endl;

	return 0;
}