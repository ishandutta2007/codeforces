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
const int mod = (int) 1e9 + 7;
using namespace std;
int a[200200];
int n;
int p[500200];
vector<int> ans;
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	for(int i = 2; i <= 2 * n; i++){
		if(!p[i]) {
			for(int j = i + i; j <= 2 * n; j += i) p[j] = 1;
		}
	}
	int sum=0;
	p[1] = 1;
	if(a[2]) {
		a[2]--;
		ans.pb(2);
		sum = 2;
	}
	for(int i = 0; a[1] + a[2] > 0; i++) {
		if(sum % 2==0) {
			if(a[1] > 0) {
				sum += 1;
				ans.pb(1);
				a[1]--;
			}
			else {
				ans.pb(2);
				sum += 2;
				a[2]--;
			}
		}else {
			if(a[2] == 0) {
				sum += 1;
				ans.pb(1);
				a[1]--;
			}
			else {
				ans.pb(2);
				sum += 2;
				a[2]--;
			}
		}
	}
	for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
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