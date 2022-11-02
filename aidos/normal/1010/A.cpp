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
int a[1111];
int b[100100];
bool can(double x){
	for(int i = 0; i < n; i++){
		int j = (i+1) % n;
		double c = (x+m)/a[i];
		if(c > x) return false;
		x -= c;
		c = (x+m)/b[j];
		if(c > x) return false;
		x -= c;
	}
	return true;
}
void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int j = 0; j < n; j++){
		cin >> b[j];
	}
	double l = 0;
	double r = 1e9+10.0;
	int ok = 0;
	for(int i = 0; i < 100; i++){
		double mid = (l + r)/2;
		if(can(mid)){
			r = mid;
			ok = 1;
		}else l = mid;
	}
	if(ok)
		printf("%.12lf\n", r);
	else printf("-1\n");
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