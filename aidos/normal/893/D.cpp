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

int n, d;
int a[100100];
int b[100100];
int l[100100];
void solve(){
	scanf("%d%d", &n, &d);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	b[n] = d;
	l[n] = -1000*1000*1000-1;
	for(int i = n-1; i >= 0; i--){
		if(a[i] == 0){
			l[i] = max(l[i+1], 0);
			b[i] = b[i+1];
		}
		else if(a[i] > 0){
			b[i] = b[i+1] - a[i];
			l[i] = l[i+1] - a[i];
		}else {
			b[i] = min(b[i+1]-a[i],d);
			l[i] = l[i+1] - a[i];
		}
	}
	int cur = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		
		if(a[i] == 0 && cur < 0){
			cnt++;
			cur = b[i];
		}
		if(a[i] == 0 && cur < 0){
			printf("-1\n");
			return;
		}
		if(cur > d){
			printf("-1\n");
			return;
		}
		cur += a[i];
		if(cur > d){
			printf("-1\n");
			return;
		}
	}
	printf("%d\n", cnt);
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