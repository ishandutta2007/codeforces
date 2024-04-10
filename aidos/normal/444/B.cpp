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

const int inf = (1ll << 25) - 1;
const int maxn = (int)2e5+100;
const int mod = (int) 1e9 + 7;
using namespace std;
ll x;
int n;
int d;
int a[maxn];
int b[maxn];
int getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
	int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}
const int C = 30;
ll A[maxn/C];
ll B[maxn/C];
int ans[maxn];
int pos[maxn];
void upd(int j, int T, ll val) {
	for(int z = 0; z < C; z++) {
		if(val & (1ll<<z)) {
			A[(z+j)/C] ^=1ll<<((z+j) % C);
			ans[z+j] = T;
		}

	}
}
void solve(){
	cin >> n >> d >> x;
	initAB();
	for(int i = 0; i < n; i++) {
		pos[a[i]] = i;
		int z = i % C;
		A[i/C] |= 1ll<<z;
	}
	for(int i = 0; i < n; i++) {
		if(b[i]) {
			int z = i % C;
			B[i/C] |= 1ll<<z;
		}
	}
	for(int i = n; i >= 1; i--) {
		int j = pos[i];
		int t = j % C;
		int o = 0;
		ll sec = (1ll<<t)-1;
		ll fir = ((1ll<<C)-1)^sec;
		while(j < n + C) {
			ll h = (A[j/C] | (A[j/C + 1] << C)) >> t;
			h &= B[o];
			if(h) {
				upd(j, i, h);
			}
			j += C;
			o++;
		}
	}
	for(int i = 0; i < n; i++) {
		cout << ans[i] << "\n";
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