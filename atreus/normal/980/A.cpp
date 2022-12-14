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

int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int a = 0, b = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == 'o')
			a ++;
		else
			b ++;
	}
	if (a == 0 or b == 0 or b % a == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
		
}