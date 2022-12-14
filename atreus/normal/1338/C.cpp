#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;

bool p[maxn];

int nex[] = {0, 2, 3, 1};
int nex2[] = {0, 3, 1, 2};

int main(){
	ios_base::sync_with_stdio (false);
	int tc;
	cin >> tc;
	while (tc --){
		ll n;
		cin >> n;
		int type = n % 3;	
		n = (n + 2) / 3;
		int t = 0;
		while (n > (1ll << 2*t)){
			n -= (1ll << 2*t);
			t ++;
		}
		ll p = (1ll << 2*t) + n - 1;
		ll ans = 0;
		if (type == 1)
			ans = p;
		else if (type == 2){	
			int t = 0;
			while (p > 0){
				ans += (1ll << 2*t) * nex[p%4];
				p /= 4;
				t ++;
			}
		}
		else{
			int t = 0;
			while (p > 0){
				ans += (1ll << 2*t) * nex2[p%4];
				p /= 4;
				t ++;
			}
		}
		cout << ans << '\n';
		continue;
	}
}