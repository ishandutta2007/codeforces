#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;

const int maxn = 1'000'000 + 10;
const int mod = 1'000'000'000 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		int mnm = -1, mxm = -1;
		for (int i = 0; i < n; i++){
			int x;
			cin >> x;
			if (mnm == -1 or mnm > x)
				mnm = x;
			if (mxm == -1 or mxm < x)
				mxm = x;
		}
		if (mxm != mnm)
			cout << 1 << '\n';
		else
			cout << n << '\n';
	}
}