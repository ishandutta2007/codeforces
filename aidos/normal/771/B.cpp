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
string s[111];
string ans[111];
string t[111];
int n, k;
void solve(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 9; j++){
			if(i & (1<<j)) s[i] +='a';
			else s[i] += 'b';
		}
	}
	for(int i = 0; i < k-1; i++){
		ans[i] = s[i];
	}
	for(int i = 0; i < n - k+1; i++){
		cin >> t[i];
	}
	for(int i = 0; i < n - k+1; i++){
		if(t[i] == "NO"){
			ans[i + k - 1] = ans[i];
		}
		else ans[i + k-1] = s[i + k - 1];
	}
	for(int i = 0; i < n; i++){
		if(i) cout << " ";
		ans[i][0] += -'a' + 'A';
		cout << ans[i];
	}
	cout << endl;
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