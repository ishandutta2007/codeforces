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
int n;
char c[200100];
int p[111];
void solve(){
	scanf("%d%s", &n, c);
	for(int i = 1; i <= 9; i++) scanf("%d", &p[i]);
	int j = 0;
	while(j < n && p[c[j] - '0'] <= c[j]-'0') j++;
	while(j < n && p[c[j] - '0'] >= c[j]-'0') {
		c[j] = p[c[j]-'0']+'0';
		j++;
	}
	printf("%s", c);
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