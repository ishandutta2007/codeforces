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
const int inf = 1e9 + 7, maxn = 3e5 + 500;
ll mark[maxn], dp[maxn], par[maxn], n;
vector <pair <pair <int, int>, int> > v[maxn];
vector <int> ans;

int main(){ // 0 --> red , 1 --> blue
	ios_base::sync_with_stdio(false);
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			int k = (i ^ j);
			if (k >= j and k <= n and i + j > k){
				cnt ++;
			}
		}
	}
	cout << cnt << endl;
}