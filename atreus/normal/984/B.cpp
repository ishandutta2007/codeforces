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
typedef long double ld;
const int mod = (int)1e9 + 7;
const int maxn = 1111;
const int MAXN = 1e5 + 100;
const int inf = (int)1e9;
int a[maxn][maxn];
string s[maxn];

int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		string ba;
		cin >> ba;
		s[i] = '+' + ba;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (s[i][j] == '*'){
				for (int p = -1; p <= 1; p++){
					for (int q = -1; q <= 1; q++){
						a[i + p][j + q] ++;
					}
				}
			}
		}
	}
	bool cur = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (s[i][j] == '*')
				continue;
			if (s[i][j] == '.' and a[i][j] == 0)
				continue;
			if (s[i][j] == '.'){
				cur = 0;
				break;
			}
			if ((int)(s[i][j] - '0') != a[i][j])
				cur = 0;
		}
	}
	if (cur)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}