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
const int maxn = (int)1e6 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;
int n, k;
vector<int> g[200100];
vector<int> ans[200200];
int c[200200];
int cnt[200200];
void solve(){
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	for(int i = 1; i <= k; i++) scanf("%d", &c[i]);
	for(int i = k; i >= 1; i--) {
		for(int j = 0; j < cnt[i]; j++) {
			int l = 1, r = n, res = -1;
			while(l <= r) {
				int mid = (l + r)/2;
				if(ans[mid].size() + 1 <= c[i]) {
					res = mid;
					r = mid-1;
				}
				else l = mid+1;
			}
			ans[res].pb(i);
		}
	}
	while(ans[n].size() == 0) n--;
	cout << n << "\n";
	for(int i =1; i <= n; i++) {
		cout << ans[i].size();
		for(const int &id: ans[i]) {
			cout << " " << id;
		}
		cout << "\n";
	}

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