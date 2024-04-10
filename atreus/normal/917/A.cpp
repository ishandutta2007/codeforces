#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
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
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7, maxn = 5e3 + 500;
int dp[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int ans = 0, n = s.size();
	for (int i = 0; i < n; i++){
		int l = 0, r = 0;
		for (int j = i; j < n; j++){
			if (s[j] == '('){
				l ++;
				r ++;
			}
			if (s[j] == ')'){
				l --;
				if (l < 0)
					l += 2;
				r --;
			}
			if (s[j] == '?'){
				l --;
				if (l < 0)
					l += 2;
				r ++;
			}
			if (r < 0)
				break;
			if (l == 0 and i != j)
				ans ++;
		}
	}
	cout << ans << endl;
}