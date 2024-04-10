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
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, k;
int a[200200];
int b[200200];
int c[200200];
int d[200200];
void solve(){
	scanf("%d%d", &n, &k);
	map<int, int> p;
	int la = -1;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if(p.count(a[i])) {
			b[i] = p[a[i]];
		}else b[i]=-1;
		p[a[i]] = i;
	}
	for(int i = 0; i < n; i++) c[i] = -1;
	for(int i = 0; i < n; i++) {
		if(b[i] >= 0) c[b[i]] = i;
	}
	for(int i = 0; i < n; i++) {
		if(c[i] >= 0) {
			d[i]++;
			d[c[i]]--;
		}
	}
	int cur = 0;
	map<int, int>M;
	int MX = 1;
	int ans = 0;
	int L = 0;
	for(int i = 0; i < n; i++) {
		cur += d[i];
		M[a[i]]++;
		MX = max(MX, M[a[i]]);
		L++;
		if(cur>0) {
		}else{
			ans += L-MX;
			MX = 0;
			L = 0;
			M.clear();
		}
	}
	cout << ans << "\n";

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