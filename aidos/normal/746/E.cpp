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

int n, m;
int a[200200];
int b[200200];

void solve(){
	scanf("%d%d", &n, &m);
	set<int> S1, S2, ans1, ans2;

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] % 2) S1.insert(a[i]);
		else S2.insert(a[i]);
	}
	m = min(m, 500000);
	for(int i = 1; i <= m; i++){
		if(i & 1) S1.insert(i);
		else S2.insert(i);
	}
	if(min(S1.size(), S2.size()) < n/2){
		cout <<-1<<endl;
		return;
	}
	int cnt1 = 0, cnt2 = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] & 1){
			if(cnt1 == n/2)continue;
			if(S1.count(a[i])){
				S1.erase(a[i]);
				b[i] = a[i];
				cnt1++;
			}
		}
		else {
			if(cnt2 == n/2) continue;
			if(S2.count(a[i])){
				S2.erase(a[i]);
				b[i] = a[i];
				cnt2++;
			}
		}
	}
	for(int i =1; i <= n; i++){
		if(b[i]) continue;
		if(cnt1 < n/2){
			b[i] = *S1.begin();
			S1.erase(S1.begin());
			cnt1++;
		}
	}
	for(int i =1; i <= n; i++){
		if(b[i]) continue;
		b[i] = *S2.begin();
		S2.erase(S2.begin());
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		if(a[i] != b[i]) cnt++;
	printf("%d\n", cnt);
	for(int i = 1; i <= n; i++){
		if(i > 1) printf(" ");
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