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
const int maxn = (int) 4e6 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int a[maxn];
vector<int> pos;
int h, g;
bool good;
void calc(int v) {
	pos.pb(v);
	if(a[v] == 0) {
		if((v/2) < (1<<g)) good = false;
		return;
	}
	if(a[v*2] > a[v*2+1]) calc(2*v);
	else calc(2*v+1);
}
void solve() {
	scanf("%d%d", &h, &g);
	for(int i = 1; i < (1<<h); i++) {
		scanf("%d", &a[i]);
	}
	vector<int> ans;
	for(int i = 1; i < (1<<g); i++) {
		while(true) {
			good = true;
			pos.clear();
			calc(i);
			if(!good) break;
			for(int j = 0; j+1 < pos.size(); j++) {
				a[pos[j]] = a[pos[j+1]];
			}
			ans.pb(i);
		}
	}
	ll s = 0;
	for(int i = 1; i < (1<<g); i++) {
		s += a[i];
	}
	printf("%lld\n", s);
	for(int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");


	for(int i = 1; i < (1<<h); i++) {
		a[i] = 0;
	}
}

int main () {
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }
    
    return 0;
}