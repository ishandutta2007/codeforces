#include <iostream>
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
const int inf = 1e9 + 7, maxn = 1e5 + 500;
pair <ll, ll> dp[maxn];
string s[maxn];

bool tmp(pair <ll, ll> a, pair <ll, ll> b){
	if (a.F * b.S > a.S * b.F)
		return true;
	return false;

}

int main(){ // 0 --> red , 1 --> blue
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll ans = 0, cnt = 0;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		cnt = 0;
		for (int j = 0; j < s[i].size(); j++){
			if (s[i][j] == 's'){
				dp[i].F ++;
				cnt ++;
			}
			else{ 
				dp[i].S ++;
				ans += cnt;
			}
		}
	}
	sort (dp, dp + n, tmp);
	cnt = 0;
	for (int i = 0; i < n; i++){
		ans += cnt * dp[i].S;
		cnt += dp[i].F;
	}
	cout << ans << endl;
}