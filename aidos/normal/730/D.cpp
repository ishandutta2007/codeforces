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
ll r;
int l[200100];
int t[200100];

vector<ll>ans;
ll k = 0;
void solve(){
	scanf("%d%I64d", &n, &r);
	for(int i = 0; i < n; i++)
		scanf("%d", &l[i]);
	for(int i = 0; i < n; i++){
		scanf("%d", &t[i]);
	}
	ll cur_time = 0, ost = 0;
	ll xx = 0;
	int mx = 100000;
	for(int i = 0; i < n; i++){
		if(t[i] < l[i]){
			printf("-1\n");
			return;
		}
		if(ost >= l[i]){
			ost -= l[i];
			cur_time += l[i];
		}
		else {
			cur_time += ost;
			l[i] -= ost;
			t[i] -= ost;
			ost = 0;
			if(l[i] * 2 <= t[i]){
				cur_time += l[i] * 2;
			}
			else {
				int x = t[i] - l[i];
				l[i] -= x;
				t[i] -= 2 * x;
				cur_time +=2 * x;
				k += (l[i] + r-1)/r;
				if(k <= mx){
					while(l[i] > r){
						ans.pb(cur_time);
						cur_time += r;
						l[i] -= r;
					}
					ans.pb(cur_time);
					ost = r - l[i];
					cur_time += l[i];
				}else{
					cur_time += l[i];
					int dd = (l[i] + r - 1)/r;
					ost = dd * 1ll * r - l[i];
				}
			}
		}
	}
	cout << k << endl;
	if(k <= mx){
		for(int i = 0; i < ans.size(); i++)
			printf("%I64d ", ans[i]);
		printf("\n");
	}
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