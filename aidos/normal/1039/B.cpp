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

ll n, k;
int getrand(int d){
	return rand() % d;
}

int out(ll l, ll r){
	cout << l << " "<< r << "\n";
	string ans;
	cin >> ans;
	if(ans == "Yes"){
		if(l == r) exit(0);
		return 1;
	}
	return 0;
}
void solve(){
	cin >> n >> k;
	ll l = 1, r = n;
	while(l <= r){
		ll mid = (l + r)/2;
		if(r-l+1<4*k+4){
			int g = getrand(r-l+1);
			out(l+g, l+g);
			l = max(l-k, 1ll);
			r = min(r+k, n);
		}else if(out(l, mid)){
			l = max(l-k, 1ll);
			r = min(mid+k, n);
		}else{
			l = max(mid+1-k, 1ll);
			r = min(r + k, n);
		}
	}
	out(l, r);
}

int main () {
	srand(time(0));
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}