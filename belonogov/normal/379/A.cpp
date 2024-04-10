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

const int maxn = -1;
const int inf = 1e9;


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int a, b, ans = 0, k, r;
	cin >> a >> b;
	while (a > 0){
		if (a < b){
			ans += a;
			a = 0;			
		}
		k = a % b;
		r = a / b;
		ans += a - (a % b);
		a = k + r;
	}
	cout << ans << endl;
 
    return 0;
}