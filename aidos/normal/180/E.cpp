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
const int maxn = (int)2e5 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;

int n, m, k;
int a[maxn];
int cnt[maxn];

map<int, int> M;
void erase(int len) {
	if(len) {
		M[len]--;
		if(M[len] == 0) M.erase(len);
	}
}
void add(int len) {
	if(len) {
		M[len]++;
	}
}
int getmax() {
	if(M.size()) {
		return (--M.end())->f;
	}
	return 0;
}
void solve(){
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l = 1;
	int cc = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		erase(cnt[a[i]]);
		cnt[a[i]]++;
		add(cnt[a[i]]);
		cc++;
		while(cc - getmax() > k) {
			erase(cnt[a[l]]);
			cnt[a[l]]--;
			add(cnt[a[l]]);
			l++;
			cc--;
		}
		ans = max(ans, getmax());
	}
	cout << ans << "\n";

}
int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d: ", i);
      solve();
    }
    
    return 0;
}