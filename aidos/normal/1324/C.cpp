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

const int inf = (1ll << 25) - 1;
const int maxn = (int) 3e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
char s[maxn];
int n;
void solve(){
	scanf("%s", s + 1);
	n = strlen(s+1) + 1;
	vector<int> pos;
	pos.pb(0);
	for(int i = 1; i < n; i++) {
		if(s[i] == 'R') pos.pb(i);
	}
	int ans = -1;
	pos.pb(n);
	for(int i = 1; i < pos.size(); i++) {
		ans = max(ans, pos[i] - pos[i-1]);
	}
	printf("%d\n", ans);
}

int main () {
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }
    
    return 0;
}