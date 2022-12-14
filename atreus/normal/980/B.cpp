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
const int maxn = (int)1e5 + 100;
const int infint = (int)1e9;
const ll inf = (ll)1e18;
string s[10];

int main(){
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	cout << "YES" << endl;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < n; j++)
			s[i] += '.';
	if (k == 0){
		for (int i = 0; i < 4; i++)
			cout << s[i] << endl;
		return 0;
	}
	k --;
	s[1][n / 2] = '#';
	if (k % 2 == 1){
		s[2][n / 2] = '#';
		k --;
	}
	for (int i = 1; i <= 2; i++){
		for (int j = 1; j < (n - 1) / 2; j++){
			if (k > 0){
				s[i][j + n / 2] = '#';
				s[i][n / 2 - j] = '#';
				k -= 2;
			}
		}
	}
	for (int i = 0; i < 4; i++)
		cout << s[i] << endl;
}