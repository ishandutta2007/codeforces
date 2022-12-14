#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define In insert
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7, maxn = 500 + 100;
int p[maxn], dp[maxn][maxn];
vector <ll> v;

int main(){
    ios_base::sync_with_stdio(false);
	memset (dp, 63, sizeof dp);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> dp[i][j];
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	for (int l = n; l >= 1; l--){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				int k = p[l];
				dp[i][j] = min (dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
		int k = p[l];
		ll sum = 0;
		for (int i = n; i >= l; i--){
			for (int j = n; j >= l; j--){
				sum += dp[p[i]][p[j]];
//				cout << p[i] << " " << p[j] << " " << dp[p[i]][p[j]] << endl;
			}
		}
		v.PB(sum);
	}
	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i] << " ";
}