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
multiset<int> S;
int a[200200];
int b[200200];
int c[200200];
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++) scanf("%d", &b[i]);
	for(int i = 0; i < n; i++) {
		S.insert(b[i]);
	}
	for(int i = 0; i < n; i++){
		int x = n - a[i];
		multiset<int>::iterator it = S.lower_bound(x);
		if(it != S.end()) {
			c[i] = *it;
			S.erase(it);
		}
		else {
			c[i] = *S.begin();
			S.erase(S.begin());
		}
		printf("%d ", (a[i] + c[i]) % n);
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