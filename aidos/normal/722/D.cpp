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
int a[100100];
int b[100100];
bool ok(int x){
	map<int, int> m;
	for(int i = 0; i < n; i++){
		b[i] = a[i];
		while(b[i] > x){
			b[i]>>=1;
		}
		while(b[i] >= 1 && m.count(b[i])){
			b[i] >>=1;
		}
		if(b[i] == 0) return 0;
		m[b[i]]++;
	}
	
	return 1;
}
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	reverse(a, a + n);
	int l = 1, r = (int) 1e9 + 1, res = -1;
	while(l <= r){
		int mid = (l + r)>>1;
		if(ok(mid)){
			res= mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	ok(res);
	for(int i = 0; i < n; i++){
		if(i) printf(" ");
		printf("%d", b[i]); 
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