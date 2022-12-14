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
const int inf = 1e9 + 7, maxn = 1000 + 100;
ll a[maxn], dp[maxn], b[maxn];

int main(){ 
	ios_base::sync_with_stdio(false);
	memset (dp, -63, sizeof dp);
	int k;
	cin >> k;
	if (k > 36)
		return cout << -1 << endl, 0;
	string s = "111111111111111111";
	while (k > 0){
		for (int i = 0; i < s.size(); i++){
			if (s[i] == '1'){
				s[i] = '4';
				k --;
				break;
			}
			if (s[i] == '4'){
				s[i] = '8';
				k --;
				break;
			}
		}
	}
	cout << s << endl;
}