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
string s;
string t;
int n;
int cnt[27];
vector<int> P[27];
int p[22222];
int a[22222];

void rec(int x){
	int d = n-1;
	int sz = 0;
	while(d >= x){
		a[sz++] = p[d];
		d--;
	}
	for(int i = 0; i < x; i++){
		a[sz++] = p[i];
	}
	for(int i = 0; i < n; i++) p[i] = a[i];
}
void solve(){
	cin >> n >> s >> t;
	for(int i = 0; i < s.size(); i++){
		cnt[s[i] - 'a']++;
	}
	for(int i = 0; i < t.size(); i++){
		cnt[t[i] - 'a']--;
	}
	for(int i = 0; i < 26; i++){
		if(cnt[i] != 0){
			printf("-1\n");
			return;
		}
	}
	for(int i = 0; i < n; i++){
		P[t[i] - 'a'].pb(i);
	}
	for(int i = 0; i < n; i++){
		p[i] = P[s[i] - 'a'].back();
		P[s[i] - 'a'].pop_back();
	}
	vector<int> ans;
	for(int i = 1; i < n; i++){
		int pos = 0;
		int pos1 = 0;
		int pos2 = 0;
		for(int j = 0; j < n; j++){
			if(p[j] ==i -1 ) pos1 = j;
			if(p[j] == i) pos2 = j;
		}
		for(int j = 0; j < n; j++){
			if(p[j] == i) {
				pos = j;
			}
		}
		if(pos + 1 < n){
			ans.pb(n - pos - 1);
			rec(pos+1);
		}
		
		if(pos1 < pos2){
			ans.pb(n);
			rec(0);
			int poss = 0;
			for(int j = 0; j < n; j++) if(p[j] == i-1) poss = j;
			rec(poss);
			ans.pb(n-poss);
		}else {
			ans.pb(1);
			rec(n-1);

			int poss = 0;
			for(int j = 0; j < n; j++) if(p[j] == i-1) poss = j;
			rec(poss);
			ans.pb(n-poss);
		}
	}
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++){
		if(i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");

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