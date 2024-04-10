#include <unordered_map>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#define MP make_pair
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 2e5 + 100;
map <int, int> dp, tmp;
int a[maxn], par[maxn], c[maxn];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = n; i >= 1; i--){
		if (dp[a[i]] <= dp[a[i] + 1] + 1){
			par[i] = tmp[a[i] + 1];
			tmp[a[i]] = i;
		}
		dp[a[i]] = max (dp[a[i]], dp[a[i] + 1] + 1);
		c[i] = dp[a[i]];
	}
	int idx = 0;
	for (int i = 1; i <= n; i++){
		if (c[i] > c[idx])
			idx = i;
	}
	cout << c[idx] << endl;
	while (idx != 0){
		cout << idx << " ";
		idx = par[idx];
	}
}