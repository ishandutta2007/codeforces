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
const int maxn = (int)5e3 + 100;
const int infint = (int)1e9;
const ll inf = (ll)1e18;
ll a[maxn], b[maxn], dp[maxn];
bool mark[maxn];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	memset (dp, -1, sizeof dp);
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (a[i] == 0){
			dp[i] = -1;
			continue;
		}
		for (int j = i - 1; j >= 1; j--){
			if (a[j] == 0)
				continue;
			ll p = a[i] * a[j];
			if (p < 0)
				continue;
			ll q = sqrt (p);
			if (q * q == p){
				dp[i] = dp[j];
				break;
			}
		}
		if (dp[i] == -1){
			dp[i] = cnt;
			cnt ++;
		}
	}
	for (int i = 1; i <= n; i++){
		int cnt = 0;
		bool tmp = 0;
		memset (mark, 0, sizeof mark);
		for (int j = i; j <= n; j++){
			if (dp[j] != -1 and !mark[dp[j]]){
				mark[dp[j]] = 1;
				cnt ++;
			}
			else 
				tmp = 1;
			b[max (cnt, 1)] ++;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << b[i] << " ";
}