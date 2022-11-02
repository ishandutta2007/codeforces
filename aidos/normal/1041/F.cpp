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
int n, m, yy1, yy2;
int cnt[200200];
int ans = 2;
int get(vector<int>&a, vector<int> &b, int d){
	for(int i = 0; i < 2 * d; i++){
		cnt[i] = 0;
	}
	for(int i = 0; i < a.size(); i++){
		cnt[(a[i] + d) % (2 * d)]++;
	}
	for(int i = 0; i < b.size(); i++){
		cnt[b[i] % (2 * d)]++;
	}
	int cur = 0;
	for(int i = 0; i < 2 * d; i++){
		cur = max(cur, cnt[i]);
	}
	return cur;
}

void rec(vector<int> a, vector<int> b, int lev){
	if(a.size() == 0 && b.size() == 0) return;
	if(lev>32) return;
	for(int i = 1; i <= 2; i++){
		ans = max(ans, get(a, b, i));
	}
	vector<int> a1, a2;
	for(int i = 0; i < a.size(); i++){
		if(a[i] % 2 == 1) a1.pb(a[i]/2);
		else a2.pb(a[i] / 2);
	}
	vector<int> b1, b2;
	for(int i = 0; i < b.size(); i++){
		if(b[i] % 2 == 1) b1.pb(b[i]/2);
		else b2.pb(b[i] / 2);
	}
	rec(a1, b1, lev+1);
	rec(a2, b2, lev+1);
}

void solve(){
	scanf("%d%d", &m, &yy1);
	vector<int> a(m);
	for(int i = 0; i < m; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d%d", &n, &yy2);
	vector<int> b(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}
	rec(a, b, 0);
	
	cout << ans << "\n";
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