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
bool isprime(ll x){
	for(int i = 2; i * 1ll * i <= x; i++)
		if(x % i == 0) return 0;
	return 1;
}
void solve(){
	cin >> n;
	if(isprime(n)){
		cout << 1 << endl;
		return;
	}
	if(n % 2 == 0){
		cout << 2 << endl;
		return;
	}
	if(isprime(n-2)){
		cout << 2 << endl;
		return;
	}
	cout << 3 << endl;

}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}