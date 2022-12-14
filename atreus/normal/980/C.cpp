#include <cstring>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)1e9 + 7;
const int maxn = (int)1e5 + 100;
const int infint = (int)1e9;
const ll inf = (ll)1e18;
int a[maxn], c[maxn], dp[maxn];

int main(){
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	memset (c, -1, sizeof c);
	c[0] = 0;
	dp[0] = 1;
	for (int i = 1; i <= n; i++){
		if (c[a[i]] != -1)
			continue;
		for (int j = a[i]; j >= 0; j--){
			if (c[j] != -1){
				if (dp[j] + a[i] - j <= k){
					for (int l = j; l <= a[i]; l++)
						c[l] = c[j];
					dp[a[i]] = dp[j] + a[i] - j;
					break;
				}
				else {
					for (int l = j + 1; l <= a[i]; l++)
						c[l] = j + 1;
					dp[a[i]] = a[i] - j;
					break;
				}
			}
			else {
				if (a[i] - j + 1 == k or j == 0){
					for (int l = j; l <= a[i]; l++){
						c[l] = j;
					}
					dp[a[i]] = a[i] - j + 1;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << c[a[i]] << " ";
}