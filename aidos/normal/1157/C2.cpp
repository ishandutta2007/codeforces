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
int n;
int p[200200];
int d[200200];
int dp[200200];
void solve(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for(int i = 1; i <= n; i++) {
		if(p[i-1] > p[i]) dp[i]=dp[i-1] + 1;
		else dp[i] = 1;
	}
	for(int i = n; i; i--){
		if(p[i+1] > p[i]) d[i]=d[i+1] + 1;
		else d[i] = 1;
	}
	int last = 0;
	string s = "";
	int l = 1, r = n;
	while(l <= r) {
		if(p[l] > last) {
			if(p[r] > last) {
				if(p[l] == p[r]) {
					if(d[l] > dp[r]) {					
						s += "L";
						last = p[l];
						l++;
					}else {
						s += "R";
						last = p[r];
						r--;
					}
				} else 
					if(p[l] < p[r]) {					
						s += "L";
						last = p[l];
						l++;
					}else {
						s += "R";
						last = p[r];
						r--;
					}
			}else {
				s += "L";
				last = p[l];
				l++;
			}
		}
		else if(p[r] > last) {
				s += "R";
				last = p[r];
				r--;
			}
		else break;
	}
	printf("%d\n%s\n", (int) s.size(), s.c_str());
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