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

const int maxn = 1e5 + 2;
const int inf = 1e9;


pair < int, int > a[maxn];


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int n;
	long long ans = 0, sum;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i].fr, &a[i].sc);
	
	for (int tt = 0; tt < 2; tt++){
		sum = 0;
		for (int i = 0; i < n; i++)
			ans += a[i].fr * a[i].fr * 1ll * (n - 1);
		for (int i = 0; i < n; i++)
			sum += a[i].fr;
		for (int i = 0; i < n; i++)
			ans -= (sum - a[i].fr) * a[i].fr;
		
		for (int i = 0; i < n; i++)
			swap(a[i].fr, a[i].sc);
	}
	cout << ans << endl;
 
    return 0;
}