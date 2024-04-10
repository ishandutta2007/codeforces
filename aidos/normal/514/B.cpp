#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define forit(it, v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++)

typedef pair <int, int > pii;
typedef vector <int> vi;
typedef long long ll;
vector < pii > v;
int used[1010];

int main(){
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
	int n, x, y;
	cin >> n >> x >> y;


	for(int i = 0, a, b;  i < n; i++){
		cin >> a >> b;
		a-=x;
		b-=y;
		v.pb(mp(a, b));
	}
	sort(v.begin(), v.end());
	int ans= 0;
	for(int i = 0; i < n; i++){
		if(used[i]) continue;
		ans++;
		x = v[i].f;
		y = v[i].s;
		for(int j = 0; j < n; j++){
			if(v[j].f * y - v[j].s * x == 0) used[j] = 1;
		}
	}
	cout << ans << endl;



	#ifdef LOCAL
	cerr << 1.0 * clock()/CLOCKS_PER_SEC << endl;
	#endif
	return 0;
}