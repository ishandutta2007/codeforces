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

char c[200200];
int a[200200];

void print(int n){
	int st = 0;
	if(a[0] == 0){
		st++;
		n--;
	}	
	for(int i = st; i < n; i++) printf("%d", a[i]);
	printf("\n");
}

void calc(int n, int len, int d){
	for(int i = 0; i < len; i++){
		int el = 9;
		if(__builtin_popcount(d) == len - i){
			while(!(d&(1<<el))) el--;
		}
		a[n - len + i] = el;
		d ^= (1<<el);
	}
}

void solve(){
	scanf("%s", c);
	int n = strlen(c);
	for(int i = 0; i < n; i++) a[i] = c[i] - '0';
	a[n-1]--;
	for(int i = n-1; i >= 0; i--){
		if(a[i] < 0) {
			a[i-1]--;
			a[i]+=10;
		}		
	}
	int M = 0;
	for(int i = 0; i < n; i++) M^=(1<<a[i]);
	if(M==0){
		print(n);
		return;
	}
	int cc = 0;
	for(int i = n-1; i >= 0; i--){
		M^=(1<<a[i]);
		for(int j = a[i]-1; j >=0; j--){
			int d = M^(1<<j);
			if(__builtin_popcount(d) <= cc){
				a[i] = j;
				calc(n, cc, d);				
				print(n);
				return;
			}
		}
		cc++;
	}
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}