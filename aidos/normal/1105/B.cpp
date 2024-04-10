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

int n, k;
char s[200200];
int ans[123];
void solve(){
	scanf("%d%d%s", &n, &k, s);
	int len= 0;
	char last = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == last) {
			last = s[i];
			len++;
		}
		else {
			last = s[i];
			len = 1;
		}
		if(len == k) {
			ans[last - 'a']++;
			last = 0;
		}
	}
	cout << *max_element(ans, ans + 27);
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