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
int a[11];
int get(int x){
	int sum = 0;
	int cnt = 0;
	while(sum + cnt <= x){
		sum += cnt;
		cnt++;
	}
	return cnt;
}
void solve(){
	for(int i = 0; i < 4; i++){
		scanf("%d", &a[i]);
	}
	int a0 = get(a[0]);
	int a1 = get(a[3]);
	if(a0 * (a0 - 1)/2 != a[0]){
		printf("Impossible\n");
		return;
	}
	if(a1 * (a1 - 1)/2 != a[3]){
		printf("Impossible\n");
		return;
	}
	if(a[1] + a[2] + a[0] + a[3] == 0){
		cout << "0\n";
		return;
	}
	if(a[1] > 0 || a[2] > 0){
	}
	else {
		if(a[0]== 0){
			for(int i = 0; i < a1; i++){
				printf("1");
			}
			return;
		}
		if(a[3] == 0){
			for(int i = 0; i < a0; i++){
				printf("0");
			}
			return;
		}
	}

	if(a[1] + a[2] != a0 * a1){
		printf("Impossible\n");
		return;
	}
	int l = 0;
	int r = 0;
	int x = a[1];
	int y = a[2];
	string ans = "";
	while( l< a0 || r < a1){
		while(l < a0 && x - a1 + r >= 0 && (x - a1 + r) + y == (a0 - l - 1) * (a1-r)){
			ans += "0";
			l++;
			x -= a1 - r;
		}
		while(r < a1 && y - a0 + l >= 0 && (y - a0 + l) + x == (a0 - l) * (a1 - r - 1)){
			ans += "1";
			r++;
			y -= a0 - l;
		}
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