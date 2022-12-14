#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll maxn = 1e6 + 10;
const ll mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		vector<pair<int,int>> ops;
		if (n <= 32){
			for (int i = 3; i <= n-1; i++)
				ops.push_back({i,n});
			int x = n;
			while (x != 1){
				ops.push_back({n,2});
				x = (x+1)/2;
			}
		}
		else{
			for (int i = 3; i <= n-1; i++)
				if (i != 32)
					ops.push_back({i,n});
			int x = n;
			while (x != 1){
				ops.push_back({n,32});
				x = (x+31)/32;
			}
			for (int i = 1; i <= 5; i++)
				ops.push_back({32,2});
		}
		cout << ops.size() << '\n';
		for (auto [x,y] : ops)
			cout << x << " " << y << '\n';
	}
}