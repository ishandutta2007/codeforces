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
const int INF = 1e9 + 7, maxn = 500 + 50;
int a[maxn][maxn], cnt[maxn], dp[maxn][maxn];
queue <int> q;
string s[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	memset (dp, 63, sizeof dp);
	memset (a, 63, sizeof a);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++)
			if (s[i][j] == '1')
				cnt[i] ++;
		
		for (int j = 0; j < cnt[i]; j++){
			for (int l = 0; l < s[i].size(); l++){
				if (s[i][l] == '1')
					q.push(l);
				if (s[i][l] == '1' and q.size() == cnt[i] - j){
					a[i][j] = min (a[i][j], l - q.front() + 1);
					q.pop();
				}
			}
//			cout << i << " " << j << " " << a[i][j] << endl;
			while (!q.empty())
				q.pop();
		}
		a[i][cnt[i]] = 0;
	}

	
	for (int i = 0; i <= k; i++)
		dp[0][i] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k; j++)
			for (int l = 0; l <= min (cnt[i], j); l++)
				dp[i][j] = min (dp[i][j], dp[i - 1][j - l] + a[i][l]);
	cout << dp[n][k] << endl;
}