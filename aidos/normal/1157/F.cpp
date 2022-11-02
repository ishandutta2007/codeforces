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
int n, k;
multiset<int> S;
int a[200200];
int b[200200];
int c[200200];
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		c[a[i]]++;
	}
	n = 200100;
	int ans = 0;
	int l = 1;
	while(l < n) {	
		int sum = 0;
		int st = l;
		while(c[l]>=2) {
			sum += c[l];
			l++;
		}
		ans = max(ans, c[st-1]+c[l] + sum);
		l++;
	}
	l = 1;
	
	while(l < n) {	
		int sum = 0;
		int st = l;
		while(c[l]>=2) {
			sum += c[l];
			l++;
		}
		if(c[l]+c[st - 1] + sum == ans) {
			printf("%d\n", ans);
			for(int i = st-1; i <= l; i++) {
				while(c[i] > 1) {
					printf("%d ", i);
					c[i]--;
				}
			}
			
			for(int i = l; i >= st-1; i--) {
				while(c[i] > 0) {
					printf("%d ", i);
					c[i]--;
				}
			}
			return;
		}
		l++;
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