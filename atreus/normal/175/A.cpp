#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	int answer = -1;
	for (int i = 1; i <= min(8, n - 2); i++){
		for (int j = 1; j <= 8 and j + i <= n - 1; j++){
			if (n-i-j > 8)
				continue;
			if ((i > 1 and s[0] == '0') or (j > 1 and s[i] == '0') or (n-i-j > 1 and s[i+j] == '0'))
				continue;
			int a = stoi(s.substr(0, i)), b = stoi(s.substr(i, j)), c = stoi(s.substr(i+j, n-i-j));
			if (a > 1000*1000 or b > 1000*1000 or c > 1000*1000)
				continue;
			answer = max(answer, a + b + c);
		}
	}
	cout << answer << endl;
}