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
int n, m;
int p[100100];
int a[100100];
int is_p[100100];
int mxp[100100];
vector<pii> ans;
void Swap(int i, int j) {
	ans.pb(mp(i, j));
	swap(a[i], a[j]);
	p[a[i]] = i;
	p[a[j]] = j;
}
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		p[a[i]] = i;
	}
	for(int i = 2; i <= n; i++){
		if(!is_p[i]) {
			for(int j = i * 2; j <= n; j+=i) is_p[j] = 1;
		}
	}
	int last = 0;
	for(int i = 2; i <= n; i++){
		if(!is_p[i]) last = i;
		mxp[i] = last;
	}
	for(int i = 1; i <= n; i++) {
		while(p[i] > i) {
			int L = p[i] - i + 1;
			Swap(p[i] - mxp[L] + 1, p[i]);
		}
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].f, ans[i].s);
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