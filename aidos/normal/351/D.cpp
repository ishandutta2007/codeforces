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
int a[100100];
int n, m;
int diff = 0;
deque<int> d[100100];
vector<pii> Q[100100];
int ans[100100];
int t[100100];
int s[100100];
int last[100100];
void upd(int *t, int p, int val) {
	while(p < maxn) {
		t[p] += val;
		p |= (p+1);
	}
}
int get(int *t, int p) {
	int res = 0;
	while(p>=0) {
		res += t[p];
		p = (p&(p+1)) - 1;
	}
	return res;
}
void solve(){
	cin >> n;
	for(int i =1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for(int i = 0 ; i < m; i++){
		int l,r;
		cin >> l >> r;
		Q[r].pb(mp(i, l));
	}
	for(int i = 1; i <= n; i++){
		if(d[a[i]].size() == 0) {
			d[a[i]].pb(i);
			upd(s, i, 1);
			//upd(t, i, 1);
		}else if(d[a[i]].size() == 1) {
			upd(s, d[a[i]].back(), -1);
			upd(s, i, 1);
			//upd(t, i, 1);
			d[a[i]].pb(i);
		} else {
			upd(s, d[a[i]].back(), -1);
			upd(s, i, 1);
			int L = i - d[a[i]].back();
			d[a[i]].pb(i);
			while(true) {
				int x = d[a[i]].front();
				d[a[i]].pop_front();
				int y = d[a[i]].front();
				if(y-x == L) {
					d[a[i]].push_front(x);
					break;
				}
				if(last[a[i]]) {
					upd(t, last[a[i]], -1);
				}
				upd(t, x, 1);
				last[a[i]] = x;
			}
		}
		for(int j = 0; j < Q[i].size(); j++){
			int ind = Q[i][j].f;
			int l = Q[i][j].s;
			ans[ind] = get(s, i) - get(s, l-1);
			if(get(t, i) - get(t, l-1) == ans[ind]) {
				ans[ind]++;
			}
		}
	}
	for(int i = 0; i < m; i++) cout << ans[i] << "\n";		
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