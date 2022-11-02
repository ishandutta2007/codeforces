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
string s;
int k;
void solve(){
	cin >> n >> k >> s;
	set<string> S;
	S.insert(s);
	int ans = 0;
	k -= 1;
	for(int i=n-1; k >= 0 && i >= 0; i--) {
		set<string> u;
		for(string x: S){
			string y="";
			for(int j = 0; j < x.size() && u.size() < k; j++) {
				u.insert(y + x.substr(j+1));
				y += x[j];
			}
			if(u.size() == k) break;
		}
		k -= u.size();
		ans += u.size() * (n-i);
		S.swap(u);
	}
	if(k == 0) cout << ans << "\n";
	else cout << -1 << "\n";
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