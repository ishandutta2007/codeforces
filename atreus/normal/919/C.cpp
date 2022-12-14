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
const int inf = 1e9 + 7, maxn = 2e3 + 500;
string s[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	if (k == 1){
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (s[i][j] == '.')
					cnt ++;
		return cout << cnt << endl, 0;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++){
		int seats = 0;
		for (int j = 0; j < m; j++){
			if (s[i][j] == '.')
				seats ++;
			else
				seats = 0;
			if (seats >= k)
				ans ++;
		}
	}
	for (int j = 0; j < m; j++){
		int seats = 0;
		for (int i = 0; i < n; i++){
			if (s[i][j] == '.')
				seats ++;
			else
				seats = 0;
			if (seats >= k)
				ans ++;
		}
	}
	cout << ans << endl;
}