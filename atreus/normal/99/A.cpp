#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 100 + 10 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++){
		if (s[i] != '.')
			continue;
		if (s[i-1] == '9')
			return cout << "GOTO Vasilisa." << endl, 0;
		if (s[i+1] >= '5')
			s[i-1] ++;
		return cout << s.substr(0, i) << endl, 0;
	}
}