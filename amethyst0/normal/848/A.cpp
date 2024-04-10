#include <bits/stdc++.h>
#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>

using namespace std;

int main() {
	int k;
	
	cin >> k;
	
	string ans;
	
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j <= k; j++) {
			k -= j;
			
			ans.push_back('a' + i);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}