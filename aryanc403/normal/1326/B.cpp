// https://codeforces.com/contest/1326/submission/73748630
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#define rep(i, a, b) for(int i = a; i <= b; ++ i)
#define per(i, a, b) for(int i = a; i >= b; -- i)
#define vi vector<int>
#define pb push_back
#define maxn
#define maxm
typedef long long ll;
/* use of long long?
   reset the arrays and variables?
*/

using namespace std;

ll n, x, ma;

int main() {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
	cin >> n;
	rep(i, 1, n) {
		cin >> x;
		ll now = x + ma;
		ma = max(now, ma);
		cout << now << " ";
	}
	cout << endl;
	return 0;
}