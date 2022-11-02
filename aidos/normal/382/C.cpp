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
const int maxn = (int)1e5+20;
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
int a[maxn];
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	if(n == 1) {
		printf("-1\n");
		return;
	}

	map<int, int> m;
	for(int i = 1; i < n; i++) {
		m[a[i] - a[i-1]]++;
	}
	if(m.size() > 2) {
		cout << 0 << "\n";
		return;
	}
	if(a[n-1] == a[0]) {
		cout << 1 << "\n";
		cout << a[0] << "\n";
		return;
	}
	if(n == 2) {
		int d = a[1] - a[0];
		if(d % 2 == 0) {
			cout << 3 << "\n";
			cout << a[0] - d << " " << a[0] + d/2 << " " << a[1] + d << "\n";
		}else{
			cout << 2 << "\n";
			cout << a[0] - d << " "  << a[1] + d << "\n";
		}
		return;
	}
	if(m.size() == 1) {
		cout << 2 <<"\n";
		int d = a[1] - a[0];
		cout << a[0] - d << " "<< a[n-1] + d << "\n";
		return;
	}
	if((--m.end()) -> s>1) {
		cout << 0 << "\n";
		return;
	}
	if(m.begin()->f * 2 == (--m.end())->f) {
		int d = m.begin()->f;
		cout << 1 << "\n";
		for(int i = 0; i < n; i++) {
			if(a[i] + d == a[i+1]) {

			}else{
				cout << a[i] + d << "\n";
				return;
			}
		}
	}else {
		cout << 0 << "\n";
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