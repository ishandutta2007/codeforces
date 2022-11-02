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
int n;
int r[111];
int d[111];
int p[111];
int cmp(int i, int j){
	return d[i] > d[j];
}

int good(int x){
	for(int i = 0; i < n; i++)
		if(r[i] < x) return 0;
	for(int i = 0; i < n; i++)
		d[i] = r[i]-x;
	sort(p, p + n, cmp);
	int sum = 0;
	for(int i = 1; i < n; i++){
		sum += d[p[i]];
	}
	if(sum < d[p[0]]) return 0;
	return 1;
}

int good2(){
	sort(p, p + n, cmp);
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += d[i];
	}
	sum -= d[p[0]];
	return sum >= d[p[0]];
}
void out(int x){
	for(int i = 0; i < n; i++)
		d[i] = r[i]-x;
	
	vector<string> ans;
	printf("%d\n", x);
	while(1){	
		sort(p, p + n, cmp);
		int i1 = p[0], i2 = p[1], i3 = p[2];
		if(d[i1] == 0) break;
		string xx = "";
		for(int i = 0; i < n; i++)
			xx += '0';
		d[i1]--;
		d[i2]--;
		xx[i1] = '1';
		xx[i2] = '1';
		//d[i3]--;
		if(!good2()){
			d[i3]--;
			xx[i3] = '1';
		}
		ans.pb(xx);
	}
	printf("%d\n", (int) ans.size());
	for(int i = 0; i < ans.size(); i++){
		printf("%s\n", ans[i].c_str());
	}
}

void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &r[i]);
		p[i] = i;
	}

	for(int i = 100; i > 0; i--){
		if(good(i)) {
			out(i);
			return;
		}
	}
	printf("0\n");
	for(int i = 0; i < n; i++){
		d[i] = r[i];
	}
	vector<string> ans;
	while(1){
		sort(p, p + n, cmp);
		if(d[p[0]] == 0) break;
		string x = "";
		for(int i = 0; i < n; i++)
			x += '0';
		for(int i = 0; i < n && i < 5; i++){
			if(d[p[i]] > 0) d[p[i]]--;
			x[p[i]] = '1';
		}
		ans.pb(x);
	}
	printf("%d\n", (int) ans.size());
	for(int i = 0; i < ans.size(); i++){
		printf("%s\n", ans[i].c_str());
	}
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}