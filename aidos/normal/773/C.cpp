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
ll a[200100];
ll bb[165];
int used[200100];
int cnt[200100];
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%I64d", &a[i]);
	}
	bb[0] = 1;
	for(int i = 1; i < 55; i++){
		bb[i] = bb[i-1] * 2;
	}
	int it = 0;
	vector<ll> b;
	map<ll, int> good;
	for(int i = 0; i < n; ){
		while(i < n && bb[it] > a[i]) {
			b.pb(a[i]);
			i++;
		}
		while(i < n && bb[it] == a[i]) {
			cnt[it]++;
			i++;
		}
		it++;
	}
	int C = 0;
	int T = 0;
	int ind = (int)b.size();
	--ind;
	int A = 0;
	for(int i = 53; i >= 0; i--){
		while(cnt[i] > 0){
			int j = i;
			while(j >= 0 && cnt[j] > 0 ) j--;
			if(j >= 0) break;
			for(int k = 0; k <= i; k++){
				cnt[k]--;
				C++;
			}
			T++;
			A++;
			if(ind >= 0 &&T>0&& b[ind] <= (1ll<<i) * 2) {
				ind--;
				T--;
				C++;
			}
			if(ind == -1 && n - C <= T){
				used[A] = 1;
			}
		}

		while(ind + 1< b.size() && cnt[i] > 0){
			if(b[ind+1] > (1ll<<i)) break;
			ind++;
			cnt[i]--;
		}
		while(T > 0 && cnt[i] > 0){
			T--;
			cnt[i]--;
			C++;
		}
		while(T > 0 && ind >= 0){
			if(b[ind] >= (1ll<<i) && b[ind] <= (1ll<<i) * 2) ind--;
			else break;
			T--;
			C++;
		}
		if(n - C <= T && ind == -1) used[A] = 1;
		if(cnt[i] > 0){
			printf("-1\n");
			return;
		}
	}

	vector<int> ans;
	for(int i = 1; i<=100010; i++)
		if(used[i]) ans.pb(i);
	if(ans.size() == 0) printf("-1\n");
	else{
		for(int i = 0; i < ans.size(); i++){
			if(i > 0) printf(" ");
			printf("%d", ans[i]);
		}
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