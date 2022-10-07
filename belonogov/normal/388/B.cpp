#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 1000 + 10;
const int inf = 1e9;

vector < pair < int, int > > ans;
int a[maxn][maxn];
int b[maxn];

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
	int k, cur = 2, n = 20;
	scanf("%d", &k);
	ans.pb(mp(0, cur)); cur++;
	for (int i = 0; i < n; i++){
		b[i] = cur - 1;
		ans.pb(mp(cur - 1, cur));
		ans.pb(mp(cur - 1, cur + 1));
		ans.pb(mp(cur - 1, cur + 2));

		ans.pb(mp(cur, cur + 3));
		ans.pb(mp(cur + 1, cur + 3));
		ans.pb(mp(cur + 2, cur + 3));
		cur += 4;		
	}
	
	
	for (int i = 0; k; i++, k /= 3){
		if (k % 3 == 0)
			continue;
		ans.pb(mp(b[i], cur++));
		if (k % 3 == 1){
			ans.pb(mp(cur - 1, cur));
			ans.pb(mp(cur, cur + 1));
			cur += 2;
		}
		if (k % 3 == 2){
			ans.pb(mp(cur - 1, cur));
			ans.pb(mp(cur - 1, cur + 1));
			ans.pb(mp(cur, cur + 2));
			ans.pb(mp(cur + 1, cur + 2));
			cur += 3;
		}
// 		int cnt = n * 2 - 2 - 1 - i * 2;
		int cnt = n * 2 + 2 - 2 - 1 - i * 2;
// 		cerr << "cnt: " << cnt << endl;
		assert(cnt >= 0);
		for (int j = 0; j < cnt; j++){
			ans.pb(mp(cur - 1, cur));
			cur++;			
		}
		ans.pb(mp(cur - 1, 1));
	}
	
	
	for (int i = 0; i < (int)ans.size(); i++){
		a[ans[i].fr][ans[i].sc] = 1;
		a[ans[i].sc][ans[i].fr] = 1;		
	}
// 	cerr << cur << " " << ans.size() << endl;
// 	for (int i = 0; i < (int)ans.size(); i++)
// 		cerr << ans[i].fr << " " << ans[i].sc << endl;
// 	
	cout << cur << endl;
	for (int i = 0; i < cur; i++, cout << "\n")
		for (int j = 0; j < cur; j++)
			printf("%c", (a[i][j])? 'Y': 'N');
		
			
 
    return 0;
}