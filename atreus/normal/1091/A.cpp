#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,int> pii;

const int maxn = 1e5 + 10;

int main(){
	ios_base::sync_with_stdio(false);	
	int y, b, r;
	cin >> y >> b >> r;
	int ans = 0;
	for (int i = 0; i <= 100; i++){
		if (y >= i and b >= i + 1 and r >= i + 2)
			ans = i + i + i + 3;
	}
	cout << ans << endl;
}