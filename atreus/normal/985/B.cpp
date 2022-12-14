#include <cstring>
#include <algorithm>
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
const int maxn = 2000 + 100;
const int  mod = 1e9 + 7;
const ll inf = (1ll << 62);
string s[maxn];
bool mark[maxn];

int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int j = 0; j < m; j++){
		int cnt = 0, idx;
		for (int i = 0; i < n; i++){
			if (s[i][j] == '1'){
				cnt ++;
				idx = i;
			}
		}
		if (cnt == 1)
			mark[idx] = 1;
	}

	for (int i = 0; i < n; i++)
		if (!mark[i])
			return cout << "YES" << endl, 0;
	cout << "NO" << endl;
}