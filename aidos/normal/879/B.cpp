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
int n, m;
int a[200200];
ll k;
void solve(){
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if(k >= n) {
		cout << n << "\n";
	}else {
		int t = 0;
		int i = 0;
		while(t < k) {
			if(a[i] > a[i+1]) {
				swap(a[i], a[i+1]);
				t++;
			}else {
				t = 1;
			}
			a[i+n] = a[i];
			i++;
		}
		cout << a[i] << "\n";
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