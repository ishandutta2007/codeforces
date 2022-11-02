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
#include <bitset>
#include <unordered_map>

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

const int inf = 100100;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int dp[1000100];
multiset<int> M;
ll a[1000100];
int t[4*maxn];
int n;
void add(int v, int l, int r, int p, int val) {
	if(l == r) {
		t[v] += val;
	}else {
		int mid = (l + r)/2;
		if(p <= mid) add(v * 2, l, mid, p, val);
		else add(v * 2 + 1, mid+1, r, p, val);
		t[v] = min(t[v * 2], t[v * 2 + 1]);
	}
}
int get(int v, int l, int r) {
	if(l == r) return l;
	if(t[v*2] <= 0) return get(v*2, l, (l+r)/2);
	else get(v * 2 + 1, (l+r)/2 + 1, r);
}
void solve(){
	int cur = 0;
	ll l = 0;
	ll r = 0;
	for(int i = 0; i < maxn; i++) {
		if(i<=3) {
			dp[i] = 0;
		}else {
			while(r * r <= i) {
				add(1, 0, maxn, dp[r], 1);
				r++;
			}
			while(l * l * l * l < i) {
				add(1, 0, maxn, dp[l], -1);
				l++;
			}
			dp[i] = get(1, 0, maxn);
		}
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	sort(a, a + n);
	int res = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] < maxn) {
			res ^= dp[a[i]];
		}else {
			
			while(r * r <= a[i]) {
				add(1, 0, maxn, dp[r], 1);
				r++;
			}
			while(l * l * l * l < a[i]) {
				add(1, 0, maxn, dp[l], -1);
				l++;
			}
			res ^= get(1, 0, maxn);
		}
	}
	if(res) cout << "Furlo\n";
	else cout<<"Rublo\n";
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