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

const int maxn = 1e6 + 2;
const int inf = 1e9;


vector < pair < int, int > > b;
int a[maxn];

bool cmp (pair < int, int > a, pair < int, int > b){
	return a.fr < b.fr || (a.fr == b.fr && a.sc > b.sc);	
}

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
	int n, t, cnt, ans;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &t);
	for (int i = 0; i < n; i++){
		b.pb(mp(a[i], 1));
		b.pb(mp(a[i] + t, -1));	
	}
	sort(b.begin(), b.end(), cmp);
	
	cnt = 0;
	ans = 0;
	for (int i = 0; i < (int)b.size(); i++){
		cnt += b[i].sc;
		ans = max(ans, cnt);		
	}
// 	for (int i = 0; i < (int)b.size(); i++)
// 		cerr << b[i].fr << " " << b[i].sc << endl;
	cout << ans << endl;
 
    return 0;
}