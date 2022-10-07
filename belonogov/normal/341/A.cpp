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


long long gcd(long long a, long long b){
	return (b == 0)? a: gcd(b, a % b);
}

int a[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n;
	long long sum = 0, ans = 0, d;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		ans += a[i];
	for (int i = 0; i < n; i++){
		ans += sum;
		sum += 2 * (a[i + 1] - a[i]) * 1ll * (i + 1);
	}

		
	d = gcd(ans, n);
	cout << ans / d << " " << n / d << endl;
	

	
    return 0;
}