#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
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
const int maxn = 1e5 + 50;
const int mod = 1e9 + 7;
const int M = 1e5 + 10;
pair <pair <int, int>, int> p[maxn];
int A[maxn], par[maxn], c[maxn][50], a[maxn];
string s[maxn];

string f (int x){
	string k;
	while (x > 0){
		k += (x % 2) + '0';
		x /= 2;
	}
	while (k.size() < 30)
		k += '0';
	return k;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		cin >> p[i].F.F >> p[i].F.S >> p[i].S;
		s[i] = f (p[i].S);
	}
	for (int k = 0; k < 30; k++){
		memset (A, 0, sizeof A);
		for (int i = 1; i <= m; i++){
			if (s[i][k] == '1'){
				A[p[i].F.F] ++;
				A[p[i].F.S + 1] --;
			}
		}
		int tmp = 0;
		for (int i = 1; i <= n; i++){
			tmp += A[i];
			c[i][k] = (tmp > 0);
			par[i] = par[i - 1] + c[i][k];
		}
		for (int i = 1; i <= m; i++){
			if (s[i][k] == '0'){
				if (par[p[i].F.S] - par[p[i].F.F - 1] == p[i].F.S - p[i].F.F + 1)
					return cout << "NO" << endl, 0;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		ll tmp = 1;
		for (int j = 0; j < 30; j++){
			a[i] += c[i][j] * tmp;
			tmp *= 2;
		}
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}