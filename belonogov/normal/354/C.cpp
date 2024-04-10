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

const int maxn = 3e5 + 2;
const int maxlen = 1e6 + 2;
const int inf = 1e9;


int a[maxn];
pair < int, int > b[maxn * 2];
int c[maxlen];


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, k, mn = inf, mx = 0, sum, ans;
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		mn = min(mn, a[i]);		
		mx = max(mx, a[i]);
	}
	for (int i = 0; i < n; i++){
		b[i * 2] = mp(max(1, a[i] - k), 1);
		b[i * 2 + 1] = mp(a[i] + 1, -1);
	}
	sort(b, b + n * 2);
	if (mn <= k){
		cout << mn << endl;
		return 0;		
	}
	
	int cnt = 0;
	int cur = 0;
	for (int i = 0; i <= mx + 1; i++){
		for (; cur < n * 2 && b[cur].fr <= i; cur++)
			cnt += b[cur].sc;
		c[i] = cnt;			
	}
	assert(cnt == 0);
	ans = k;
	for (int i = k + 1; i <= mx; i++){
		sum = 0;
		for (int j = i; j <= mx; j += i)
			sum += c[j];
//		cerr << sum << endl;
		assert(sum <= n);
		if (sum == n)
			ans = i;		
	}
	cout << ans << endl;
	
	
 
    return 0;
}