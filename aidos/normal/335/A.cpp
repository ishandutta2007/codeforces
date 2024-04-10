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

const int inf = (1 << 29) - 1;
const int maxn = (int)1e5 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;

int n, k;
string s;
int cnt[29];
void solve(){
	cin >> s >> n;
	for(int i = 0; i < 26; i++) {
		cnt[i] = 0;
		for(int j = 0; j < s.size(); j++)
			if(s[j] == i + 'a') cnt[i]++;
	}
	
	int ans = 1;
	while(ans <= s.size()) {
		int len = 0;
		for(int i = 0; i < 26; i++) {
			len += (cnt[i] + ans-1)/ans;
		}
		if(len <= n) break;
		ans++;
	}
	if(ans > s.size()) {
		cout << -1 << "\n";
		return;
	}
	cout << ans << "\n";
	for(int i = 0; i < 26; i++) {
		int x = (cnt[i] + ans - 1)/ans;
		for(int j = 0; j < x; j++) {
			cout << char(i + 'a');
			n--;
		}
	}
	for(int i = 0; i < n; i++) cout << 'a';
	cout << "\n";
}
int main () {

	int t = 1;
	//scanf("%d", &t);
	for(int i=1; i<=t; i++){
		//printf("Case #%d: ", i);
		solve();
	}
    return 0;
}