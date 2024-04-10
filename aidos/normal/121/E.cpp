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
int s[300][10100];
int x[100100];
int a[100100];
vector<int> c, d;
int lim = 10000;
int K = 1200;
int m;
int good[100100];

void add(int l, int r, int z) {
	int bl = l/K;
	int br = r/K;
	if(bl == br) {
		for(int i = l; i <= r; i++) {
			s[bl][a[i]]--;
			a[i] += z;
			s[bl][a[i]]++;
		}
	}else{
		for(int i = l; i < bl * K + K; i++) {
			s[bl][a[i]]--;
			a[i] += z;
			s[bl][a[i]]++;
		}
		for(int i = bl+1; i < br; i++) x[i]+=z;
		for(int i = br*K; i <= r; i++) {
			s[br][a[i]]--;
			a[i] += z;
			s[br][a[i]]++;
		}
	}
}
int get(int l, int r) {
	int bl = l/K;
	int br = r/K;
	int res = 0;
	if(bl == br) {
		for(int i = l; i <= r; i++) {
			res += good[a[i]+x[bl]];
		}
	}else{
		for(int i = l; i < bl * K + K; i++) {
			res += good[a[i] + x[bl]];
		}
		for(int i = bl+1; i < br; i++) {
			for(int j = 0; j < c.size(); j++) {
				if(c[j] >= x[i]) res += s[i][c[j] - x[i]];
			}
		}
		for(int i = br*K; i <= r; i++) {
			res += good[a[i] + x[br]];
		}
	}
	return res;
}
void solve(){
	d.pb(4);
	d.pb(7);
	while(d.size() > 0){
		vector<int> dd;
		for(int i = 0; i < d.size(); i++) {
			c.pb(d[i]);
			good[d[i]] = 1;
			if(d[i]*10 + 4 <= lim) dd.pb(d[i] * 10 + 4);
			if(d[i]*10 + 7 <= lim) dd.pb(d[i] * 10 + 7);
		}
		d = dd;
	}
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		s[i/K][a[i]]++;
	}
	for(int i = 0; i < m; i++) {
		string s;
		int l, r;
		cin >> s>> l >> r;
		l--;
		r--;
		if(s == "add"){
			int d;
			cin >> d;
			add(l, r, d);
		}else {
			int ans = get(l, r);
			cout << ans << "\n";
		}
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