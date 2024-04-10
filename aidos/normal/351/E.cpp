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
#include <bitset>
#include <unordered_map>

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

const int inf = 100100;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
int a[2020];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = abs(a[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int x = 0, y = 0;
		for(int j =0;j < n; j++){
			if(a[i] > a[j]) {
				if(i > j) x++;
				else y++;
			}
		}
		ans += min(x, y);
	}
	cout << ans << "\n";
	
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