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
ll d[100];

void solve(){
	d[0] = 0;
	for(int i = 1; i < 62; i++){
		d[i] = d[i-1] + d[i-1] + (1ll<<(i-1));
	}
	cin >> n;
	n--;
	vector<int> v;
	for(int i = 0; n>0;i++){
		if(n&(1ll<<i)){
			n^=(1ll<<i);
			v.pb(i+1);
		}
	}
	ll ans = 0;
	forit(it, v){
		ans += d[*it-1];
		ans += (1ll<<(*it-1));
	}	
	cout << ans << endl;
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