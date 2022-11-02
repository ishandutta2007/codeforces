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
int n, m;
string s[100100];
void solve(){
	cin >> n >> m;
	for(int i=0; i < n + m; i++) cin >> s[i];
	sort(s, s + n + m);
	int cnt =0;
	for(int i = 1; i < n + m; i++) {
		if(s[i] == s[i-1]) cnt++;
	}
	n -= cnt;
	m -= cnt;
	n += (cnt+1)/2;
	m += cnt/2;
	if(n > m) cout << "YES\n";
	else cout << "NO\n";
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