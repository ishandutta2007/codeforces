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
int n, m;
int c[111][111];
int a[111];
int b[111];
int check(int x){
	int sum = c[0][0];
	a[0] = x;
	b[0] = c[0][0] - x;
	for(int i = 1; i < m; i++){
		b[i] = c[0][i] - a[0];
		sum +=b[i];
		if(b[i] < 0) return 0;
	}
	for(int i = 1; i < n; i++){
		a[i] = c[i][0] - b[0];
		sum += a[i];
		if(a[i] < 0) return 0;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i] + b[j] != c[i][j]) return 0;
		}
	}
	cout << sum << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < a[i]; j++)
			cout << "row " << i + 1 << endl;
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < b[i]; j++)
			cout << "col " << i + 1 << endl;
	}
	return 1;
}
void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cin >> c[i][j];
	}
	int l = 0, r = c[0][0];
	if(n < m) {
		l = -c[0][0];
		r = 0;
	}
	while(l <= r){
		if(check(abs(l))){
			return;
		}
		l++;
	}
	cout << -1 <<endl;
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