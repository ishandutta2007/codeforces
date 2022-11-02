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
int q;
pii ans[300100];
int c[100100];
void solve(){
	scanf("%d%d", &n, &q);
	deque<int> dq;
	int mi=0;
	for(int i=0; i < n; i++){
		int x;
		scanf("%d", &x);
		dq.pb(x);
		mi=max(mi, x);
	}
	int iter = 0;
	while(dq.front() != mi){
		int a=dq.front();
		dq.pop_front();
		int b=dq.front();
		dq.pop_front();
		dq.push_front(max(a, b));
		dq.pb(min(a, b));
		ans[iter++]=mp(a, b);
	}
	for(int i = 0; i < n; i++){
		int a=dq.front();
		dq.pop_front();
		c[i] = a;
	}
	for(int i  =0;i < q; i++){
		ll d;
		scanf("%lld", &d);
		if(d <= iter) {
			printf("%d %d\n", ans[d-1].f, ans[d-1].s);
		}else{
			d -= iter + 1;
			printf("%d %d\n", c[0], c[d % (n-1) + 1]);
		}
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