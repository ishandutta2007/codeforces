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
int a[200200];

void solve(){
	scanf("%d", &n);
	vector<int> x, y;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		int d = sqrt(a[i]);
		if(d * d == a[i]){
			x.pb(i);
		}
		else {
			y.pb(i);
		}
	}
	ll sum = 0;
	if(x.size() < y.size()){
		vector<int> S;
		for(int i = 0; i < y.size(); i++){
			int j = y[i];
			int z = sqrt(a[j]);
			S.pb(min(a[j] - z * z, (z+1) * (z+1) - a[j]));
		}
		sort(S.begin(), S.end());
		int ne = (y.size() - x.size())/2;
		for(int i = 0; i < ne; i++){
			sum += S[i];
		}
	}else{
		vector<int> S;
		for(int i = 0; i < x.size(); i++){
			int j = x[i];
			if(a[j] == 0){
				S.pb(2);
			}
			else {
				S.pb(1);
			}
		}
		sort(S.begin(), S.end());
		int ne = (x.size() - y.size())/2;
		for(int i = 0; i < ne; i++){
			sum += S[i];
		}
	}
	cout << sum << endl;
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