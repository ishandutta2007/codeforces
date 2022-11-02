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

int X, d;
void solve(){
	ll x = 1;
	cin >> X >> d;
	vector<ll> ans;
	for(int i = 30; i > 0; i--){
		int g  = (1<<i)-1;
		while(X >= g){
			for(int j = 0; j < i; j++) ans.pb(x);
			x+=d;
			X -= g;	
		}
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
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