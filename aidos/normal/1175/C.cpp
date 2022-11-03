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
int a[200200];
pii b[400200];
void solve(){
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	int l = 0, r = 1e9;
	int x = -1;
	while(l <= r){
		int mid = (l + r)>>1;
		int i = 0;
		int st = 0;
		for(int j=0; j < n; j++){
			while(i < n && a[i] - mid <= a[j] + mid) {
				b[st++] = mp(a[i]-mid, 1);
				i++;
			}
			b[st++] = mp(a[j]+mid, -1);
		}
		i = 0;
		int cur = 0;
		while(i < 2 * n && cur <= k){
			cur += b[i].s;
			i+=1;
		}
		if(cur > k) {
			r = mid-1;
			x = b[i-1].f;
		}else{
			l = mid+1;
		}
		
	}
	printf("%d\n", x);
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