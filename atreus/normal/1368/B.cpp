#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 3000 + 10;
const int mod = 998244353;

int main(){
	ios_base::sync_with_stdio(false);
	ll k;
	cin >> k;
	string s = "codeforces";
	for (int i = 1; i <= 50; i++){
		ll cnt = 1;
		for (int j = 1; j <= 9; j++)
			cnt = cnt * (i + 1);
		cnt *= i;
		if (cnt >= k){
			cnt = 1;
			for (int j = 1; j <= 10; j++)
				cnt *= i;
			int x = 0;
			for (int j = 1; j <= 9 and cnt < k; j++, x++)
				cnt = (cnt / i) * (i + 1);
			for (int j = 0; j < x; j++)
				for (int z = 0; z < i + 1; z ++)
					cout << s[j];
			for (int j = x; j < 10; j++)
				for (int z = 0; z < i; z++)
					cout << s[j];
			cout << endl;
			return 0;
		}
	}
}