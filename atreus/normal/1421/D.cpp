#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200 + 10;

int c[8];

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int x, y;
		cin >> x >> y;
		for (int i = 0; i < 6; i++)
			cin >> c[i];
		for (int i = 0; i < 36; i++)
			for (int j = 0; j < 6; j++)
				c[j] = min(c[j], c[(j+5)%6]+c[(j+1)%6]);
		ll answer = 0;
		if (x > 0 and y > 0){
			int mn = min(x,y);
			answer += +1LL*mn*c[0];
			x -= mn, y -= mn;
		}
		if (x < 0 and y < 0){
			int mn = max(x,y);
			answer += -1LL*mn*c[3];
			x -= mn, y -= mn;
		}
		if (x > 0)
			answer += +1LL*x*c[5];
		else
			answer += -1LL*x*c[2];
		if (y > 0)
			answer += +1LL*y*c[1];
		else
			answer += -1LL*y*c[4];
		cout << answer << '\n';
	}
}