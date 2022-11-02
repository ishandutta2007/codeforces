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
int get(int x){
	cout << x << endl;
	int res;
	cin >> res;
	if(res == 0){
		exit(0);
	}
	return res;
}
void solve(){
	cin >> m >> n;
	vector<int> res;
	vector<int> cur;
	for(int i = 0; i < n; i++){
		res.pb(get(1));
	}
	for(int i = 0; i < n; i++){
		if(res[i] > 0){
			cur.pb(1);
		}else{
			cur.pb(0);
		}
	}
	int l = 2, r = m;
	int d = 0;
	while(l <= r){
		int mid = (l + r)/2;
		int res = get(mid);
		if(!cur[d]) res = -res;
		if(res > 0){
			l = mid+1;
		}else {
			r = mid-1;
		}
		d = (d + 1) % n;
	}
	get(r);
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