#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define SZ(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	int res = 0;
	while(a >= 1 && b >= 2 && c >= 4) {
		res += 7; a -= 1; b -= 2; c -= 4;
	}
	cout << res;
}