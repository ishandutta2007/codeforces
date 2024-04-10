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
const int maxn = (int)4e5+20;
const int mod = (int) 1e9 + 7;
const int maxd = (int) 700700;
using namespace std;
int n, m, p;
int a[maxn];
int b[maxn];
map<int, int> M;
int sz;
int cnt[maxn];
vector<int> calc(vector<int> z) {
	vector<int> ans;
	if(z.size() < m) return ans;
	set<int> S;
	for(int i = 0; i < m; i++) {
		cnt[b[i]]++;
		S.insert(b[i]);
	}
	for(int i = 0; i < z.size(); i++) {
		cnt[z[i]]--;
		if(cnt[z[i]] == 0) S.erase(z[i]);
		else S.insert(z[i]);
		if(i >= m) {
			cnt[z[i-m]]++;
			if(cnt[z[i-m]] == 0) S.erase(z[i-m]);
			else S.insert(z[i-m]);
		} 
		if(S.size() == 0) {
			ans.pb(i-m+1);
		}
	}
	for(int i = 0; i < m; i++) cnt[b[i]] = 0;
	for(int i = 0; i < z.size(); i++) cnt[z[i]] = 0;
	return ans;
}
void solve(){
	scanf("%d%d%d", &n, &m, &p);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if(M.count(a[i]) == 0) {
			M[a[i]] = sz;
			sz++;
		}
		a[i] = M[a[i]];
	}
	for(int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		if(M.count(b[i]) == 0) {
			cout << 0 << "\n";
			return;
		}
		b[i] = M[b[i]];
	}
	vector<int> ans;
	for(int i = 0; i < p; i++) {
		vector<int> c, d;
		for(int j = i; j < n; j += p) {
			c.pb(a[j]);
		}
		d = calc(c);
		for(int j = 0; j < d.size(); j++) {
			ans.pb(d[j] * p + i);
		}
	}
	sort(all(ans));
	printf("%d\n", (int)ans.size());
	for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i]+1);
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