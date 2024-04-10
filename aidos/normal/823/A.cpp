#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (int)a.size()
#define forit (it, s)for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define FNAME "a"

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
int n, k;

int main () {

	#ifdef LOCAL
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	cin >> n >> k;
	if(n-1 == k){
		printf("2\n");
		for(int i = 2; i <= n; i++){
			printf("1 %d\n", i);	
		}
		return 0; 
	}
	int st = k + 2;
	int mi = 0;
	int mx=0;
	vector<pii> ans;
	int x = k;
	int y = n - 1;
	
	for(int i = 2; i <= k + 1; i++){
		int z=y/x;
		x--;
		y-=z;
		int la = 1;
		if(mx < z) {
			mi = mx;
			mx = z;
		}
		else if(mi < z) mi = z;
		for(int j = 1; j < z; j++){
			ans.pb(mp(la, st));
			la = st;
			st++;	
		} 
		ans.pb(mp(la, i));
	}
	cout << mx + mi << endl;
	for(int i = 0; i < ans.size(); i++){ 
		printf("%d %d\n", ans[i].f, ans[i].s);
	}
	return 0;
}