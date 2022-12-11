#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;    
const int N = int(3e5), mod = 10007;

int n,a[N];
ll ans;


int main () {
	scanf("%d",&n);
	for(int i= 1;  i <= n; i++) scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	for(int i = 1; i <= n; i++){
		int j = n - i + 1;
		ans = (ans + 1ll * a[i] * a[j]) % mod;
	}
	cout << ans;

return 0;
}