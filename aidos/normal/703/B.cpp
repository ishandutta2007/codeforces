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

int n, k;
int a[100100];
int b[100100];
void solve(){
	scanf("%d%d", &n, &k);
	ll cur1= 0, cur2=0, ans = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i =0, x; i<k; i++){
		scanf("%d", &x);
		b[x-1] = 1;
	}
	for(int i = 0; i < n; i++){
		if(b[i] == 0){
			int j = (i - 1 + n) % n;
			if(!b[j]) ans += a[i] * 1ll * a[j];
			ans += a[i] * 1ll * cur2;
			cur1 += a[i];
		}else {
			ans += (cur1 + cur2) * 1ll * a[i];
			cur2 += a[i];
		}
	}
	cout << ans << endl;
}

int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Test case #%d\n", i);
      solve();
    }

    return 0;
}