#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int mod = (int)1e9 + 7;
const int inf = (1<<30);
int n;
void solve(){
	int x, y;
	cin >> x >> y;
	int d = x % y;
	x -= d;
	d = min(y/2, d);
	x+=d;
	cout << x << "\n";
}
int main () {
	cin >> n;
	for(int i = 0; i < n; i++) solve();




 	return 0;
}