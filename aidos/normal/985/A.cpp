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
int n;
int a[111];
int main () {

	cin >> n;
	for(int i = 0; i < n/2; i++) {
		cin >> a[i];
		a[i]--;
	}
	sort(a, a + n/2);
	int x = 0, y = 0;
	for(int i = 0; i < n/2; i++) {
		x += abs(i*2 - a[i]);
		y += abs(i * 2 + 1-a[i]);
	}
	cout << min(x,y) << "\n";

    return 0;
}