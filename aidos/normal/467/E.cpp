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
const int maxn = (int) 5e5 + 10;
const int mod = (int) 1e9 + 7;
const int maxd = (int) 700700;
using namespace std;
int n;
map<int, int> m;
int prv[maxn];
vector<int> d;
int a[maxn];
int R[maxn];
int sz = 0;
int last[maxn];
int cnt[maxn];

void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if(m.count(x)==0) {
			m[x] = sz;
			a[i] = sz;
			R[sz] = x;
			prv[i] = -1;
			sz++;
		}else{
			a[i] = m[x];
			prv[i] = last[a[i]];
		}
		last[a[i]] = i;
	}
	int L = 0;
	vector<int> ans;
	set<int> S, F;
	for(int i = 0; i < n; i++) {
		cnt[a[i]]++;
		if(cnt[a[i]] == 4) {
			while(L<=i) {
				cnt[a[L]] = 0;
				L++;
			}
			for(int t = 0; t < 4; t++) ans.pb(a[i]);
			S.clear();
			F.clear();
			continue;
		}
		if(prv[i] < L) {
			F.insert(i);
			continue;
		}
		int P = -1;
		if(S.find(a[i]) != S.end()) {
			for(int j = prv[i] + 1; j < i; j++) {
				if(prv[j] >= L && prv[j] < prv[i]) {
					P = j;
				}
			}
		}
		while(F.size() > 0 && (*(--F.end())) > prv[i]) {
			int h = *(--F.end());
			F.erase(--F.end());
			S.insert(a[h]);
		}
		F.insert(i);
		if(P!=-1) {
			ans.pb(a[P]);
			ans.pb(a[i]);
			ans.pb(a[P]);
			ans.pb(a[i]);
			while(L<=i) {
				cnt[a[L]] = 0;
				L++;
			}
			S.clear();
			F.clear();
		}
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++) {
		printf("%d ", R[ans[i]]);
	}
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