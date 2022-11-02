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
const int mod = (int) 1e9 + 7;
using namespace std;
int a[1111];
int n;
int get(int x, int y){
	if(max(x, y) == 2) return 3;
	return 4;
}
int calc(int x, int y, int z) {
	if(y != 1) return 0;
	if(x == z) return 0;
	return x == 3;
}
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(int i = 2; i <= n; i++){
		if(a[i] == 1) continue;
		if(a[i-1] == 1) continue;
		cout << "Infinite\n";
		return;
	}
	int ans = 0;
	for(int i = 2; i <= n; i++){
		ans += get(a[i-1], a[i]);
	}
	for(int i = 2; i < n; i++) {
		ans -= calc(a[i-1], a[i], a[i+1]);
	}
	cout << "Finite\n"<< ans ;
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