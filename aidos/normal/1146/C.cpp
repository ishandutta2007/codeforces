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

void solve(){
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 7; i >= 0; i--){
		vector<int> a, b;
		for(int j = 0; j < n; j++){
			if(j&(1<<i)) a.pb(j+1);
			else b.pb(j+1);
		}
		if(a.size() == 0 || b.size() == 0) continue;
		cout << a.size() << " " << b.size();
		for(int i = 0; i < a.size(); i++) cout << " " << a[i];
		for(int i = 0; i < b.size(); i++) cout << " " << b[i];
		cout << endl;
		int x;
		cin >> x;
		ans = max(ans, x);
	}
	cout << "-1 " << ans << endl;
}

int main () {
    int t=1;
    //scanf("%d", &t);
    cin >> t;
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}